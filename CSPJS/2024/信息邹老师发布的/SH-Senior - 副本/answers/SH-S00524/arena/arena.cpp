#include<bits/stdc++.h>
using namespace std;
const int N=131075;
long long ans[N];
int win[20][N];
int a[N];
char c[20][N];
bool con[N];
int ask[N];
int dg(int k,int idx){
	cout<<k<<" "<<idx<<"\n";
	if(k==1) return idx;
	int u=dg(k-1,idx*2-1),v=dg(k-1,idx*2);
	if(c[k-1][idx]=='0'){
		if(a[u]>=k-1) return u;
		return v;
	}
	else {
		if(a[v]>=k-1) return v;
		return u;
	}
	return 0;
}
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>ask[i];
	int k=ceil(log2(n));
	for(int i=1;i<=k;i++) cin>>c[i]+1;
	int T;
	cin>>T;
	while(T--){
		int x[4];
		for(int i=0;i<4;i++) cin>>x[i];
		for(int i=1;i<=n;i++) a[i]^=x[i%4];
		long long ans=0;
		for(int j=1;j<=m;j++){
			ans^=(long long)j*dg((int)(log2(ask[j])),1);
		}
		cout<<ans<<"\n";
		/*
		int p=1,tn=1;
		long long tot=1;
		for(int j=1;j<=n;j++){
			if(j>p){
				p<<=1;tn++;
				if(c[tn][1]=='0' && a[win[tn-1][1]]>=tn){
					for(int i=j;i<=p;i++) ans[i]=win[tn-1][1];
					j=p;
					continue;
				}
			}
			int idx=j,rank=j;
			for(int r=1;r<=p;r++){
				if(idx%2==1 && c[r][idx+1>>1]=='1'){
					ans[j]=
				}
				if(idx%2==0){
					if(c[r][idx+1>>1]=='1' && a[j]<r){
						idx=win[r][idx-1];
						continue;
					}
					if(c[r][idx+1>>1]=='1' && a[j]>=r){
						tot-=win[r][idx-1];
						idx=idx+1>>1;
						continue;
					}
				}
				if(c[r][idx+1>>1]=='0')
			}
		}
		*/
		
		for(int i=1;i<=n;i++) a[i]^=x[i%4];
	}
	return 0;
}
