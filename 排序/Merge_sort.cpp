#include<iostream>
//待排序的数组或列表分成两个子数组（或子列表），直到每个子数组只包含一个元素。因为一个元素的数组是天然有序的。

//在分解的基础上，将两个已经排好序的子数组合并成一个新的有序数组。这个过程通过比较两个子数组的元素来实现，确保合并后的数组仍然是有序的。

//重复上述两个步骤，直到所有的子数组合并成一个最终的有序数组。
class Merge_sort
{
    public:
    int* Solution(int input[],int n)
    {
        if(n==1)
        {
            int* temp=new int[1];
            temp[0]=input[0];
            return temp;
        }
        int** middle_group=split(input,n);
        int* l1=Solution(middle_group[0],n/2);
        int* l2=Solution(middle_group[1],n-n/2);
        int*result=merge(l1,l2,n);

        delete l1;
        delete l2;
        
        return result;
        
    }
    //函数中创建的参数必须用new关键字才能在全局使用
    private:
    int** split(int in[],int n)
    {
        int* l1=new int[n/2]; 
        int* l2=new int[n-n/2];
        int count=0;
        //将前一半元素存储在l1，后一半存储在l2
        for(int i=0;i<n/2;i++)
        {
            l1[count]=in[i];
            count++;
        }
        count=0;
        for(int i=n/2;i<n;i++)
        {
            l2[count]=in[i];
            count++;
        }

        int** output=new int*[2];
        output[0]=l1;
        output[1]=l2;
        return output;
    }


    //实现两个有序数组和合并
    int* merge(int a[],int b[],int n)
    {
        int* temp=new int[n];
        int count_a=0;
        int count_b=0;
        int i=0;
        // 当 a, b 数组均有剩余元素时  
        //当a,b数组均有剩余元素时   
        while (count_a < n / 2 && count_b < (n - n / 2)) {  
            if (a[count_a] <= b[count_b]) {  
                temp[i++] = a[count_a++];  
            } else {  
                temp[i++] = b[count_b++];  
            }  
        }  

         //当a数组遍历完
        while(count_b<(n-n/2))
        {
                temp[i]=b[count_b];
                count_b++;
                i++;
        }
        //当b数组遍历完
        while(count_a<n/2)
        {
                temp[i]=a[count_a];
                count_a++;
                i++;
        }

        return temp;
    }
};


//test
int main()
{
    int input[]={4,3,7,1,2,9,49};
    Merge_sort a;
    int n=sizeof(input)/sizeof(input[0]);
    int* result=a.Solution(input,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",result[i]);
    }

}