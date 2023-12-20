#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  状态码
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

//  链表初始化
int LinkListInit(LinkList **pList)
{
    int ret = 0;
    LinkList *list = (LinkList *)malloc(sizeof(LinkList) * 1);
    if(!list)
    {
        return MALLOC_ERROR;
    }
    //  清空脏数据
    memset(list, 0, sizeof(LinkList) * 1);

    list->head = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if(!list->head)
    {
        return MALLOC_ERROR;
    }
    //  清空脏数据
    memset(list->head, 0, sizeof(LinkNode) * 1);
    list->head->data = 0;
    list->head->next = NULL;

    //  链表的长度为0
    list->len = 0;

    //  二级指针
    *pList = list;

    return ret;
}

//  链表头插
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val)
{

}

//  链表尾插
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val)
{

}

//  链表指定位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val)
{

}

//  链表头删
int LinkListHeadDelete(LinkList *pList, int pos)
{

}

//  链表尾删
int LinkListTailDelete(LinkList *pList)
{

}

//  链表指定位置删
int LinkListDeleteAppointPos(LinkList *pList, int pos)
{

}

//  链表删除指定元素
int LinkListDeleteAppointData(LinkList *pList, ELEMENTTYPE val)
{

}

//  获取链表的长度
int LinkListGetLength(LinkList *pList, int *pSize)
{

}

//  链表的销毁
int LinkListDestroy(LinkList *pList)
{

}

//  链表遍历接口
int LinkListForeach(LinkList *pList)
{

}