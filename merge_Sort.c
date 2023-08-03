#define  _CRT_SECURE_NO_WARNINGS

#include<string.h>
#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int tempArr[], int left, int mid, int right) {
    int l_pos=left;
    int r_pos = mid+1;
    int pos = left;
    //合并,某个半区没有元素后跳出
    while (l_pos<=mid && r_pos <=right)
    {
        if (arr[l_pos] < arr[r_pos])
            tempArr[pos++] = arr[l_pos++];
        else
            tempArr[pos++] = arr[r_pos++];
    }
    //合并左半区
    while (l_pos <= mid) {
        tempArr[pos++] = arr[l_pos++];
    }
    //合并右半区
    while (r_pos <= right){
        tempArr[pos++] = arr[r_pos++];
    }
    //赋值
    while (left<=right) {
        arr[left] = tempArr[left];
        left++;
    }
}

void msort(int arr[],int tempArr[],int left,int right) {
    if (left < right) {
        int mid = (left+right)/2;
        msort(arr,tempArr,left,mid);//划分左边
        msort(arr, tempArr, mid+1, right);//划分右边
        merge(arr, tempArr, left, mid, right);
        for (int i = 0; i < 9; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
}

void merge_sort(int arr[],int n) {
    int* tempArr = (int*)malloc(n*sizeof(int));
    if (tempArr != NULL) {
        msort(arr,tempArr,0,n-1);//归递算法
        free(tempArr);
    }
    else
    {
        printf("申请空间失败\n");
    }
}
int main() {
    int arr[] = {9,5,2,7,12,4,3,1,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,n);
    for (int i = 0; i < n; i++) {
        printf("%d  ",arr[i]);
    }
    return 0;
}

