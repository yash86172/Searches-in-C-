#include<stdio.h>

void improvedBubbleSort(int A[], int num)
{
    int i,j,flag,temp;
    for(i=0;i<num-1;i++)
    {
        flag=0;
        for(j=0;j<=num-i-2;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                flag=1;
            }
        }
        if(flag==0)
            break;
    }
}

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
    while(lo<=hi && arr[lo]<=x && arr[hi]>=x)
    {
        pos = lo + ((hi - lo)*(x - arr[lo]) / (arr[hi] - arr[lo]));
        if (arr[pos] == x)
            return pos;
        else if(arr[pos]<x)
            return interpolationSearch(arr, pos+1,hi,x);
        else if(arr[pos]>x)
            return interpolationSearch(arr,lo,pos-1,x);
    }
    return -1;
}


int main()
{
    int n,i,x;
    printf("Enter no. of elements:");
    scanf("%d",&n);
    int arr[n];
    printf("\nEnter elements:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    improvedBubbleSort(arr,n);
    printf("Enter element to be searched\n");
    scanf("%d",&x);
    int index = interpolationSearch(arr, 0, n - 1, x);
    if (index == -1)
        printf("Element not found");
    else
        printf("Element found\n");
    return 0;
}
