#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int a[1000010];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
	string s;
    cin >> s;
    int size = 0;
    for (int i = 0;i < s.size();i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
           	size++;
           	a[size] = s[i] - '0';
        }
    }
    sort(a+1,a+size+1);
    for (int i = size;i >= 1;i--)
    {
        cout << a[i];
    }
    return 0;
}
