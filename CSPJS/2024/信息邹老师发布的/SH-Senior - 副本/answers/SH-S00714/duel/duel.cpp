#include<bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define Rep(i,a,b) for(ll i=(b);i>=(a);--i)
#define all(x) x.begin(),x.end()
#define cll const ll
#define Set(x,y) memset(x,y,sizeof(x))
#define Cpy(x,y) memcpy(x,y,sizeof(x))
using namespace std;
cll N=100009;
ll r[N],n;
void solve2(){
	ll c1=0,c2=0;rep(i,1,n)if(r[i]==1)c1++;else c2++;
	cout<<max(c1,c2)<<endl;
}
ll cnt[N];
void solve(){
	rep(i,1,n)cnt[r[i]]++;
	cout<<*max_element(cnt+1,cnt+1+r[n])<<endl;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;rep(i,1,n)cin>>r[i];
	sort(r+1,r+1+n);
	if(r[n]<=2)solve2();
	else solve();
	return 0;
}
