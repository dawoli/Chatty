#include<iostream>
#include<map>
#include<cstdio>
using namespace std;
map<string,bool> mp;
char a[15]={' ','A','2','3','4','5','6','7','8','9','T','J','Q','K'};
char b[5]={' ','D','C','H','S'};
int main()
{
    freopen("poker.in","r",stdin);
    freopen("poker.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
    {
        string s;
        cin>>s;
        mp[s]=1;
    }
    int cnt=0;
    for(int i = 1;i<=4;i++)
    {
        for(int j = 1;j <= 13;j++)
        {
            string s="";
            s+=b[i];
            s+=a[j];
            if(mp[s]==0)cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
