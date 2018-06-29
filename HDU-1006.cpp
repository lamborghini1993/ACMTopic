#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double degree;
struct Interval
{
    double left;
    double right;
};

Interval Intersection2(Interval A, Interval B)
{
    Interval N = {0,0};
    if(A.right <= B.left || B.right <= A.left)
        return N;
    A.left = max(B.left, A.left);
    A.right = min(B.right, A.right);
    if(A.left>A.right)
        return N;
    return A;
}

Interval Intersection3(Interval A, Interval B, Interval T)
{
    return Intersection2(Intersection2(A, B), T);
}

/*
��� degree<=|kx+b|<=360 - degree
(kx + b) >= degree =>  x>=(degree - b) / k      A
(kx + b) <= -degree =>  x<=(-degree - b) / k    B
(degree - 360) <= (kx + b) <= (360 - degree)    C
D = [0, 60]
(A | B) & C & D
*/
void Slove(double k, double b, Interval *tmp)
{
    Interval A, B, C;
    A.left = (degree - b) / k;
    A.right = 60;

    B.left = 0;
    B.right = (-degree - b) / k;

    C.left = (degree - 360 - b) / k;
    C.right = (360 - degree - b) / k;

    Interval T = {0, 60};

    tmp[0] = Intersection3(A, C, T);
    tmp[1] = Intersection3(B, C, T);
}

/*
ʱ��-���룺  360/12*(h+m/60+x/3600)-360/60*(m+x/60)
            = 30h-11/2*m-11/120*x    (ȡ��������x��ϵ��Ϊ������ΪҪȡ����ֵ���Խ��һ��)
            = 11/120*x-30h+11/2*m

ʱ��-����:  360/12*(h+m/60+x/3600)-360/60*x
            = 719/120*x - 30h - 1/2m

����-����:  360/60*x-360/60*(m+x/60)
            = 59/10*x - 6m
*/
double HappyTime(int hh, int mm)
{
    Interval result[3][2];
    Slove(11.0 / 120, -30.0 * hh + 11.0 / 2 * mm, result[0]);//ʱ��ͷ�������Ҫ��Ľ�
    Slove(719.0 / 120, -30.0 * hh - 1.0 / 2 * mm, result[1]);//ʱ��ͷ�������Ҫ��Ľ�
    Slove(59.0 / 10, -6.0 * mm, result[2]);//�������������Ҫ��Ľ�
    double sum = 0;
    /* ��������󽻼�
    (A|B)&(C|D)&(E|F) = A&C&E + A&C&F + .. // ���ڰ���������
    */
    for(int x = 0; x < 2; x++)
    {
        for(int y = 0; y < 2; y++)
        {
            for(int z = 0; z < 2; z++)
            {
                Interval T = Intersection3(result[0][x], result[1][y], result[2][z]);
                sum += T.right - T.left;
            }
        }
    }
    return sum;
}

int main()
{
    while(scanf("%lf", &degree) && degree >= 0)
    {
        double happytime = 0;
        for(int hh = 0; hh < 12; hh++)
        {
            for(int mm = 0; mm < 60; mm++)
            {
                double result = HappyTime(hh, mm);
                happytime += result;
            }
        }
        printf("%.3lf\n", happytime * 100 / (12 * 60 * 60));
    }
    return 0;
}
