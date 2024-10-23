#include<iostream>

//第二个元素（索引 1）开始，将其视为当前需要插入的元素（称为 key），而第一个元素（索引 0）则构成已排序部分。

//遍历已排序部分，从 key 前面的元素开始向前比较，寻找合适的位置来插入 key。
//如果已排序部分的当前元素大于 key，则将该元素向后移动一位（即覆盖当前位置）。

//一旦找到一个不大于 key 的元素，或者已排序部分已遍历完，将 key 插入到合适的位置。

//对未排序部分的下一个元素重复步骤 1 到 3，直到整个数组排序完成。


//Point: 将元素从已排序区最后一个相比较，只要比已排序区元素小，已排序区元素向后移动一个。
class Insert_sort
{
    public:
    void Solution(int input[],int n)
    {
        for(int i=1;i<n;i++)
        {
            int element=input[i];
            int j=i-1;
            //查找插入位置 并将比element大的元素依次向后移动一位
            while(j>=0&&element<input[j])
            {
                input[j+1]=input[j];
                j--;
            }
            //插入
            input[j+1]=element;
        }
    }
};

//test
int main()
{
    int input[]={4,3,2,1,2,1,49};
    Insert_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}