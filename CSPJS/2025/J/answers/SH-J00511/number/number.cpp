#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int cnt=0;
    string s;
    int a[1000005];
    getline(cin,s);
    for (int i=0;i<s.size();i++)
    {
        if(s[i]>='0'&&s[i]<='9')
        {
            a[cnt]=s[i]-'0';
            //cout<<a[cnt];
            cnt++;
        }
    }

    sort(a,a+cnt);
    //cout<<endl<<cnt<<endl;
    for(int i=cnt-1;i>=0;i--)
    {
        cout<<a[i];
    }

    return 0;
}
