#include <algorithm>
#include <iostream>
using namespace std;

bool cmp(int a, int b)	//cmp函数，确定sort函数排序的规则
{    
    return a > b;
}

int gcd(int num[], int n)   //求多个数的最大公约数的算法
{
    sort(num, num + n, cmp);
    while (num[0] != num[n - 1])
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (num[i] % num[i + 1] == 0)
                num[i] = num[i + 1];
            else
                num[i] = num[i] % num[i + 1];
        }
        sort(num, num + n, cmp);
    }
    return num[0];
}

int main()
{
    int a[8] = { 32,16,12,24,36,20,40,28 }; //最大公约数：4
    int L = sizeof(a) / sizeof(int);        //L为元素个数
    cout << gcd(a, L);      				//输出最大公约数：4
    return 0;
}

