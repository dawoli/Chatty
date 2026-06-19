#include<bits/stdc++.h>
using namespace std;
string s;
int a[100005];

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s; 
    int cnt=1;
    int sl=s.size();
    for(int i=1;i<=sl+1;i++)
    {
        if('0'<=s[i-1]&&s[i-1]<='9')
        {
            a[cnt]=s[i-1]-'0';
            cnt++;
        }
    }
    sort(a+1,a+cnt);
    for(int i=cnt-1;i>=1;i--)
    {
        cout<<a[i];
    }
    cout<<"\n";
    return 0;
}
