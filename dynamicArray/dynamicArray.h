#ifndef __DYNAMIC_ARRAY_H_
#define __DYNAMIC_ARRAY_H_


typedef int ELEMENTTYPE;
//   避免头文件重复包含

typedef dynamicArray
{
    ELEMENTTYPE *data;      //数组的空间
    int len;        //数组的大小
    int capacity;   //数组的容量
}dynamicArray;

//  API: application program interface

//  动态数组的初始化
int dynamicArrayInit();

//  动态数组插入数据(默认插到数组的末尾)
int dynamicArrayInsertData();

//  动态数组插入数据, 在指定位置插入
int dynamicArrayAppoinPosInsertData();

//  动态数组修改指定位置的数据
int dynamicArrayModifyAppointPosData();

//  动态数组删除数据(默认情况下删除最后末尾的数据)
int dynamicArrayDelelteData();

//  动态数组删除指定位置的数据
int dynamicArrayDeleteAppointPosData();

//  动态数组的销毁
int dynamicArrayDestroy();

//  获取数组的大小
int dynamicArrayGetSize();

//  获取数组的容量
int dynamicArrayGetCapacity();


#endif //__DYNAMICARRAY_H_