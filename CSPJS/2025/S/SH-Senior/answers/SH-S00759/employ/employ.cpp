#include<bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define ld long double
#define ull unsigned long long
#define cll const long long
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
cll N=509; ll n,a[N],s[N],m;
void work(){
	cin>>n>>m;
	rep(i,1,n){char c;cin>>c;s[i]=c-48;}
	rep(i,1,n)cin>>a[i];
	ll p[18],ans=0; bool lv[18]; rep(i,1,n)p[i]=i;
	do{
		ll nheLv=0;
		rep(i,1,n)lv[i]=0;
		rep(i,1,n){
			rep(j,i,n)if(nheLv>=a[p[j]]&&!lv[j])nheLv++,lv[j]=1;
			if(!lv[i])nheLv+=!s[i],lv[i]=!s[i];
		}
		if(nheLv<=n-m)ans++;
	}while(next_permutation(p+1,p+1+n));
	cout<<ans<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	ll T=1;//cin>>T;
	while(T--)work();
	return 0;
}

