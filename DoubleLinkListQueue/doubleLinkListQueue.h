#ifndef __DOUBLE_LINKLIST_QUEUE_H_
#define __DOUBLE_LINKLIST_QUEUE_H_


/* 队列初始化 */
int doubleLinkListQueueInit();

/* 队列入队 */
int doubleLinkListQueuePush();

/* 查看队头元素 */
int doubleLinkListQueueTop();

/* 查看队尾元素 */
int doubleLinkListQueueRear();

/* 队列出队 */
int doubleLinkListQueuePop();

/* 队列长度 */
int doubleLinkListQueueGetSize();

/* 队列是否为空 */
int doubleLinkListQueueIsEmpty();

/* 队列销毁 */
int doubleLinkListQueueDestroy();

#endif