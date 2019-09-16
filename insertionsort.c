#include<stdio.h>
void main()
{
    int n,a[100],i;
    void insertionSort(int*,int);
    printf("enter the number of elements:\n");
    scanf("%d",&n);
    printf("Enter numbers one by one:\n");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("ENTERED ARRAY(BEFORE SORTING)\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
    insertionSort(a,n);
    printf("\nAFTER SORTING\n");
    for(i=0;i<n;i++)
        printf("%d\t",a[i]);
}
void insertionSort(int*a,int n)
{
    int i,j,temp;
    for(i=1;i<n;i++)
    {
        temp=a[i];
        for(j=i-1;j>=0&&temp<a[j];j--)
            a[j+1]=a[j];
        a[j+1]=temp;
    }
}
