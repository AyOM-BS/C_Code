#include<stdio.h>

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int left = 0;
    int right = 0;
    int lenth = sizeof(arr) / sizeof(arr[0]);
    left = arr[0];
    right = arr[lenth - 1];
    printf ("请输入要查找的数字\n");
    int k = 0;
    scanf ("%d",&k);
    int mid = (left + right) / 2;
    for (; k < arr[mid]; )
    {
        right = mid - 1;
        mid = (left + right) / 2;
    }
    for (; k > arr[mid]; )
    {
        left = mid + 1;
        mid = (left + right) / 2;
    }
    if (k == arr[mid])
    {
        printf ("找到了,该数字在第%d个\n",mid);
    }
    else
    {
        printf ("没有该数字\n");
    }
    return 0;
}