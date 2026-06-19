#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int T,n,lim,q,a[2*N],l[N],r[N],pos[2*N],len,rq[N],cq[N],maxn,maxcol,now[2*N];
bool f[109][2*N],ans[109][2*N];
void solve(){
	maxcol=0;len=0;
	cin>>n>>lim>>q;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		l[i]=len+1;r[i]=len+x;len+=x;
		for(int j=l[i];j<=r[i];j++){
			cin>>a[j];
			maxcol=max(maxcol,a[j]);
			pos[j]=i;
		}
	}
	maxn=0;
	for(int i=0;i<=2e5;i++) now[i]=-1;
	for(int i=1;i<=q;i++) cin>>rq[i]>>cq[i],maxn=max(maxn,rq[i]);
	for(int i=1;i<=maxn+1;i++){
		for(int j=1;j<=2e5;j++) now[j]=-1;
		if(i==1) now[1]=0;
		else {
			for(int j=1;j<=len;j++)
				if(f[i-1][j]){
					if(now[a[j]]==-1) now[a[j]]=pos[j];
					else if(now[a[j]]!=pos[j]) now[a[j]]=0;
				}
		}
		for(int j=1;j<=2e5;j++){
			if(now[j]!=-1) ans[i-1][j]=1;
			else ans[i-1][j]=0;
		}
		if(i>maxn) break;
		for(int j=1;j<=n;j++){
			int num=0;
			f[i][l[j]]=0;
			for(int k=l[j]+1;k<=r[j];k++){
				int col=a[k-1];
				if(now[col]==0||(now[col]!=-1&&now[col]!=j)) num++;
				if(k-l[j]+1>lim){
					col=a[k-lim];
					if(now[col]==0||(now[col]!=-1&&now[col]!=j)) num--;
				}
				if(num>0) f[i][k]=1;
				else f[i][k]=0;
			}
		}
	}
	for(int i=1;i<=q;i++) cout<<ans[rq[i]][cq[i]]<<'\n';
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--) solve();
	return 0;
}
