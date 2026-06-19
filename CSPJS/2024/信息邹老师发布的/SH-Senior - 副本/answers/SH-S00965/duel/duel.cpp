#include<bits/stdc++.h>
using namespace std;
#define int long long

const int MAXN=1e5+5;
int n;
int a[MAXN];
int cur=1;

signed main()
{
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		if(a[i]>a[cur]) cur++;
	cout<<n-cur+1;
}
