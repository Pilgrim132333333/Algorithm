#include "Heapify.cpp"
#include<iostream>
#include<vector>
using namespace std;
class Heap_sort
{
    private:
    void build_heap(vector<int>&array,int size)
    {
        for(int i=(size-1)/2;i>=0;i--)
        {
            Heapify(array,size,i);
        }
    }
    public:
    vector<int> Heap_sort_new(vector<int>& array,int size)
    {
        vector<int> result;
        build_heap(array,size);
        for(int i=size-1;i>=0;i--)
        {
            swap(array[0],array[i]);
            Heapify(array,i,0);
        }
        return array;
    }
};