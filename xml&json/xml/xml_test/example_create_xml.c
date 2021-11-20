#include <stdio.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Create xml file\n");
        printf("Usage: %s file_name\n", argv[0]);
        exit(1);
    }

    //定义文档和节点指针
    xmlDocPtr doc = xmlNewDoc(BAD_CAST"1.0");

    xmlNodePtr root_node = xmlNewNode(NULL,BAD_CAST"company");

    //设置根节点
    xmlDocSetRootElement(doc,root_node);

    //在根节点中直接创建节点
    //xmlNewTextChild(root_node, NULL, BAD_CAST "year", BAD_CAST "2021");

    //xmlNewTextChild(root_node, NULL, BAD_CAST "month", BAD_CAST "11");

    //xmlNewTextChild(root_node, NULL, BAD_CAST "day", BAD_CAST "19");

    //创建一个节点，设置其内容和属性，然后加入根结点
    //xmlNodePtr node = xmlNewNode(NULL,BAD_CAST"node2");

    //xmlNodePtr content = xmlNewText(BAD_CAST"NODE CONTENT");

    //xmlAddChild(root_node,node);

    //xmlAddChild(node,content);

    //xmlNewProp(node,BAD_CAST"attribute",BAD_CAST "yes");

    //创建一个儿子和孙子节点
    xmlNodePtr fisrtnode = xmlNewNode(NULL, BAD_CAST "domain");

    xmlAddChild(root_node,fisrtnode);

    xmlNodePtr title = xmlNewNode(NULL, BAD_CAST "title");

    xmlAddChild(fisrtnode,title);

    xmlAddChild(title, xmlNewText(BAD_CAST "log config"));

    xmlNodePtr author = xmlNewNode(NULL, BAD_CAST "author");

    xmlAddChild(fisrtnode,author);

    xmlAddChild(author, xmlNewText(BAD_CAST "Smalz"));

    xmlNodePtr datewritten = xmlNewNode(NULL, BAD_CAST "datewritten");

    xmlAddChild(fisrtnode,datewritten);

    xmlAddChild(datewritten, xmlNewText(BAD_CAST "2021-11-19"));


    //创建一个儿子和孙子节点
    xmlNodePtr secondnode = xmlNewNode(NULL, BAD_CAST "body");

    xmlAddChild(root_node,secondnode);

    xmlNodePtr headline = xmlNewNode(NULL, BAD_CAST "headline");

    xmlAddChild(secondnode,headline);

    xmlAddChild(headline, xmlNewText(BAD_CAST "This is the headline"));

    xmlNodePtr para = xmlNewNode(NULL, BAD_CAST "para");

    xmlAddChild(secondnode,para);

    xmlAddChild(para, xmlNewText(BAD_CAST "This is the body text"));




    //存储xml文档
    int ret = xmlSaveFormatFileEnc(argv[1], doc, "UTF-8", 1);
    if (ret != -1)
    {
       printf("create xml file, write %d bytes\n", ret);
    }

    //释放文档内节点动态申请的内存
    xmlFreeDoc(doc);

    return 0;
}
