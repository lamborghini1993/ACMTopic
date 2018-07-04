#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
using namespace std;

int N, T, time, s, t, i, j;
int num[210];

int main()
{
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &N);
        memset(num, 0, sizeof(num));
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d", &s, &t);
            if(s > t)
                swap(s, t);
            s = (s + 1) / 2;//设置为一边即可
            t = (t + 1) / 2;
            for(j = s; j <= t; j++)
                num[j]++;
        }
        time = 0;
        for(i = 0; i < 205; i++)
        {
            if(time < num[i])
                time = num[i];
        }
        printf("%d\n", time * 10);
    }
    return 0;
}
