#include <stdio.h>
#include <stdlib.h>

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

int linearSearch(int A[], int num, int n)
{
    int i,flag=-1;
    for(i=0;i<num;i++)
    {
        if(A[i]==n)
            flag=i;
    }
    return flag;
}


int binSearch(int A[], int num, int n)
{
    int low=0,high=num,mid,flag=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
         if(n==A[mid])
         {
             flag=mid;
             break;
         }   
        else if(n<A[mid])
            high=mid-1;
        else
            low=mid+1;
    }
    return flag;
}


int main(int n, char* args[])
{
    FILE *fp;
    fp = fopen(args[1], "r");
    int arr[100];
    int cnt = 0;
    if(fp==NULL)
    {
        printf("File doesn't exist");
        exit(0);
    }
    else
    {
        printf("---Reading from file---\n");
        while(fscanf(fp, "%d",&arr[cnt]) != EOF)
        {
            printf("%d\n",arr[cnt]);
            cnt++;
        }
        fclose(fp);
        improvedBubbleSort(arr,cnt);
        while(1)
        {
            int choice, n, pos;
            printf("\nEnter your choice:\n1:Linear search\n2:Binary search\n3:Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("\nEnter a number:");
                        scanf("%d",&n);
                        pos=linearSearch(arr,cnt,n);
                        if(pos==-1)
                            printf("\nNumber not found\n");
                        else
                            printf("\nNumber found at position:%d\n",pos+1);
                        break;
                case 2: printf("\nEnter a number:");
                        scanf("%d",&n);
                        pos=binSearch(arr,cnt,n);
                        if(pos==-1)
                            printf("\nNumber not found\n");
                        else
                            printf("\nNumber found at position:%d\n",pos+1);
                        break;
                default: return 0;
            }
        }

    }
	return 0;
}
