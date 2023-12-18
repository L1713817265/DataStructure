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
};

#define DEFALUT_SIZE 10

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
int dynamicArrayInsertData(dynamicArray *pArray,ELEMENTTYPE val);

//  动态数组插入数据, 在指定位置插入
int dynamicArrayAppoinPosInsertData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

//  动态数组修改指定位置的数据
int dynamicArrayModifyAppointPosData(dynamicArray *pArray, int pos, ELEMENTTYPE val);

//  动态数组删除数据(默认情况下删除最后末尾的数据)
int dynamicArrayDelelteData(dynamicArray *pArray);

//  动态数组删除指定位置的数据
int dynamicArrayDeleteAppointPosData(dynamicArray *pArray, int pos);

//  动态数组删除指定的元素
int dynamicArrayDeleteAppointData(dynamicArray *pArray, ELEMENTTYPE val);

//  动态数组的销毁
int dynamicArrayDestroy(dynamicArray *pArray);

//  获取数组的大小
int dynamicArrayGetSize(dynamicArray *pArray, int *pSize);

//  获取数组的容量
int dynamicArrayGetCapacity(dynamicArray *pArray, int *pCapacity);
