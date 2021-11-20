#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#ifndef BOOL
typedef     unsigned char           BOOL;              
#endif

#ifndef CHAR
typedef      char                   CHAR;       
#endif

#ifndef BYTE
typedef     unsigned char           BYTE;         
#endif

#ifndef BOOLEAN
typedef     unsigned char           BOOLEAN; 
#endif

#ifndef UCHAR
typedef     unsigned char           UCHAR;         
#endif

#ifndef INT8
typedef     signed char             INT8;       
#endif

#ifndef UINT8
typedef     unsigned char           UINT8;        
#endif

#ifndef INT16
typedef     short                   INT16;
#endif

#ifndef UINT16
typedef     unsigned short          UINT16;        
#endif

#ifndef DWORD
typedef     unsigned int            DWORD;       
#endif

#ifndef INT32
typedef     int                     INT32; 
#endif

#ifndef UINT32
typedef     unsigned int            UINT32;    
#endif

#ifndef UINT64
typedef     long long               UINT64;    
#endif


#ifndef FLOAT
typedef     float                   FLOAT;        
#endif

#ifndef DOUBLE
typedef     double                  DOUBLE; 
#endif

#ifndef FALSE
#define     FALSE                   0
#endif

#ifndef TRUE
#define     TRUE                    1
#endif

#ifndef NULL
#define     NULL                    ((void *)0)
#endif

#ifndef VOID
  typedef void				    VOID;
#endif
/******************************************************************************
*  function name | CodeBytes2String
*  content       | 字节数据转换为可打印字符串 
                   如：{0xC8, 0x32, 0x9B, 0xFD, 0x0E, 0x01} --> "C8329BFD0E01"
*  parameter     | pcSrc
                   pucDst
                   i32SrcLength
*  return        | 返回目标字符串长度。
*                  -1--失败
*  notice        | 无
******************************************************************************/
INT32 CodeBytes2String(const UCHAR * pucSrc, CHAR * pcDst, INT32 i32SrcLength)
{
    const CHAR  tab[]   = "0123456789ABCDEF";   // 0x0-0xf的字符查找表
    INT32 i;
    //校验参数
    if (pucSrc == NULL || pcDst == NULL || i32SrcLength < 0)
    {
        return -1;
    }

    for (i = 0; i < i32SrcLength; i++)
    {
        *pcDst++ = tab[*pucSrc >> 4];      // 输出高4位
        *pcDst++ = tab[*pucSrc & 0x0f];    // 输出低4位
        pucSrc++;
    }
    // 输出字符串加个结束符
    *pcDst = '\0';
    // 返回目标字符串长度
    return i32SrcLength * 2;
}

/******************************************************************************
*  function name | CodeString2Bytes
*  content       | 可打印字符串转换为字节数据 
                   如："C8329BFD0E01" --> {0xC8, 0x32,0x9B, 0xFD, 0x0E, 0x01}
*  parameter     | pcSrc
                   pucDst
                   i32SrcLength
*  return        | 返回目标字符串长度。
*                  -1--失败
*  notice        | 无
******************************************************************************/
INT32 CodeString2Bytes(const CHAR *pcSrc, UCHAR *pucDst, INT32 i32SrcLength)
{
    UCHAR *pDest = (UCHAR *)pucDst;
    INT32 i;

    if (pcSrc == NULL || pucDst == NULL || i32SrcLength < 0)
	{
		return -1;
	}
	
	for (i = 0; i < i32SrcLength; i += 2)
	{
		// 输出高4位
		if (*pcSrc >= '0' && *pcSrc <= '9')
        {
            *pDest = (UCHAR) ((UCHAR) (*pcSrc - '0') << 4) ;
        }
        else if(*pcSrc >= 'a' && *pcSrc <= 'z')
        {
            *pDest = (UCHAR) ((UCHAR) ((*pcSrc - 'a') + 10) << 4);
        }
        else
        {
            *pDest = (UCHAR) ((UCHAR) ((*pcSrc - 'A') + 10) << 4);
        }

		pcSrc++;

		// 输出低4位
		if (*pcSrc >= '0' && *pcSrc <= '9')
		{
			*pDest |= *pcSrc - '0';
		}
        else if (*pcSrc >= 'a' && *pcSrc <= 'z')
        {
            *pDest |= (*pcSrc - 'a') + 10;
        }
		else
		{
			*pDest |= (*pcSrc - 'A') + 10;
		}

		pcSrc++;
		pDest++;
	}

	// 返回目标数据长度
	return (i32SrcLength / 2);
}


void main()
{
	printf("hello wolrd\n");
	UCHAR byteData[]={0x01,0x12,0x13,0x1e,0x2d,0x14,0x4f,0x5b};

	CHAR *stringData = (char *)malloc(10);
	int dataLenth =  CodeBytes2String(byteData,stringData,sizeof(byteData));
	printf("[test]: string = %s,dataLenth = %d\n",stringData,dataLenth);

	char *stringTest = (char *)malloc(20);
	unsigned char codeData[10] = {0};
	stringTest = "C8329BFD0E01";
	int codeSize = CodeString2Bytes(stringTest,codeData,strlen(stringTest));
	printf("codeSize = %d\n",codeSize);
	for(int i=0;i<sizeof(codeData);i++)
	{
		printf("codeData[%d] = %x \n",i,codeData[i]);
	}

}




