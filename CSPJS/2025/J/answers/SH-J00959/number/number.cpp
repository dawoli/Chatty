#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

char a[1000010];
bool cmp(int x,int y)
{
    return x>y;
}

int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int cnt=0;
    int t=s.size()-1;
    for(int i=0;i<=t;i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            cnt++;
            a[cnt]=s[i];
        }
    }
    sort(a+1,a+cnt+1,cmp);
    for(int i=1;i<=cnt;i++)
    {
        cout<<a[i];
    }
    return 0;
}
