//单调栈就是在一个列表中找到一串递增数
//eg:[3,2,4,1,2,2,3,7,5,6,8,7,8]
//单调递增栈：[1,2,3,5,6,7,8] 找到最小数并只在右侧找到比他大的并以此类推
#include<vector>
#include<stack>
#include<iostream>
using namespace std;
class up_stack{
    public:
    vector<int> Solution(vector<int> x)
    {
        stack<int> result;
        vector<int> re;
        for(int i=0;i<x.size();i++)
        {
            if(result.empty())
            {
                result.push(x[i]);
                continue;
            }
            while(!result.empty()&&x[i]<=result.top())
            {
                result.pop();
            }
            result.push(x[i]);
        }
        while(!result.empty())
        {
            int count=0;
            re.push_back(result.top());
            result.pop();
        }
        return re;
    }
};
int main()
{
    vector<int> x={1,23,42,1,3,2,1,4,4,3,7,5,3,8,6,5,4,44,8,9,6,9};
    up_stack a;
    vector<int> result=a.Solution(x);
    for(int i=0;i<result.size();i++)
    {
        printf("%d",result[i]);
    }
}