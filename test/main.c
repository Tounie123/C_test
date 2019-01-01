//
//  main.c
//  test
//
//  Created by zhou tuan on 2018/12/28.
//  Copyright © 2018年 zhou tuan. All rights reserved.
//

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void bitmapSort(char *a, int len)
{
    int length, max, min, i, index;
    length = len;
    min = max = a[0];
    //找出数组最大值
    for(i = 1; i < length; i++){
        if(a[i] > max){
            max = a[i];
        }
        if(min > a[i]) {
            min = a[i];
        }
    }
    //得到位图数组
    char *arr;
    arr = (char *)malloc(max - min + 1);
    memset(arr, 0, max - min + 1);
    for(i = 0; i < length; i++){
        index = a[i] - min;
        arr[index]++;
    }
    //重整a中的元素
    int arr_length;
    arr_length = max - min + 1;
    index = 0;
    for(i = 0; i < arr_length; i++){
        while (arr[i] > 0){
            a[index] = i + min;
            index++;
            arr[i]--;
        }
    }
    free(arr);
    arr = NULL;
}

void print(char *a, int n)
{
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main()
{
    int length;
    char test[] = {50,1,26,3,45,12,13};
    length = sizeof(test) / sizeof(test[0]);
    print(test, length);
    bitmapSort(test, length);
    print(test, length);
    return 0;
}
