#include<iostream>
#include<vector>
#include<limits>
using namespace std;
class Prim_Algorithm
{
    public:
    int V;
    vector<vector<int>> adj;

    Prim_Algorithm(int v)
    {
        this->V=v;
        adj.resize(V);
        for(int i=0;i<V;i++)
        {
            adj[i].resize(V,INT_MAX);
        }
    }

    void addEdge(int u,int v,int val)
    {
        adj[u][v]=val;
    }
    
    bool search(vector<int> model,int n,int size)
    {
        for(int i=0;i<size;i++)
        {
            if(model[i]==n)
            {
                return true;
            }
        }
        return false;
    }
    vector<int> Solution(vector<vector<int>>adj)
    {
        vector<int> result;
        result.resize(this->V);
        result[0]=0;
        vector<bool> visit(V,false);
        visit[0]=true;
        int count=1;
        for( ;count<V+1;count++)
        {
            int Ver=-1;
            int mim=INT_MAX;
            for(int i=0;i<V;i++)
            {
                if(visit[i])
                {
                    for(int j=0;j<V;j++)
                    {
                        if(!visit[j]&&adj[i][j]<mim)
                        {
                            mim=adj[i][j];
                            Ver=j;
                        }
                    }
                }
            }
            if(Ver!=-1)
            {
                result[count]=Ver;
                visit[Ver]=true;
            }
        }
        return result;
    }
};

int main()
{
    Prim_Algorithm x(7);
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
    vector<int> result=x.Solution(x.adj);
    for(int i=0;i<7;i++)
    {
        printf("%d\n",result[i]);
    }

}