#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int a[1000010];

bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            cnt++;
            a[cnt]=s[i]-'0';
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout << a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
