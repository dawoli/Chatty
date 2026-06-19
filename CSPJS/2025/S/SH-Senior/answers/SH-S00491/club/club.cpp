#include<bits/stdc++.h>
using namespace std;
#define sc cerr
#define qlog(a) {sc<<#a<<"="<<a<<"\n";}
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define qloga(a,l,r) {sc<<#a<<" : ";rep(I,l,r){sc<<a[I]<<" ";}sc<<"\n";}
#define qlogSTL(a) {sc<<#a<<" : ";for(auto I:a){sc<<I<<" ";}sc<<"\n";}
typedef long long ll;

#define int ll
const int N=1e5+10;
ll n,a[N][3];
ll lft[N];
int c[10];

ll tanxin(){
	for(int i=0;i<10;i++)c[i]=0;

	rep(i,1,n){
		if(a[i][0]==a[i][1] &&a[i][0]==a[i][2])continue; //不管了

		int j=max_element(a[i],a[i]+3)-a[i];
		if((a[i][0]==a[i][j])+(a[i][1]==a[i][j])+(a[i][2]==a[i][j])==2){
			if(a[i][0]!=a[i][j])j=0;	
			else if(a[i][1]!=a[i][j])j=1;
			else j=2;

			c[7-(1<<j)]++;
		}
		c[1<<j]++;
	}
	while(c[1+2]--){
		if(c[1]<n/2)c[1]++;
		else c[2]++;
	}
	while(c[1+4]--){
		if(c[1]<n/2)c[1]++;
		else c[4]++;
	}
	while(c[2+4]--){
		if(c[2]<n/2)c[2]++;
		else c[4]++;
	}
	if(c[1]>n/2)return -1;
	if(c[2]>n/2)return -1;
	if(c[4]>n/2)return -1;
	ll ans=0;
	rep(i,1,n)ans+=max(max(a[i][0],a[i][1]),a[i][2]);
	return ans;
}
ll fxsolve(int r){
	ll sum=0;
	rep(i,1,n)sum+=a[i][r];

	rep(i,1,n){
		if(r==0)lft[i]=max(a[i][1],a[i][2]);
		if(r==1)lft[i]=max(a[i][0],a[i][2]);
		if(r==2)lft[i]=max(a[i][0],a[i][1]);
		lft[i]-=a[i][r];
	}
	sort(lft+1,lft+1+n,greater<ll>());
	for(int i=1;i<=n/2;i++)sum+=lft[i];
	return sum;
}

ll solve(){
	cin>>n;
	rep(i,1,n)rep(j,0,2)cin>>a[i][j];

	
	ll Sol1=tanxin();
	if(Sol1!=-1)return Sol1;
	ll fx0 = fxsolve(0);
	ll fx1 = fxsolve(1);
	ll fx2 = fxsolve(2);
	return max(max(fx0,fx1),fx2);
}

signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0); cin.tie(0);

	int T; cin>>T;
	while(T--){
		cout<<solve()<<"\n";
	}
}
