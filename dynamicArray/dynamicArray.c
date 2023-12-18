#include "dynamicArray.h"
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

#define DEFALUT_SIZE 10

//  静态函数前置声明: 静态函数一定要前置声明
static int extendDynamicCapacity(dynamicArray *pArray);
static int shrinkDynamicCapacity(dynamicArray *pArray);

//  动态数组的初始化
int dynamicArrayInit(dynamicArray *pArray, int capacity)
{
    if(!pArray)
    {
        return NULL_PTR;
    }

    //  避免传入非法值
    if(capacity < 0)
    {
        capacity = DEFALUT_SIZE;
    }

    //  分配空间
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * capacity);
    if(!pArray->data)
    {
        return MALLOC_ERROR;
    }
    //  清除脏数据
    memset(pArray->data, 0, sizeof(ELEMENTTYPE) * capacity);

    pArray->len = 0;
    pArray->capacity = capacity;

    return ON_SUCCESS;
}

//  动态数组插入数据(默认插到数组的末尾)
int dynamicArrayInsertData(dynamicArray *pArray,ELEMENTTYPE val)
{
    return dynamicArrayAppoinPosInsertData(pArray, pArray->len, val);
}

//  动态数组扩容
static int extendDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;

    int needExtendCapacity = pArray->capacity + (pArray->capacity >> 1);

    //  备份指针
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needExtendCapacity);
    if(!pArray->data)
    {
        return MALLOC_ERROR;
    }

    //  把之前的数据全部拷贝过来
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    //释放以前的内存 避免内存泄漏
    if(tmpPtr)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    //  更新动态数组的容量
    pArray->capacity = needExtendCapacity;

    return ret;
}

//  动态数组插入数据, 在指定位置插入
int dynamicArrayAppoinPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    //  指针判空
    if(!pArray)
    {
        return NULL_PTR;
    }

    //  判断位置的合法性
    if(pos < 0 || pos > (pArray->len))
    {
        return INVALID_ACCESS;
    }

    //  数组扩容的临界值是: 数组大小的1.5倍 >= 数组容量
    if(pArray->len + (pArray->len >> 1) >= pArray->capacity)
    {
        //  开始扩容
        extendDynamicCapacity(pArray);
    }
    

    //  数据后移 留出pos位置插入
    for(int idx = pArray->len; idx > pos; idx--)
    {
        pArray->data[idx] = pArray->data[idx - 1];
    }
    //  找到对应的值 填入到数组中
    pArray->data[pos] = val;

    //  数组大小加一
    (pArray->len)++;

    return ON_SUCCESS;
}

//  动态数组修改指定位置的数据
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val)
{
    //  指针判空
    if(!pArray)
    {
        return NULL_PTR;
    }

    //  判断位置的合法性
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    //  更新位置的数据
    pArray->data[pos] = val;

    return ON_SUCCESS;
}

//  动态数组删除数据(默认情况下删除最后末尾的数据)
int dynamicArrayDelelteData(dynamicArray *pArray)
{
    dynamicArrayDeleteAppointPosData(pArray, pArray->len - 1);
}

//  动态数组缩容
static int shrinkDynamicCapacity(dynamicArray *pArray)
{
    int ret = 0;

    int needShrinkCapacity = pArray->capacity - (pArray->capacity >> 1);

    //  备份指针
    ELEMENTTYPE *tmpPtr = pArray->data;
    pArray->data = (ELEMENTTYPE *)malloc(sizeof(ELEMENTTYPE) * needShrinkCapacity);
    if(!pArray->data)
    {
        return MALLOC_ERROR;
    }

    //  拷贝之前的数据到之前的空间
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = tmpPtr[idx];
    }

    //  释放以前的内存 避免内存泄漏
    if(tmpPtr)
    {
        free(tmpPtr);
        tmpPtr = NULL;
    }

    //  更新动态数组的容量
    pArray->capacity = needShrinkCapacity;

    return ret;
}

//  动态数组删除指定位置的数据
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos)
{
    //  指针判空
    if(!pArray)
    {
        return NULL_PTR;
    }

    //  判断位置得到合法性
    if(pos < 0 || pos >= pArray->len)
    {
        return INVALID_ACCESS;
    }

    //  缩容
    if(pArray->len < pArray->capacity >> 1)
    {
        shrinkDynamicCapacity(pArray);
    }
    //  数据前移
    for(int idx = 0; idx < pArray->len; idx++)
    {
        pArray->data[idx] = pArray->data[idx + 1];
    }

    //  更新数组的大小
    (pArray->len)--;

    return ON_SUCCESS;
}

//  动态数组删除指定的元素
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val)
{
    for(int idx = pArray->len - 1; idx >= 0; idx--)
    {
        if(val == pArray->data[idx])
        {
            dynamicArrayDeleteAppointPosData(pArray, idx);
        }
    }
    return ON_SUCCESS;
}

//  动态数组的销毁
int dynamicArrayDestroy(dynamicArray *pArray)
{
    if(!pArray)
    {
        return NULL_PTR;
    }

    if(pArray->data)
    {
        free(pArray->data);
        pArray->data = NULL;
    }
    return ON_SUCCESS;
}

//  获取数组的大小
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize)
{
    if(!pArray)
    {
        return NULL_PTR;
    }

    //  解引用
    if(pSize)
    {
        *pSize = pArray->len;
    }
    return ON_SUCCESS;
}

//  获取数组的容量
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity)
{
    if(!pArray)
    {
        return NULL_PTR;
    }

    if(pCapacity)
    {
        *pCapacity = pArray->capacity;
    }
    return ON_SUCCESS;
}

//  获取指定位置的元素数据
int dynamicArrayGetAppointPosVal(dynamicArray *pArray, int pos, ELEMENTTYPE *pVal)
{
    //  指针判空
    if(!pArray)
    {
        return NULL_PTR;
    }

    //  判断位置的合法性
    if(pos < 0 || pos >=pArray->len)
    {
        return INVALID_ACCESS;
    }

    if(pVal)
    {
        *pVal = pArray->data[pos];
    }

    return ON_SUCCESS;
}
