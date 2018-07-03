#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int m, n;
int info[1000010];

bool Compare(int a, int b)
{
    return a > b;
}

int main()
{
    while(scanf("%d %d", &n, &m) != EOF)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &info[i]);
        }
        sort(info, info+n, Compare);
        for(int i = 0; i < m - 1; i++)
            printf("%d ", info[i]);
        printf("%d\n", info[m - 1]);
    }
    return 0;
}
