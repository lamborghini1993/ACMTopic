#include <iostream>
#include <stack>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;


int LargestRectangleArea(vector<int> &height)
{
    height.push_back(0);//为了统计，数组最后添加0，确保原数组的最后一位得到计算
    stack<int> s;
    int LargestArea = 0;
    int temp, i = 0;
    while(i < (int)height.size())
    {
        if(s.empty() || (height[i] > height[s.top()]))
        {
            s.push(i);
            i++;
        }
        else
        {
            temp = s.top();
            s.pop();
            LargestArea = max(LargestArea, height[temp] * (s.empty() ? i : i - s.top() - 1));
        }
    }
    return LargestArea;
}
int main()
{
    int a[] = {2,1,5,6,2,3};
    vector<int> height(a, a + sizeof(a) / sizeof(int));
    cout << LargestRectangleArea(height) << endl;
    return 0;
}
