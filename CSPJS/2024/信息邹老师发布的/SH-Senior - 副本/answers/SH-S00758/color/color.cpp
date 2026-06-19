#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb emplace_back
using namespace std;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
// #define rand(x,y) uniform_int_distribution<int>(x,y)(rng)

const int N=2e5+5,M=1e6+5;
int n,a[N];
ll f[N],lst[N];
unordered_map<int,int> lv;
ll s[N];
void work(){
	int i;
	cin>>n;
	for(i=0;i<=n+1;i++) f[i]=lst[i]=a[i]=s[i]=0;
	lv.clear();
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		lst[i]=lv[a[i]];
		lv[a[i]]=i;
		if(a[i]==a[i-1]) s[i]=a[i];
		s[i]+=s[i-1];
	}
	for(i=1;i<=n;i++){
		f[i]=f[i-1];
		if(lst[i]){
			if(lst[i]==i-1) f[i]=max(f[i],f[i-1]+a[i]);
			else f[i]=max(f[i],f[lst[i]+1]+a[i]+s[i-1]-s[lst[i]+1]);
		}
	}
	cout<<f[n]<<'\n';
}
signed main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	int _;cin>>_;while(_--) work();
	return 0;
}
