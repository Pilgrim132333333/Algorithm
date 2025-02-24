#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

class graph
{
    public:
    int V; //顶点
    vector<vector<int>> adj;   //邻接表

    graph(int V)
    {
        this->V=V;
        adj.resize(V);
    }


    //添加由u点到v点的边
    void addEdge(int u,int v)
    {
        adj[u].push_back(v); //添加u到v的边
        adj[v].push_back(u); //添加v到u的边
    }

    vector<int> BFS(int start)
    {
        vector<int> distance(V,INT_MAX); //计算起点到各个节点的最短距离
        distance[start]=0;

        queue<int> q; //建造队列
        q.push(start); //将起点推入队列
        while(!q.empty())
        {
            int u=q.front(); //取队列第一个
            q.pop(); //将其删除

            for(int i:adj[u]) //遍历i点连接的所有点
            {
                if(distance[i]==INT_MAX)
                {
                    distance[i]=distance[u]+1;
                    q.push(i);
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
        cout<<result[i]<<endl;

    }

    
}
