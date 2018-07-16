#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int eggs, floors;
int result[1001][32];

void DroppingEggsPuzzle()
{
    for(int x = 1; x < 32; x++)
        result[1][x] = x;

    for(int n = 2; n < 1001; n++)
    {
        for(int x = 2; x < 32; x++)
        {
            if(n >= x - 1) result[n][x - 1] = result[x - 1][x - 1];
            result[n][x] = result[n - 1][x - 1] + 1 + result[n][x - 1];
        }
    }
    //for(int n=1;n<=100;n++)
    //    for(int x = 1; x < 32; x++)
    //        printf("resutl[%d][%d]=%d\n",n,x,result[n][x]);

}

int findNum()
{
    for(int x = 1;; x++)
    {
        if(result[eggs][x] >= floors)
        {
            return x;
        }
    }
}

int main()
{
    DroppingEggsPuzzle();
    while(scanf("%d %d", &eggs, &floors) != EOF)
    {
        cout << findNum() << endl;
    }
    return 0;
}

//#include <iostream>
//#include <stack>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//int eggs, floors;
//int result[2][10001];//奇/偶数个鸡蛋对应第几层里面存放的值
//
//int DroppingEggsPuzzle()
//{
//
//    for(int j = 0; j < floors + 1; j++)
//    {
//        result[0][j] = result[1][j] = j;
//    }
//
//    for(int i = 2; i <= eggs; i++)
//    {
//        for(int j = 2; j <= floors; j++)
//        {
//            int maxNum = 0x7fffffff, temp;
//            for(int x = 1; x <= floors; x++)
//            {
//                temp = max(result[(i - 1) % 2][x - 1], result[i % 2][j - x]) + 1;
//                maxNum = min(maxNum, temp);
//            }
//            result[i % 2][j] = maxNum;
//        }
//    }
//    return result[eggs % 2][floors];
//}
//
//int main()
//{
//    while(scanf("%d %d", &eggs, &floors) != EOF)
//    {
//        cout << DroppingEggsPuzzle() << endl;
//    }
//    return 0;
//}



//#include <iostream>
//#include <stack>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//using namespace std;
//
//int eggs, floors;
//int result[1001][10001];
//
//int DroppingEggsPuzzle()
//{
//    for(int i = 0; i < eggs + 1; i++)
//    {
//        result[i][0] = 0;
//        result[i][1] = 1;
//
//    }
//    for(int j = 0; j < floors + 1; j++)
//    {
//        result[0][j] = 0;
//        result[1][j] = j;
//
//    }
//
//    for(int i = 2; i <= eggs; i++)
//    {
//        for(int j = 2; j <= floors; j++)
//        {
//            result[i][j] = 0x7fffffff;
//            for(int x = 1; x <= floors; x++)
//            {
//                int temp = max(result[i - 1][x - 1], result[i][j - x]) + 1;
//                result[i][j] = min(result[i][j], temp);
//            }
//        }
//    }
//    return result[eggs][floors];
//}
//
//int main()
//{
//    while(scanf("%d %d", &eggs, &floors) != EOF)
//    {
//        cout << DroppingEggsPuzzle() << endl;
//    }
//    return 0;
//}

