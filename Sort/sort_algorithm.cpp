#include "sort_algorithm.h"

using namespace std;

void BubbleSort::sort(vector<T> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
    return;
}

void SelectSort::sort(vector<T> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int min_index=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_index])
            {
                min_index=j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
    return;
}

void InsertSort :: sort(vector<T> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    return;
}

vector<T> MergeSort :: split(vector<T> &arr,int left,int right){
    if(left<right){
        return arr[right];
    }
    mid = (left+right)/2;
    left_arr = arr[left:mid];
    left_right = arr[mid+1:right];
    vector<T> l1=split(left_arr,left,mid);
    vector<T> l2=split(right_arr,mid+1,right);
    vector<T> merged_arr=merge(l1,l2);
    return merged_arr;
}

vector<T> MergeSort :: merge(vector<T> &left_arr,vector<T> &right_arr){
    vector<T> merged_arr;
    int i=0,j=0;
    while(i<left_arr.size() && j<right_arr.size())
    {
        if(left_arr[i]<right_arr[j])
        {
            merged_arr.push_back(left_arr[i]);
            i++;
        }
       else{
        merged_arr.push_back(right_arr[j]);
        j++;
       }
    }
    while(i<left_arr.size())
    {
        merged_arr.push_back(left_arr[i]);
    }
    while(j<right_arr.size())
    {
        merged_arr.push_back(right_arr[j]);
    }
    return merged_arr;
}

void MergeSort :: sort(vector<T> &arr){
    vector<T> sorted_arr=quick_sort(arr,0,arr.size()-1);
    for(int i=0;i<sorted_arr.size();i++)
    {
        arr[i]=sorted_arr[i];
    }
    return;
}

void QuickSort :: sort(vector<T> &arr){
    quick_sort(arr,0,arr.size()-1);
    return;
}

void QuickSort :: quick_sort(vector<T> &arr,int left,int right){
    if(right<left)
    {
        return;
    }
    int lleft=left;
    int rright=right;
    int pivot=arr[(left+right)/2]
    while(left<right)
    {
        if(arr[left]>pivot)
        {
            swap(arr[left],arr[right]);
            right--;
        }
        else{
            left++;
        }
        if(arr[right]<pivot)
        {
            swap(arr[left],arr[right]);
            left++;
        }
        else{
            right--;
        }
    }
    quick_sort(arr,lleft,right);
    quick_sort(arr,left,rright);
    return;
}