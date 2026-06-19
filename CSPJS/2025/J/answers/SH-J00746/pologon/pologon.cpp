#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int pow(int t)
{
    int res=1;
    for(int i=1;i<=t;i++)
        res=(res*2)%MOD;
    return res;
}
int main()
{
    freopen("pologon.in","r",stdin);
    freopen("pologon.out","w",stdout);
    int a,s[5005],lg[5005],cnt=0;
    cin >> a;
    if(a==3)
    {
    	int x,y,z;
    	cin >>x>>y>>z;
    	int m=max(x,y);
    	m=max(m,z);
    	if(x+y+z>2*m)
    	{
    		cout << 1;
		}
		else
		{
			cout << 0;
		}
		return 0;
	}
    for(int i=1;i<=a;i++)
    {
        cin >> s[i];
        lg[s[i]]++;
    }
    if(a<=20)
    {
		for(int i=1;i<=pow(20);i++)
    	{
    		int maxi=-1,sum=0,c=0;
			for(int j=20;j>=1;j--)
    		{
    			if(i%2==1)
    			{
    				maxi=max(maxi,s[i]);
    				sum+=s[i];
    				c++;
				}
			}
			if(c>=3&&sum>2*maxi)
				cnt++;
		}
		cout<<cnt;
		return 0;
	}
    if(lg[1]==a)
    {
        cout <<(res-1-a*(a-1)/2)%MOD;
        return 0;
    }
    return 0;
}
