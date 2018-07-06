#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int h, w, n, p, answer;
const int NUM = 200000;

struct SegementTree
{
    int l, r;
    int count;
}Tree[NUM * 4];

void CreateSegmentTree(int l, int r, int x)
{
    Tree[x].l = l;
    Tree[x].r = r;
    Tree[x].count = w;
    if(l >= r)
    {
        return;
    }
    int mid = (l + r) / 2;
    CreateSegmentTree(l, mid, x << 1);
    CreateSegmentTree(mid + 1, r, x << 1 | 1);
}

void MaintainSegmentTree(int x, int value)
{
    if(Tree[x].count < value)
        return;
    if(answer != -1)
        return;
    if(Tree[x].l == Tree[x].r)
    {
        if(Tree[x].count >= value)
        {
            Tree[x].count -= value;
            answer = Tree[x].l;
        }
        return;
    }
    MaintainSegmentTree(x << 1, value);
    MaintainSegmentTree(x << 1 | 1, value);
    if(answer != -1)
    {
        // 更新父节点
        Tree[x].count = max(Tree[x << 1].count, Tree[x << 1 | 1].count);
    }
}

int main()
{
    while(scanf("%d %d %d", &h, &w, &n) != EOF)
    {
        if(h > n)h = n;//剪枝h
        CreateSegmentTree(1, h, 1);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &p);
            answer = -1;
            MaintainSegmentTree(1, p);
            printf("%d\n", answer);
        }
    }
    return 0;
}
