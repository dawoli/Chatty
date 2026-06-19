#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string s;
int a[1000005];
int pos;
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    cin >> s;
    s = " " + s;
    int len = s.size();
    for(int i=1;i<=len-1;i++)
    {
        if(s[i] - 48 >= 0 && s[i] - 48 <= 9)
        {
            a[++pos] = s[i] - 48;
        }
    }
    sort(a+1,a+pos+1,cmp);
    for(int i=1;i<= pos;i++)
    {

        cout << a[i];
    }


    return 0;
}
