#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int N=30010;

vector<int> a;  //用于存储待离散化或代存储的值
int b[N];  //用于记录修改值对应的操作
int s[N];  //前缀和数组

//用于输入操作和查找操作
vector<pair<int,int>> add,query;

//二分查找位置
int find(int x)
{
    int l=0,r=a.size()-1;
    while(l<r)
    {
        int middle=l+r>>2;
        if(a[middle]>=x)
        {
            r=middle;
        }
        else{
            l=middle+1;
        }
    }
    return l;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c}); 
        a.push_back(x);  //将需要被操作的x推进a
    }
    for(int i=0;i<m;i++)
    {
        int l,r;
        cin>>l>>r;

        query.push_back({l,r});

        a.push_back(l);
        a.push_back(r);
    }

    sort(a.begin(),a.end()); //sort
    a.erase(unique(a.begin(),a.end()));  //删除相邻的重复元素

    for(auto item:add)
    {
        int j=find(item.first);
        b[j]+=item.second; //将与b对应于a的元素加加
    }

    //制作前缀和数组，减小时间复杂度
    for(int i=0;i<a.size();i++)
    {
        if(i==0)
        {
            s[i]=b[i];
        }
        else{
            s[i]=s[i-1]+b[i];
        }
    }

    //查询
    for(auto item:query)
    {
        int i=find(item.first);
        int j=find(item.second);

        if(i==0)
        {
            cout<<s[j];
        }
        else{
            cout<<s[j]-s[i-1]<<endl;
        }

    
    }
}