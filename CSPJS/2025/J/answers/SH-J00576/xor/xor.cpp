#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+9;
ll n,m,a[N],s[N]; 
map<ll,ll> mp;
struct Node{
	ll l,r;
}Bef[N],Aft[N];
bool cmp(const Node&p,const Node&q){
	return p.l<q.l;
}
ll cntBe,cntAf;
//RP++ 愿星族点亮你前行的道路 
//CCF太强了 
//luogu 663291
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) s[i]=(s[i-1]^a[i]);
	for(int i=n;i>=0;i--){
		if(mp[(s[i]^m)]){
			cntBe++;
			Bef[cntBe].r=mp[(s[i]^m)];
			Bef[cntBe].l=i+1;
		}
		mp[s[i]]=i;
	}
	sort(Bef+1,Bef+1+cntBe,cmp);
	for(int i=cntBe;i>=1;i--)
		if((!cntAf)||Bef[i].r<Aft[cntAf].r){
			cntAf++;
			Aft[cntAf].l=Bef[i].l;
			Aft[cntAf].r=Bef[i].r;
		}
	sort(Aft+1,Aft+1+cntAf,cmp);
	ll Ans=0,R=0;
	for(int i=1;i<=cntAf;i++){
		if(Aft[i].l>=R){
			Ans++;
			R=Aft[i].r+1;
		}
	}
	cout<<Ans<<endl;
	return 0;
}

