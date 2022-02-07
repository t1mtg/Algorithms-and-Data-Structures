#include <iostream>
#include <vector>

using namespace std;

struct node {
    vector<int> edges;
};

void dfs(int k, vector<node>& graph, vector<vector<int>>&d)
{
    d[k][0] = 0;
    d[k][1] = 1;
    for(int i = 0; i < graph[k].edges.size(); i++)
        dfs(graph[k].edges[i], graph, d);
    for(int i = 0; i < graph[k].edges.size(); i++) {
        d[k][1] += d[graph[k].edges[i]][0];
        d[k][0] += max(d[graph[k].edges[i]][0], d[graph[k].edges[i]][1]);
    }

}


int main() {
    int n;
    cin >> n;
    vector<int> result;
    vector<node> graph(n);
    int root = 0;
    vector<vector<int>> d(n, vector<int>(2));
    int a;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        if(a != 0)
            graph[a - 1].edges.push_back(i);
        else
            root = i;

    }
    
    dfs(root, graph, d);
    cout << max(d[root][0], d[root][1]);
    return 0;
}