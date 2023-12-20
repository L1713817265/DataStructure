#ifndef __LINKLIST_H_
#define __LINKLIST_H_

#define ELEMENTTYPE int

//  链表结点取别名
typedef struct LinkNode
{
    ELEMENTTYPE data;
    //  指向下一个结点的指针
    struct LinkNode *next;    //  指针的类型为什么是结点

} LinkNode;

//  链表
typedef struct LinkList
{
    //  链表的虚拟头结点
    LinkNode *head;
    
    //  链表的长度
    int len;
} LinkList;

//  链表初始化
int LinkListInit(LinkList **pList);

//  链表头插
int LinkListHeadInsert(LinkList *pList, ELEMENTTYPE val);

//  链表尾插
int LinkListTailInsert(LinkList *pList, ELEMENTTYPE val);

//  链表指定位置插入
int LinkListAppointPosInsert(LinkList *pList, int pos, ELEMENTTYPE val);

//  链表头删
int LinkListHeadDelete(LinkList *pList, int pos);

//  链表尾删
int LinkListTailDelete(LinkList *pList);

//  链表指定位置删
int LinkListDeleteAppointPos(LinkList *pList, int pos);

//  链表删除指定元素
int LinkListDeleteAppointData(LinkList *pList, ELEMENTTYPE val);

//  获取链表的长度
int LinkListGetLength(LinkList *pList, int *pSize);

//  链表的销毁
int LinkListDestroy(LinkList *pList);

#endif