#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::clog;
using std::endl;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const int N=100009;
int x[N],n;
std::multiset <int> a;
int main()
{
	std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
//	freopen("F:\\CSP-S\\duel\\duel4.in","r",stdin);
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>x[i];
	std::sort(x+1,x+1+n);
	for(int i=n; i>=1+1; i--) a.insert(x[i]);
	int ans=n;
	for(int i=1; i<=n; i++)
	{
		while(!a.empty()&&*a.begin()<=x[i]) a.erase(a.begin());
		if(!a.empty()&&*a.begin()>x[i]) ans--,a.erase(a.begin());
	}
	cout<<ans<<endl;
	return 0;
}

