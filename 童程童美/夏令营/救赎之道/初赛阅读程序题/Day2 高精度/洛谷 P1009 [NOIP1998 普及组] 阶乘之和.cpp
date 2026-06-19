#include<bits/stdc++.h>
using namespace std;
#define N 105
void setLen(int a[], int i)
{
	while(a[i] == 0 && i > 1)
		i--;
	a[0] = i;
} 
void Multiply(int a[], int b)
{
    int c = 0, i;
    for(i = 1; i <= a[0]; ++i)
    {
        a[i] = a[i]*b + c;
        c = a[i] / 10;
        a[i] %= 10; 
    }
    while(c > 0)
    {
        a[i] = c % 10;
        c /= 10;
        i++;
    }
   	setLen(a, i);
}
void Add(int a[], int b[])
{
    int c = 0, i;
    for(i = 1; i <= a[0] || i <= b[0]; ++i)
    {
        a[i] += b[i] + c;
        c = a[i] / 10;
        a[i] %= 10;
    }
    if(c > 0)
        a[i] = c;
    setLen(a, i);
}
void showNum(int a[])
{
    for(int i = a[0]; i >= 1; --i)
        cout << a[i];
}
int main()
{
    int a[N] = {1, 1}, s[N] = {1, 0}, n; 
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        Multiply(a, i);
        Add(s, a);
    }
    showNum(s);
    return 0;
}
