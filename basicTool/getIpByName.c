#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>


void main()
{
	printf("hello world\n");
	char **ptr;
	struct hostent *hst;
	char str[16];
	hst = gethostbyname("www.baidu.com");
	if(NULL != hst)
	{
		printf("offical name:%s\r\n",hst->h_name==NULL?"NULL":hst->h_name);

		for(ptr = hst->h_aliases;*ptr != NULL;ptr++)
		{
            printf(" alias:%s\r\n",*ptr);
		}
		switch(hst->h_addrtype) 
		{
			case AF_INET:
			case AF_INET6:
			ptr=hst->h_addr_list;

			for(;*ptr!=NULL;ptr++)
			{
				char *p = inet_ntop(hst->h_addrtype, *ptr, str, sizeof(str));
			    if(NULL != p)
					printf(" address:%s\r\n", p);
			}
			break;
			default:
			printf("unknown address type/n");
			break;
		}
	}else
	{
		printf("hello error \n");
	}
}
