#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=505;
int a[N],x[N];
bool f[N];
int ans=0;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		f[i]=c-'0';
		sum+=f[i];
	}
	if(sum<m)
	{
		cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) x[i]=i;
	int ans=0;
	do{
		int dead=0,suc=0;
		for(int i=1;i<=n;i++)
		{
			if(dead>=a[x[i]]) dead++;
			else if(f[i]) suc++;
			else dead++;
		}
		if(suc>=m) ans++;
		ans%=998244353;
	}while(next_permutation(x+1,x+n+1));
	cout<<ans<<endl;
	return 0;
}

