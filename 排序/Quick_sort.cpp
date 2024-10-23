#include<iostream>

class Quick_sort
{
    public:
    void Solution(int input[],int L,int R)
    {
        //如果左边界大于右边界，那么不做任何改变直接返回
        if(L>=R)
        {
            return;
        }
        int left=L;
        int right=R;
        //选择中间数为基准数
        int target=input[(L+R)/2];
        while(left<right)
        {
            while(input[left]<target)
            {
                left++;
            }
            while(input[right]>target)
            {
                right--;
            }
            if(left<=right){
                change(input[left],input[right]);
                left++;
                right--;
            }
        }
        Solution(input,L,right);
        Solution(input,left,R);


        
    }

    private:
    //两个数字交换
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
    int input[]={4,3,2,7,2,9,49};
    Quick_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    a.Solution(input,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",input[i]);
    }

}