#include<bits/stdc++.h>
#define N 100005
typedef long long ll;
using namespace std;
struct Member{
	ll a1,a2,a3;
}a[N];
bool cmpA(const Member&a,const Member&b){
	if(a.a1>b.a1) return 1;
	if(a.a1<b.a1) return 0;
	if(a.a2>b.a2) return 1;
	if(a.a2<b.a2) return 0;
	return a.a3>b.a3;
}
bool cmpB(const Member&a,const Member&b){
	if(a.a1-a.a2>b.a1-b.a2) return 1;
	if(a.a1-a.a2<b.a1-b.a2) return 0;
	return max(a.a1,a.a2)>max(b.a1,b.a2);
}
ll T,n,ans;
void dfs(ll x,ll x1,ll x2,ll x3,ll cnt){
	if(x>n){
		ans=max(ans,cnt);
		return;
	}
	if(x1<n/2) dfs(x+1,x1+1,x2,x3,cnt+a[x].a1);
	if(x2<n/2) dfs(x+1,x1,x2+1,x3,cnt+a[x].a2);
	if(x3<n/2) dfs(x+1,x1,x2,x3+1,cnt+a[x].a3);
}
void Solve1_4(){
	dfs(1,0,0,0,0);
	cout<<ans;
}
bool A(){
	for(ll i=1;i<=n;i++) if(a[i].a2!=0||a[i].a3!=0) return 0;
	return 1;
}
void SolveA(){
	sort(a+1,a+1+n,cmpA);
	for(ll i=1;i<=n/2;i++) ans+=a[i].a1;
	cout<<ans;
}
bool B(){
	for(ll i=1;i<=n;i++) if(a[i].a3!=0) return 0;
	return 1;
}
void SolveB(){
	sort(a+1,a+1+n,cmpB);
	for(ll i=1;i<=n/2;i++) ans+=a[i].a1+a[i+n/2].a2;
	cout<<ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n,ans=0;
		for(ll i=1;i<=n;i++) cin>>a[i].a1>>a[i].a2>>a[i].a3;
		if(n<=30) Solve1_4();			//20pts
		else if(A()) SolveA();			//5pts
		else if(B()) SolveB();			//15pts 
		cout<<"\n";
	}
	return 0;
}
