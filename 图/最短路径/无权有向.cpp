#include<vector>
#include<iostream>
#include<limits.h>
#include<queue>
using namespace std;

//有向图仅仅是在无向无权图的基础上修改邻接表使之不对称
class graph
{
    public:
    int V;
    vector<vector<int>> adj;

    graph(int V)
    {
        this->V=V;
        adj.resize(V);
    }

    void addEdge(int u,int v)
    {
        adj[u].push_back(v);
    }

    vector<int> BFS(int start)
    {
        vector<int> distance(V,INT_MAX);
        distance[start]=0;

        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i:adj[u])
            {
                if(distance[i]==INT_MAX)
                {
                    distance[i]=distance[u]+1;
                }
            }
        }
        return distance;

    }
};


int main()
{
    graph x(5);
    x.addEdge(0,1);
    x.addEdge(1,2);
    x.addEdge(1,3);
    x.addEdge(3,4);
    vector<int> result=x.BFS(3);
    for(int i=0;i<5;i++)
    {
        if(result[i]==INT_MAX)
        {
            cout<<"Can't Reach"<<endl;
            continue;
        }
        cout<<result[i]<<endl;

    }

    
}