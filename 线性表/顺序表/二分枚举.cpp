//在所有可能的结果中二分枚举中所有满足条件的结果

//Eg. Leetcode 875
#include<vector>
#include<limits>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        vector<int> result;
        int max=*std::max_element(piles.begin(),piles.end());
        int left=1;
        int right=max;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(process(mid,piles,h))
            {
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return right;

    }
    bool process(int r,vector<int>& piles,int h)
    {
        int n=piles.size();
            int count=0;
            for(int i=0;i<n;i++)
            {
                count+=(piles[i]+r-1)/r;
            }
            if(count<=h)
            {
                return true;
            }
            else{
                return false;
            }
    }
};

int main()
{
    vector<int> piles={312884470};
    Solution a;
    int x=a.minEatingSpeed(piles,312884470);
    printf("%d",x);

}

//不使用常规二分查找方法因为数据过大会造成栈溢出
