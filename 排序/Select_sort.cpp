#include<iostream>
#include<limits>

//从未排序部分中遍历找到最小的元素。
//记录该最小元素的位置。

//将找到的最小元素与未排序部分的第一个元素交换位置。
//这样，未排序部分的长度减少，已排序部分的长度增加。

//对剩余的未排序部分重复步骤 2 和 3，直到整个数组排序完成。
//O(n^2)

class Select_sort{
    public:
    //算法的实现
    void Solution(int input[],int n)
    {
        for(int i=0;i<n;i++)
        {
            //使待定的中间值等于最大的int
            int middle= std::numeric_limits<int>::max();
            int change_number;
            for(int j=i;j<n;j++)
            {
                if(input[j]<middle)
                {
                    change_number=j;
                    middle=input[j];
                }
            }
            change(input[change_number],input[i]);
        }

    }
    private:
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
    int input[]={4,3,2,1,2,9,49};
    Select_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}