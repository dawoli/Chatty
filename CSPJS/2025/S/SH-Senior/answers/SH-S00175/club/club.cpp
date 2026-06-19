#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=100009;
struct Member{
	ll a,b,c;
} a[N];
ll t,n;
bool A(){
	for(ll i=1;i<=n;i++)if(a[i].b+a[i].c!=0)return false;
	return true;
}
bool B(){
	for(ll i=1;i<=n;i++)if(a[i].c!=0)return false;
	return true;
}
bool cmpA(const Member&a,const Member&b){
	if(a.a!=b.a)return a.a>b.a; //reverse sort
	return a.b>b.b;
}
bool cmpB(const Member&a,const Member&b){
	ll deltaA=a.a-a.b;
	ll deltaB=b.a-b.b;
	if(deltaA!=deltaB)return deltaA>deltaB;
	else if(deltaA>=0)return a.a>b.a;
	else return a.b>b.b;
}
void dfs(vector<ll>clubs,ll member,ll&ans){   //0=>A 1=>B 2=>C
	if(member==n){
		ll cntA=0,cntB=0,cntC=0;
		for(ll i=0;i<member;i++){
			if(clubs[i]==0)cntA++;
			if(clubs[i]==1)cntB++;
			if(clubs[i]==2)cntC++;
			if(cntA>n/2||cntB>n/2||cntC>n/2)return;
		}
		if(cntA>n/2||cntB>n/2||cntC>n/2)return;
		ll t=0;
		for(ll i=0;i<member;i++)
			if(clubs[i]==0)t+=a[i+1].a;
			else if(clubs[i]==1)t+=a[i+1].b;
			else t+=a[i+1].c;
		ans=max(ans,t);
		return;
	}
	for(ll j=0;j<3;j++){
		clubs[member]=j;
		dfs(clubs,member+1,ans);
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
    	cin>>n;
    	for(ll i=1;i<=n;i++)cin>>a[i].a>>a[i].b>>a[i].c;
    	if(A()){
    		ll ans=0;
    		sort(a+1,a+1+n,cmpA);
    		for(ll i=1;i<=n/2;i++)ans+=a[i].a;
    		cout<<ans<<endl;
		}
		else if(n<=30){
			ll ans=0;
			vector<ll>clubs(19);
			dfs(clubs,0,ans);
			cout<<ans<<endl;
		} //25
		else if(B()){
			ll ans1=0;
			sort(a+1,a+1+n,cmpB);
			for(ll i=1;i<=n/2;i++)ans1+=a[i].a;
			for(ll i=n/2+1;i<=n;i++)ans1+=a[i].b;
			for(ll i=1;i<=n;i++)swap(a[i].a,a[i].b);
			ll ans2=0;
			sort(a+1,a+1+n,cmpB);
			for(ll i=1;i<=n/2;i++)ans2+=a[i].a;
			for(ll i=n/2+1;i<=n;i++)ans2+=a[i].b;
			cout<<max(ans1,ans2)<<endl;
		}
	}
    return 0;
}
