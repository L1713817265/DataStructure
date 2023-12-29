#include "doubleLinkListQueue.h"
#include "doubleLinkList.h"


/* 队列初始化 */
int doubleLinkListQueueInit(DoubleLinkListQueue **pQueue)
{
    return DoubleLinkListInit(pQueue);
}

/* 队列入队 */
int doubleLinkListQueuePush(DoubleLinkListQueue *pQueue, ELEMENTTYPE val)
{
    return DoubleLinkListTailInsert(pQueue, val);
}

/* 查看队头元素 */
int doubleLinkListQueueTop(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return DoubleLinkListGetHeadVal(pQueue, pVal);
}

/* 查看队尾元素 */
int doubleLinkListQueueRear(DoubleLinkListQueue *pQueue, ELEMENTTYPE *pVal)
{
    return DoubleLinkListGetTailVal(pQueue, pVal);
}

/* 队列出队 */
int doubleLinkListQueuePop(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListHeadDelete(pQueue);
}

/* 队列长度 */
int doubleLinkListQueueGetSize(DoubleLinkListQueue *pQueue, int *pSize)
{
    return DoubleLinkListGetLength(pQueue, pSize);
}

/* 队列是否为空 */
int doubleLinkListQueueIsEmpty(DoubleLinkListQueue *pQueue)
{
    int size = 0;
    DoubleLinkListGetLength(pQueue, &size);
    return size == 0 ? 1 : 0;
}

/* 队列销毁 */
int doubleLinkListQueueDestroy(DoubleLinkListQueue *pQueue)
{
    return DoubleLinkListDestroy(pQueue);
}