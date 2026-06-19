#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5,M=1e6+5;
int T,n,a[N];
ll f[M];
inline void read(int &ret){
	ret=0; int ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch))
		ret=ret*10+(ch^48),ch=getchar();
}
priority_queue<pair<ll,int>> pq;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		while(!pq.empty()) pq.pop();
		for(int i=1;i<=n;++i) read(a[i]);
		int m=*max_element(a+1,a+n+1);
		for(int i=1;i<=m;++i) f[i]=-1e18;
		ll tag=0; f[0]=0; pq.push(make_pair(0ll,0));
		for(int i=1;i<=n;++i){
			int dt=(a[i]==a[i-1])*a[i]; tag+=dt;
			while(!pq.empty()&&f[pq.top().second]!=pq.top().first) pq.pop();
			ll res=pq.top().first-dt;
			res=max(res,f[a[i]]-dt+a[i]);
			f[a[i-1]]=max(f[a[i-1]],res);
			pq.push(make_pair(f[a[i-1]],a[i-1]));
		}
		printf("%lld\n",*max_element(f,f+m+1)+tag);
	}
	return 0;
} 
