#include<iostream>


//从头到尾依次比较相邻的两个元素。
//如果前一个元素大于后一个元素，则交换它们的位置。
//重复步骤1和2，直到没有需要交换的元素为止。
//O(n^2)

class Bubble_sort{
    public:
    //算法的实现
    //如果传入静态数组，那么需要使用sizeof函数，且方程中的sizeof函数仅会返回数组指针的大小
    //vector数组可以使用size（）函数
    void Solution(int input[],int n)
    {
        for(int i=n-1;i>0;i--)
        {
            for(int j=1;j<=i;j++)
            {
                if(input[j-1]>input[j])
                {
                    change(input[j-1],input[j]);
                }
            }
        }
    }
    private:
    //交换两个数字
    //用&a,&b的原因：如果不用&则只是在函数作用域内暂时改变a，b的值，而使用&则可以直接改变数组内的两个元素
    void change(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
};


//test
int main()
{
    int input[]={4,3,7,1,2,9,49};
    Bubble_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}