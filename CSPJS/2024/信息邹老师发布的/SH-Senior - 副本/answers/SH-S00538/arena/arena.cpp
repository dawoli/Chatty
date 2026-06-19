#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
int ans[200005];
int c[200005];
int d[20][200005];
int win[20][200005];
int lg[200005];
int modif[4];
int k;
void solve(){
	for(int i=1;i<=n;i++) win[0][i]=i;
	for(int r=1;r<=k;r++){
		for(int i=1;i<=(1<<(k-r));i++){
			int ll=win[r-1][i*2-1];
			int rr=win[r-1][i*2];
			if(d[r][i]==1){
				if(a[rr]<r) win[r][i]=ll;
				else win[r][i]=rr;
			}else{
				if(a[ll]<r) win[r][i]=rr;
				else win[r][i]=ll;
			}
		}
	}
	int res=0;
	for(int i=1;i<=m;i++){
		res=res^(win[lg[c[i]]][1]*i);
	}
	cout<<res<<endl;
}
signed main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>c[i];
	for(int i=1;i<=n;i++){
		for(int kk=0;kk<=20;kk++){
			if((1<<kk)>=i){
				lg[i]=kk;
				break;
			}
		}
	}
	k=lg[n];
	for(int i=1;i<=k;i++){
		for(int j=1;j<=(1<<(k-i));j++){
			char x;
			cin>>x;
			if(x=='1') d[i][j]=1;
		}
	}
	int t;
	cin>>t;
	while(t--){
		cin>>modif[0]>>modif[1]>>modif[2]>>modif[3];
		for(int i=1;i<=n;i++){
			a[i]=a[i]^modif[i%4];
		}
		solve();
		for(int i=1;i<=n;i++){
			a[i]=a[i]^modif[i%4];
		}
	}
	return 0;
} 
