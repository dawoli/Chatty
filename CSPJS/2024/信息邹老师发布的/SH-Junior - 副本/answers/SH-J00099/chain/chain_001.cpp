#include<bits/stdc++.h>
using namespace std;
#define ll int
#define N 200009
ll T,n,k,q,r[N],c[N],l[N],op,suml,mxr;
vector<ll>s[N];

bool all1(){
	for(ll i=1;i<=q;i++)if(r[i]!=1){
		return 0;
	}
	return 1;
}
bool r1s[N];ll r1;
void sol1(){
	for(ll i=1;i<=n;i++){
		r1=0;
		for(ll j=1;j<=l[i];j++){
			if(r1)r1s[s[i][j]]=1,r1--;
			if(s[i][j]==1)r1=max(r1,k-1);
		}		
	}
	for(ll i=1;i<=q;i++){
		if(r1s[c[i]])cout<<"1\n";
		else cout<<"0\n";
	}
}
ll ans2;
void dfs(ll i,ll j,ll d,bool p,ll cx){
	if(ans2)return;
	if(!d){
		if(s[i][j]==cx)ans2=1;
		return;
	}
	if(p)for(ll k1=j+1;k1<=l[i]&&k1<=j+k-1;k1++)dfs(i,k1,d-1,0,cx);
	else for(ll k1=1;k1<=n;k1++)if(i!=k1)for(ll k2=1;k2<=l[k1];k2++)
		if(s[k1][k2]==s[i][j])dfs(k1,k2,d,1,cx);
}
void sol2(){
	for(ll i=1;i<=q;i++){
		ans2=0;
		for(ll j=1;j<=n;j++){
			for(ll j1=1;j1<=l[j];j1++)
				if(ans2)break;
				else if(s[j][j1]==1)dfs(j,j1,r[i],1,c[i]);
		}
		cout<<ans2<<"\n";
	}
}
void solp(){
	for(ll i=1;i<=q;i++)cout<<"0\n";//..............
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k>>q;
		suml=0;
		for(ll i=1;i<=n;i++){
			s[i].clear();
			cin>>l[i];
			suml+=l[i];
			s[i].push_back(0);
			for(ll j=1;j<=l[i];j++){
				cin>>op;
				s[i].push_back(op);
			}
		}
		for(ll i=1;i<=q;i++){
			cin>>r[i]>>c[i];
			mxr=max(mxr,r[i]);
		}
		if(all1()&&n<=1000&&q<=1000&&suml<=2000)sol1();
		else if(n*q<=100000000)sol2();
		else solp();
	}
	return 0;
} 
