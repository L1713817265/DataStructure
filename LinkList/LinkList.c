#include "LinkList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//  状态码
enum STATUS_CODE
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

//  静态函数只在本源文件(.c)内使用
//  静态函数前置声明
static int LinkListAccordAppointValGetPos(LinkList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE));
//  指针判空
static int PointerJudge(LinkList *ptr);

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
    
    //  初始化的时候, 尾指针 = 头指针
    list->tail = list->head;

    //  链表的长度为0
    list->len = 0;

    //  二级指针
    *pList = list;

    return ret;
}

//  链表头插
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, 0, val);
}

//  链表尾插
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val)
{
    return LinkListAppointPosInsert(pList, pList->len, val);
}

//  链表指定位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val)
{
    int ret = 0;

    //  指针判空
    PointerJudge(pList);

    if(pos < 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }

    //  封装结点
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode) * 1);
    if(!newNode)
    {
        return MALLOC_ERROR;
    }
    //  清除脏数据
    memset(newNode, 0, sizeof(LinkNode) * 1);
#if 1
    newNode->data = 0;
    newNode->next = NULL;
#endif
    //  赋值
    newNode->data = val;

#if 1
    //  从虚拟头结点开始遍历
    LinkNode *travelNode = pList->head;
#else
    LinkNode *travelNode = pList->head->next;
#endif

    int flag = 0;
    //  这种情况下需要更改尾指针
    if(pos == pList->len)
    {
        //  修改结点指向
        travelNode = pList->tail;
        flag = 1;
    }
    else
    {
        while(pos--)
        {
            travelNode = travelNode->next;
        }
    }
    newNode->next = travelNode->next;
    travelNode->next = newNode;
    if(flag)
    {
        //  尾指针更新位置
        pList->tail = newNode;

    }

    //  更新链表的长度
    (pList->len)++;

    return ret;
}

//  链表头删
int LinkListHeadDelete(LinkList *pList)
{
    return LinkListDeleteAppointPos(pList, 1);
}

//  链表尾删
int LinkListTailDelete(LinkList *pList)
{
    return LinkListDeleteAppointPos(pList, pList->len);
}

//  链表指定位置删
int LinkListDeleteAppointPos(LinkList *pList, int pos)
{
    int ret = 0;

    //  指针判空
    PointerJudge(pList);

    if(pos <= 0 || pos > pList->len)
    {
        return INVALID_ACCESS;
    }
#if 1
    LinkNode *travelNode = pList->head;
#else
    LinkNode *travelNode = pList->head->next;
#endif

    int flag = 0;
    //  需要修改尾指针
    if(pos == pList->len)
    {
        //  需要修改尾指针
        flag = 1;
    }
    LinkNode *needDelNode = NULL;
    while(--pos)
    {
        //  向后移动位置
        travelNode = travelNode->next;
    }
    //  跳出循环找到的是哪一个结点?
    needDelNode = travelNode->next;
    travelNode->next = needDelNode->next;

    if (flag)
    {
        //  调整尾指针
        pList->tail = travelNode;
    }

    //  释放内存
    if(needDelNode)
    {
        free(needDelNode);
        needDelNode = NULL;
    }

    //  链表的长度减一
    (pList->len)--;

    return ret;
}

//  根据指定的元素得到在链表中所在的位置
static int LinkListAccordAppointValGetPos(LinkList *pList, ELEMENTTYPE val, int *pPos, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    //  静态函数只给本源文件的函数使用, 不需要判断合法性
#if 1
    int pos = 0;
    LinkNode *travelNode = pList->head;
#else
    int pos = 1;
    LinkNode *travelNode = pList->head->next;
#endif

    int cmp = 0;
    while(travelNode)
    {
        #if 0
        if(travelNode->data == val)
        {
            //  解引用
            *pPos = pos;
            return pos;
        }
        #else
        cmp = compareFunc(val, travelNode->data);
        if(cmp == 1)
        {
            //  解引用
            *pPos = pos;
            return pos;
        }
        #endif
        travelNode = travelNode->next;
        pos++;
    }
    //  解引用
    *pPos = NOT_FIND;

    return NOT_FIND;
}

//  链表删除指定元素
int LinkListDeleteAppointData(LinkList *pList, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE, ELEMENTTYPE))
{
    int ret = 0;

    int pos = 1;
    int size = 0;
    while(LinkListGetLength(pList, &size) && pos != NOT_FIND)
    {
        //  根据指定的元素得到在链表中所在的位置
        LinkListAccordAppointValGetPos(pList, val, &pos, compareFunc);
        LinkListDeleteAppointPos(pList, pos);
    }
    
    return ret;
}

//  获取链表的长度
int LinkListGetLength(LinkList *pList, int *pSize)
{
    int ret = 0;

    //  指针判空
    PointerJudge(pList);

    if(pSize)
    {
        *pSize = pList->len;
    }

    //  返回链表的长度
    return pList->len;
}

//  链表的销毁
int LinkListDestroy(LinkList *pList)
{
    int size = 0;
    //  我们使用头删删除结点释放链表
    while(LinkListGetLength(pList, &size))
    {
        LinkListHeadDelete(pList);
    }

    if(pList->head)
    {
        free(pList->head);
        //  指针置为NULL
        pList->head = NULL;
        pList->tail = NULL;
    }
}

//  链表遍历接口
int LinkListForeach(LinkList *pList, int (*printFunc)(ELEMENTTYPE))
{
    int ret = 0;

    //  指针判空
    PointerJudge(pList);

#if 0
    //  travelNode指向虚拟头结点
    LinkNode *travelNode = pList->head;
    while(travelNode->next != NULL)
    {
        travelNode = travelNode->next;
        printf("travelNode->data: %d",travelNode->data);
    }
#else
    //  travelNode指向链表的第一个元素
    LinkNode *travelNode = pList->head->next;
    while(travelNode != NULL)
    {
#if 0
        printf("travelNode->data: %d\n",travelNode->data);
#else
        //  包装器 . 钩子 . 回调函数
        printFunc(travelNode->data);
#endif
        travelNode = travelNode->next;
    }
#endif

    return ret;
}

//  指针判空
static int PointerJudge(LinkList *ptr)
{
    if(!ptr)
    {
        return NULL_PTR;
    }
    return 0;
}