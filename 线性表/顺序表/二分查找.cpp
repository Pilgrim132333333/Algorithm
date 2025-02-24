#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class BinarySearch{
    public:
    //Situation1:
    //[left,right]
    int Situation1(vector<int> &nums,int target)
    {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<=right)
        {
            int middle=(right+left)/2;
            if(nums[middle]==target)
            {
                return middle;
            }
            else{
                if(nums[middle]>target)
                {
                    right=middle-1;
                }
                else{
                    left=middle+1;
                }
            }
        }
        return -1;
    }

    //Situation2：
    //[left,right)
    int Situation2(vector<int> &nums,int target)
    {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int left=0;
        int right=n;
        while(left<right)
        {
            int middle=left+(right-left)/2;
            if(nums[middle]==target)
            {
                return middle;
            }
            else{
                if(nums[middle]>target)
                {
                    right=middle;
                }
                else{
                    left=middle+1;
                }
            }
        }
        return -1;
    }

};


int main()
{
    BinarySearch bs;
    vector<int> nums = {1, 3, 5, 7, 9};
    int target = 5;
    int result = bs.Situation1(nums, target);
    if (result!= -1)
    {
        cout << "Target found at index " << result << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }
    return 0;
}
