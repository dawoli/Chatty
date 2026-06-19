#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=1e5+5;
int n,a[MAXN];

signed main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=1;
	while(r<=n)
	{
		while(a[r]==a[l]&&r<=n)
			++r;
		if(r>n)
			break;
		++l;
		++r;
	}
	cout<<n-l+1;
	return 0;
}
