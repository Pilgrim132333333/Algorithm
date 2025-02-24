#include <iostream>
#include <vector>
#include <queue>
#include <limits.h> // 包含INT_MAX
using namespace std;

vector<int> Solution(vector<vector<int>> adj) {
    vector<int> result(V, -1); // 初始化结果为-1表示未访问
    vector<bool> visited(V, false); // 跟踪已访问的节点
    result[0] = 0; // 从第一个顶点开始
    visited[0] = true;

    for (int count = 1; count < V; count++) {
        int mim = INT_MAX;
        int Ver = -1;

        for (int i = 0; i < V; i++) {
            if (visited[i]) {
                for (int j = 0; j < V; j++) {
                    if (!visited[j] && adj[i][j] < mim) {
                        mim = adj[i][j];
                        Ver = j;
                    }
                }
            }
        }

        if (Ver != -1) {
            result[count] = Ver;
            visited[Ver] = true;
        }
    }
    return result;
}