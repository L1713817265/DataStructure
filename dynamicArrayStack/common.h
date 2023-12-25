#ifndef __COMMON_H_
#define __COMMON_H_

#define ELEMENTTYPE void *

//   避免头文件重复包含

typedef struct dynamicArray
{
    ELEMENTTYPE *data;      //数组的空间
    int len;        //数组的大小
    int capacity;   //数组的容量
}dynamicArray;

#endif