#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

const int N = 210;
int edge[N][N], pre[N];
bool visit[N];
int m, n, si, ei, ci, result, p, i;

bool BFS(int s, int t)
{
    memset(visit, false, sizeof(visit));
    memset(pre, -1, sizeof(pre));
    queue<int> q;
    q.push(s);
    visit[s] = true;
    pre[s] = s;
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        for(i = 1; i <= m; i++)
        {
            if(visit[i] || edge[p][i] <= 0)
                continue;
            visit[i] = true;
            pre[i] = p;
            if(i == t)return true;
            q.push(i);
        }
    }
    return false;
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        result = 0;
        memset(edge, 0, sizeof(edge));
        while(n--)
        {
            scanf("%d %d %d", &si, &ei, &ci);
            edge[si][ei] += ci;//×¢ÒâÖØ±ß
        }
        while(BFS(1, m))
        {
            int end = m, start, minF = INT_MAX;
            for(end = m; end != 1; end=start)
            {
                start = pre[end];
                minF = min(minF, edge[start][end]);
            }
            for(end = m; end != 1; end = start)
            {
                start = pre[end];
                edge[start][end] -= minF;
                edge[end][start] += minF;
            }
            result += minF;
        }
        printf("%d\n", result);
    }
    return 0;
}
