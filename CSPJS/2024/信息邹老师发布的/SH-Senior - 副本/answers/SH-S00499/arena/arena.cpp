#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define up(l,r,i) for(int i=(l);i<=(r);++i)

constexpr int N=1e5+7;

ll n,m,_a[N],c[N],a[N],x[9],winner[N];
string s[33];

void solve(){
	ll ans=0;
	up(1,m,i){
		if((ll)pow(2,(int)log2(c[i]))==c[i]){
			up(1,c[i],j)winner[j]=j;
			ll cnt=log2(c[i]);
			for(int j=cnt;j;--j){
				ll lim=pow(2,j-1);
				up(1,lim,k){
					int leizhu,moyu;
					if(s[j][k]==1)leizhu=winner[k*2],moyu=winner[k*2-1];
					else leizhu=winner[k*2-1],moyu=winner[k*2];
					if(a[leizhu]>=cnt-j+1)winner[k]=leizhu;
					else winner[k]=moyu;
				}
			}
			//cout<<winner[1]<<' ';
			ans^=(i*winner[1]); 
		}
		else continue;
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	ll k=ceil(log2(n));
	up(1,n,i)cin>>_a[i];
	up(1,m,i)cin>>c[i];
	for(int i=k;i;--i)cin>>s[i],s[i]=" "+s[i];
	int tc;cin>>tc;
	while(tc--){
		up(0,3,i)cin>>x[i];
		up(1,n,i)a[i]=(_a[i]^x[i%4]);
		solve();
	}
	return 0;
}

