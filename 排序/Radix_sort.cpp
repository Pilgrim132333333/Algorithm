#include<iostream>
#include<vector>
#include<limits>
#include<cmath>
class Radix_sort
{
    private:
    int get_dix(int x,int dix)
    {
        int result;
        result=(x/dix)%10;
        return result;
    }
    public:
    void Solution(int* input,int size)
    {
        std::vector<std::vector<int>> bucket(10);
        int max=std::numeric_limits<int>::min();
        //找出最大值
        for(int i=0;i<size;i++)
        {
            if(input[i]>max)
            {
                max=input[i];
            }
        }

        //n为max的位数
        int n=0;
        int dig=1;
        while(max/dig>0)
        {
            n++;
            dig*=10;
        }

        //在10的i次方位进行操作
        for(int i=0;i<n;i++)
        {

            //检查input的各个数字应该放进哪个bucket，并插入
            for(int j=0;j<size;j++)
            {
                int x=get_dix(input[j],int(pow(10,i)));
                bucket[x].push_back(input[j]);
            }

            //将bucket中的各个元素取出插入放进input中
            int j=0;
            int dig=0;
            while(j<size)
            {
                //当bucket[j]为的vector不为空时按顺序取出元素，并删除第一个元素
                while(!bucket[dig].empty())
                {
                    input[j]=bucket[dig][0];
                    bucket[dig].erase((bucket[dig].begin()));
                    j++;
                }
                dig++;
            }

        }
        
    }
};

//test
int main()
{
    int input[]={4,3,2,1,2,9,49};
    Radix_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}