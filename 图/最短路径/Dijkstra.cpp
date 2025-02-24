
#include<iostream>
#include<queue>
#include<limits.h>
#include<vector>
using namespace std;

//DiJkstra算法的实现
//vector需要resize函数来确定大小和初始化
class Dijkstra
{
    public:
    int V;
    vector<vector<int>> adj;
    Dijkstra(int V)
    {
        this->V=V;
        //确定adj有几行
        adj.resize(V);
        //确定有几列并且初始化为INT_MAX
        for(int i=0;i<V;i++)
        {
            adj[i].resize(V,INT_MAX);
        }
    }
    //增加边
    void addEdge(int u,int v,int val)
    {
        adj[u][v]=val;
    }
    
    vector<vector<int>> Soluation(int start)
    {
        vector<vector<int>> result(2,vector<int>(V,INT_MAX));
        //距离和路线列表
        vector<int> distance(V,INT_MAX);
        vector<int> path(V,-1);

        distance[start]=0;
        path[start]=0;

        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<V;i++)
            {
                //假如u到i有路线
                if(adj[u][i]!=INT_MAX)
                {
                    //假如这条路线小于之前通往i点的路线
                    //或还没有通往i点的路线
                    if(adj[u][i]+distance[u]<distance[i])
                    {
                        distance[i]=adj[u][i]+distance[u];
                        path[i]=u;
                        q.push(i);
                    }
                }
            }
        }
        result[0]=distance;
        result[1]=path;
        return result;
    }
};


int main()
{
    Dijkstra x(7);
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
    vector<vector<int>>result=x.Soluation(2);
    for(int i=0;i<7;i++)
    {
        printf("v%d %d %d\n",i+1,result[0][i],result[1][i]);
    }

}