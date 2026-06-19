#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b)
{
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,a[100005];
    int sum=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[i]=s[i];
            sum++;
        }
        else if(s[i]>='a'&&s[i]<='z')continue;
    }
    sort(a,a+s.size(),cmp);
    for(int i=0;i<sum;i++)cout<<a[i];
    return 0;
}

