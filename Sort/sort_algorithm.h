#ifndef SORT_ALGORITHM_H
#define SORT_ALGORITHM_H

#include <vector>
#include <string>
using namespace std;

template<typename T>
class SortAlgorithm {
public:
     virtual ~SortAlgorithm() = default;
     virtual void sort(vector<T> &arr) = 0;
};

class BubbleSort : public SortAlgorithm{
public:
    void sort(vector<T> &arr) override;

}

class SelectSort : public SortAlgorithm{
    void sort(vector<T> &arr) override;
}

class InsertSort : public SortAlgorithm{
    void sort(vector<T> &arr) override; 
}

class MergeSort : public SortAlgorithm{
    void sort(vector<T> &arr) override;
    vector<T> split(vector<T> &arr,int left,int right);
    void merge(vector<T> &left_arr,vector<T> &right_arr);
    }

class QuickSort : public SortAlgorithm{
    void sort(vector<T> &arr) override;
    void quick_sort(vector<T> &arr,int left, int right);
}


#endif