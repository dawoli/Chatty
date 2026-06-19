#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int N=2e5+5,K=20;
int n,Q,aa[N],c[N],k,a[N],win[K][N];
int T,xx[4];
bool ok[N];
bool d[K][N];
vector<int> mea[K][N];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>n>>Q;
	for(int i=1;i<=n;i++)cin>>aa[i];
	for(int i=1;i<=Q;i++)cin>>c[i];
	while((1<<k)<n)k++;
	char ch;
	for(int i=1;i<=k;i++)
		for(int j=1;j<=1<<(k-i);j++){
			cin>>ch;
			if(ch=='1')d[i][j]=1;
		}
	while(T--){
		cin>>xx[0]>>xx[1]>>xx[2]>>xx[3];
		for(int i=1;i<=n;i++)a[i]=aa[i]^xx[(i&1)+(i&2)];
		int res=0,ans=0;
		for(int qw=1;qw<=Q;qw++){
			int kk=0;
//			cout<<c[qw]<<'\n';
//			return 0;
			while((1<<kk)<c[qw])kk++;
//	return 0;
			for(int i=1;i<=(1<<kk);i++)ok[i]=1;
			for(int i=1;i<=(1<<kk);i++)mea[0][i].pb(i);
			for(int i=1;i<=kk;i++){
				for(int j=1;j<=1<<(kk-i);j++){
					if(!d[i][j]){
						bool flg=0;
						for(auto x:mea[i-1][(j<<1)-1]){
							if(x>=i)mea[i][j].pb(x);
							if(x<i && !flg){
								for(auto y:mea[i-1][j<<1]){
									mea[i][j].pb(y);
								}
								flg=1;
							}
						}
					}
					else{
						bool flg=0;
						for(auto x:mea[i-1][(j<<1)]){
							if(x>=i)mea[i][j].pb(x);
							if(x<i && !flg){
								for(auto y:mea[i-1][(j<<1)-1]){
									mea[i][j].pb(y);
								}
								flg=1;
							}
						}
					}
				}
			}
			for(auto x:mea[kk][1]){
				res+=x;
			}
			for(int i=1;i<=kk;i++)
				for(int j=1;j<=1<<(kk-i);j++)
					mea[i][j].clear();
			for(int i=1;i<=(1<<kk);i++)mea[0][i].clear();
			ans^=res*qw;
			res=0;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
