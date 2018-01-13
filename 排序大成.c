#include<stdio.h>
#define N 10

void swap(int *a,int *b)/*const int表示*a，*b为只读*/
{   int t;
    t=*a;
	*a=*b;
	*b=t;
}
/*冒泡*/
void order1(int a[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
             if (a[j]>a[j+1])
			 {
		        swap(&a[j],&a[j+1]);
			 }
		}

	}
}
/*插入*/
void order2(int a[],int n)
{
	int i,j,t;
	for(i=1;i<n;i++)
	{
		t=a[i];
		for(j=i-1;t<a[j]&&j>=0;j--)
		{
            a[j+1]=a[j];
		}
		a[j+1]=t;
	}

}
/*选择*/
void order3(int a[],int n)
{
    int i,j,max;
    for(i=0;i<n-1;i++)
	{
		max=i;
		for(j=i+1;j<n;j++)
		{
             if (a[max]<a[j])
			 {
		        max=j;
			 }
		}
		if(max!=i)
		{
		    swap(&a[max],&a[i]);
		}
	}
}
/*两翼*/
void order4(int a[],int n )
{
	int i,j,max1,max2;
	for(i=0;i<n/2;i++)
	{
		max1=i;
		for(j=i+1;j<n-i;j++)
		{
             if (a[max1]<a[j])
			 {
		        max1=j;
			 }
		}
        if(max1!=i)
		{
		     swap(&a[max1],&a[i]); 
		}
        max2=n-1-i;
		for(j=n-2-i;j>i;j--)
		{
             if (a[max2]<a[j])
			 {
		        max2=j;
			 }
		}
        if(max2!=n-1-i)
		{
			 swap(&a[max2],&a[n-1-i]);
		}
	}
}
/*最后输出*/
void endprintf(int a[],int n)
{
    int i;
	for(i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\n");

}
int main()
{
	int a[N],i;
	printf("输入十个数字：\n");
	for(i=0;i<N;i++)
	{
		scanf("%d",&a[i]);
	}
    order4(a,N);
	endprintf(a,N);
	return 0;
}