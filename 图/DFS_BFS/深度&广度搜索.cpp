#include<iostream>
#include<vector>
#include<limits>
#include<stack>
#include<queue>
using namespace std;

class search
{
    public:
    int V;
    vector<vector<int>> adj;
    search(int V)
    {
        this->V=V;
        adj.resize(V);
        for(int i=0;i<V;i++)
        {
            adj[i].resize(V,INT_MAX);
        }
    }
    void addEdge(int u,int z,int val)
    {
        adj[u][z]=val;
    }
    vector<int> DFS(int u)
    {
        vector<int> result;
        result.resize(V,-1);
        result[0]=u;
        
        vector<bool> visit;
        visit.resize(V,false);
        visit[u]=true;
        
        stack<int> middle;
        middle.push(u);
        
        int count=1;
        while(!middle.empty())
        {
            for(int i=0;i<V;i++)
            {
                if(this->adj[middle.top()][i]!=INT_MAX && !visit[i])
                {  
                    middle.push(i);
                    visit[i]=true;
                    result[count]=i;
                    count++;
                    break;
                }
                if(i==V-1)
                {
                    middle.pop();
                }
            }
        }
        return result;
    }
    vector<int> BFS(int u)
    {
        vector<int> result;
        result.resize(V,-1);

        vector<bool> visit;
        visit.resize(V,false);
        visit[u]=true;

        queue<int> middle;
        middle.push(u);

        int count=1;
        result[0]=u;
        while(!middle.empty())
        {
            for(int i=0;i<V;i++)
            {
                if(adj[middle.front()][i]!=INT_MAX&&!visit[i])
                {
                    middle.push(i);
                    visit[i]=true;
                    middle.push(i);
                    result[count]=i;
                    count++;
                }
            }
            middle.pop();
        }
        return result;
    }
};

int main()
{
    search x(7);
    x.addEdge(0,1,2);
    x.addEdge(0,3,1);
    x.addEdge(1,3,3);
    x.addEdge(1,4,10);
    x.addEdge(2,0,4);
    x.addEdge(2,5,5);
    x.addEdge(3,2,2);
    x.addEdge(3,4,2);
    x.addEdge(3,5,8);
    x.addEdge(3,6,4);
    x.addEdge(4,6,1);
    x.addEdge(6,5,1);
    vector<int> result=x.BFS(0);
    for(int i=0;i<7;i++)
    {
        printf("%d\n",result[i]);
    }

}