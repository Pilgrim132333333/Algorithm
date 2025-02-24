//一维差分
//一个数组先差分后前缀相当于原数组

//对原数组[l,r]区间的数+n
#include<iostream>
using namespace std;
int main()
{
    int array[9]={0};
    int b[9]={0};
    int l,r,n;
    cin>>l>>r;
    cin>>n;
    //定义差分数组
    for(int i=1;i<9;i++)
    {
        array[0]=0;
        scanf("%d",&array[i]);
        b[i]=array[i]-array[i-1];
    }

    //执行+n操作
    b[l]+=n;
    b[r+1]-=n;

    for(int i=1;i<9;i++)
    {
        b[i]+=b[i-1];
        printf("%d",b[i]);
    }




}