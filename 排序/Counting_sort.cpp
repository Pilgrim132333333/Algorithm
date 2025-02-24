#include<iostream>
#include<limits>
class Counting_sort
{
    private:
    int* make_middle(int size)
    {
        int* middle=new int[size];
        std::fill(middle,middle+size,0);
        return middle;
    }
    public:
    void Solution(int* input,int size)
    {
        int min=std::numeric_limits<int>::max();
        int max+=std::numeric_limits<int>::min();
        for(int i=0;i<size;i++)
        {
            if(input[i]>max)
            {
                max=input[i];
            }
            if(input[i]<min)
            {
                min=input[i];

                
            }
        }
        int middle_size=max-min+1;
        int* middle=make_middle(middle_size);

        for(int i=0;i<size;i++)
        {
            int diff=input[i]-min;
            middle[diff]++;
        }

        int count_middle=0;
        for(int i=0;i<size;i++)
        {
            while(middle[count_middle]==0)
            {
                count_middle++;
            }
            input[i]=min+count_middle;
            middle[count_middle]--;
        }
        return;
    }
};

//test
int main()
{
    int input[]={4,3,2,7,2,9,49};
    Counting_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}