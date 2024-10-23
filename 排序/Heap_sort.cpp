#include<iostream>

//堆指的是一个完全二叉树（只有最底层为空，且必须从左到右依次填满）
//分为大根堆与小根堆

class Stack_sort
{
    public:
    //假如输入为大根堆
    void Solution_1(int input[],int size)
    {
        int count=1;
        for(int i=0;i<size;i++)
        {
            change(input[0],input[size-count]);
            xia_lv_Solution(input,size-count);
            count++;
        }


    }
    
    private:
    //交换两个数的值
    //*用于函数中*
    //需要传入变量的引用，否则会带入与变量具有相同的值的副本，无法真正改变变量的值
    //可以认为传入的是a的地址，直接对应a变量，所以与平常的交换相比，不再是交换value的值而是改变变量
    void change(int &a,int &b)
    {
        int temp=a;
        a=b;
        b=temp;
    }
    
    //此函数仅仅用于将最顶部的数插入到堆的正确位置
    void xia_lv_Solution(int input[],int size)
    {
        int i=0;
        int left_leaf=2*i+1;
        int right_leaf=2*i+2;
        int middle;
        while(left_leaf<size)
        {
            if(right_leaf<size)
            {
                middle=input[left_leaf]>input[right_leaf] ? left_leaf : right_leaf;
            }
            else{
                middle=left_leaf;
            }
          

            if(input[middle]>input[i])
            {
                change(input[i],input[middle]);
                i=middle;
            }
            else{
                break;
            }
            left_leaf=2*i+1;
            right_leaf=2*i+2;
        }
    }

    //构建大根堆
    int* stack_struct(int input[],int size)
    {
        int* result=new int[size];
        int count=0;
        for(int i=0;i<size;i++)
        {
            if(i==0)
            {
                result[0]=input[0];
                count++;
            }
            else{
                xia_lv_Solution(result,count);
                count++;
            }
        }
    }
};

//test
int main()
{
    int input[]={90,10,6,7,2,3,4,1};
    Stack_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution_1(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}