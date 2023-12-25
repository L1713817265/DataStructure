#include "binarySearchTree.h"
#include <stdlib.h>

//  状态码
enum STATUS_CODE
{
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};

/* 静态函数前置声明 */
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2);

/* 创建结点 */
static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parentNode);

/* 二叉搜索树的初始化 */
int binarySearchTreeInit(BinarySearchTree **pBstree)
{
    int ret = 0;
    BinarySearchTree *bstree = (BinarySearchTree *)malloc(sizeof(BinarySearchTree) * 1);
    if(!bstree)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree, 0, sizeof(BinarySearchTree) * 1);
    /* 初始化树 */
    {
        bstree->root = NULL;
        bstree->size = 0;
    }
#if 0
    /* 分配根结点 */
    bstree->root = malloc(sizeof(BSTreeNode) * 1);
    if(!bstree->root)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(bstree->root, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根结点 */
    {
        bstree->root->data = 0;
        bstree->root->left = NULL;
        bstree->root->right = NULL;
        bstree->root->parent = NULL;
    }
#else
    bstree->root = createBSTreeNewNode(0, NULL);
    if(!bstree)
    {
        return MALLOC_ERROR;
    }
#endif

    *pBstree = bstree;
    return ret;
}

static BSTreeNode *createBSTreeNewNode(ELEMENTTYPE val, BSTreeNode *parent)
{
    /* 分配根结点 */
    BSTreeNode *newNode = malloc(sizeof(BSTreeNode) * 1);
    if(!newNode)
    {
        return MALLOC_ERROR;
    }
    /* 清除脏数据 */
    memset(newNode, 0, sizeof(BSTreeNode) * 1);
    /* 初始化根结点 */
    {
        newNode->data = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }

    /* 赋值 */
    newNode->data = val;
    newNode->parent = parent;

    return newNode;
}

#if 0
static int compareFunc(ELEMENTTYPE val1, ELEMENTTYPE val2)
{
    #if 0
    if(val1 < val2)
    {
        return -1;
    }
    else if(val1 > val2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    #else
    return val1 - val2;
    #endif
}
#endif

/* 二叉搜索树的插入 */
int binarySearchTreeInsert(BinarySearchTree *pBstree, ELEMENTTYPE val, int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2))
{
    int ret = 0;
    if(pBstree->size == 0)
    {
        /* 更新树的结点 */
        (pBstree->size)++;

        pBstree->root->data = val;
        return ret;
    }

    /* travelNode 指向根结点 */
    BSTreeNode *travelNode = pBstree->root;
    BSTreeNode *parentNode = pBstree->root;

    /* 确定符号: 到底放在左边还是右边 */
    int cmp = 0;
    while(travelNode)
    {
        /* 标记父结点 */
        parentNode = travelNode;
        cmp = compareFunc(val, travelNode->data);
        /* 出入元素 < 遍历到的结点*/
        if(cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if(cmp > 0)     /* 出入元素 > 遍历到的结点*/
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 出入元素 = 遍历到的结点*/
            return ret;
        }
    }

#if 0
    BSTreeNode *newNode = malloc(sizeof(BSTreeNode) * 1);
    if(!newNode)
    {
        return MALLOC_ERROR;
    }
    memset(newNode, 0, sizeof(BSTreeNode) * 1);
    {
        newNode->data = 0;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->parent = NULL;
    }
    /* 新结点赋值 */
    newNode->data = val;
#else
    BSTreeNode *newNode = createBSTreeNewNode(0, parentNode);
#endif

    /* 挂在左子树 */
    if(cmp < 0)
    {
        travelNode->left = newNode;
    }
    else
    {
        /* 挂在右子树 */
         travelNode->right = newNode;
    }
#if 0
    /* 新结点的parent指针赋值 */
    newNode->parent = parentNode;
#endif
    /* 更新树的结点 */
    (pBstree->size)++;

    return ret;
}

/* 二叉搜索树的前序遍历 */
int binarySearchTreePreOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;


    return ret;
}

/* 二叉搜索树的中序遍历 */
int binarySearchTreeInOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;


    return ret;
}

/* 二叉搜索树的后序遍历 */
int binarySearchTreePostOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;


    return ret;
}

/* 二叉搜索树的层序遍历 */
int binarySearchTreeLevelOrderTravel(BinarySearchTree *pBstree)
{
    int ret = 0;


    return ret;
}