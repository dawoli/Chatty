#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,ans;
string s;
struct people
{
	int c,i;
}a[505];
bool cmp(people x,people y)
{
	return x.i<y.i;
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	if (n<=18)
	{
		for (int i=1;i<=n;i++)
		{
			cin>>a[i].c;
			a[i].i=i;
		}
		do
		{
			int f=0;
			for (int i=1;i<=n;i++)
			{
				if (s[i-1]=='0'||f>=a[i].c)
					f++;
			}
			if (n-f>=m)
				ans++;
			ans%=mod;
		} while(next_permutation(a+1,a+n+1,cmp));
		cout<<ans;
	}
	else
	{
		for (int i=1;i<=n;i++)
			ans=(ans*i)%mod;
		cout<<ans;
	}
 } 
