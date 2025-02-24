#include<iostream>
#include<vector>
using namespace std;
//构建堆的算法中最为重要的一步，用于局部维护形成堆
void Heapify(vector<int>& array,int size,int i)
{
    //可以用于以i为根节点一下的大小为size的树的维护
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<size&&array[left]>array[largest])
    {
        largest=left;
    }

    if(right<size&&array[right]>array[largest])
    {
        largest=right;
    }

    //如果调整了一次根节点和叶节点，那么可能会破坏下面的树
    //需要递归来调整
    if(largest!=i)
    {
        swap(array[i],array[largest]);
        Heapify(array,size,largest);
    }
}