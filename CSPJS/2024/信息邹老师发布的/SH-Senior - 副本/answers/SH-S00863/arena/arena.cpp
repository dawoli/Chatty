#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,m,rawA[100009],c[100009],K,x[4],a[100009];
bool d[20][200009],istypeA=1;
namespace solA{
	ll ans,mxc,win[20][200009];
	void solve(){
		for(int i=1;i<=m;i++) mxc=max(mxc,c[i]);
		for(int i=1;i<=mxc;i++) win[0][i]=i;
		for(int i=1;(1<<i)<=mxc;i++){
			for(int j=1;j<=mxc/(1<<i);j++){
				if(d[i][j]){
					win[i][j]=(a[win[i-1][j<<1]]>=i?win[i-1][j<<1]:win[i-1][(j<<1)-1]);
				}else{
					win[i][j]=(a[win[i-1][(j<<1)-1]]>=i?win[i-1][(j<<1)-1]:win[i-1][j<<1]);
				}
				//cout<<i<<' '<<j<<' '<<d[i][j]<<' '<<win[i][j]<<endl;
			}
		}
		for(int i=1;i<=m;i++){
			int tmp1,tmp2=-1;
			tmp1=c[i];
			while(tmp1) {
				tmp2++;
				tmp1/=2;
			}
			ans^=i*win[tmp2][1];
			//cout<<c[i]<<' '<<win[tmp2][1]<<endl;
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	int tmp;
	tmp=n;
	while(tmp) {
		K++;
		tmp/=2;
	}
	for(int i=1;i<=n;i++) cin>>rawA[i];
	for(int i=1;i<=m;i++){
		cin>>c[i];
		tmp=c[i];
		while(tmp>1&&istypeA){
			if(tmp%2) istypeA=0;
			else tmp/=2;
		}
	} 
	char c;
	for(int i=1;i<=K;i++){
		for(int j=1;j<=(1<<(K-i));j++){
			cin>>c;
			d[i][j]=(c=='1');
		}
	}
	cin>>T;
	while(T--){
		cin>>x[0]>>x[1]>>x[2]>>x[3];
		for(int i=1;i<=n;i++) a[i]=rawA[i]^x[i%4];
		//for(int i=1;i<=n;i++) cout<<a[i]<<' ';
		//cout<<"==="<<endl;
		if(istypeA) solA::solve();
	}
	return 0;
}

