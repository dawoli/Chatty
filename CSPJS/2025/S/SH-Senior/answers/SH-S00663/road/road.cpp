#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int num=1;
struct qwq{
	int l,r,v;
}e[2000009];
int fa[2000009];
vector<int> b[19];
bool cmp(qwq m,qwq n){
	return m.v<n.v;
}
int a[19][100009];
int f(int x){
	if(fa[x]!=x) return f(fa[x]);
	return x;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		cin>>e[i].l>>e[i].r>>e[i].v;
	}
	int pp;
	for(int i=1;i<=k;i++){
		cin>>pp;
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
			//cout<<a[i][j]<<endl;
		}
	}
	if(k==0){
		long long ans=0,cnt=0;
		sort(e+1,e+1+m+k*n,cmp);
		for(int i=1;i<=m;i++){
			int fl=f(e[i].l);
			int fr=f(e[i].r);
			if(fl!=fr){
				fa[fl]=fr;
				ans+=e[i].v;
				cnt++;
				if(cnt==n-1) break;
			}
		}
	}
	else{
		int ac=m;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=n;j++){
				e[++ac].v=a[i][j];
				e[ac].l=n+i;
				e[ac].r=j;
			}
		long long ans=0,cnt=0;
		sort(e+1,e+1+m+k*n,cmp);
		for(int i=1;i<=m+k*n;i++){
			if(e[i].l>n){
				b[e[i].l-n].push_back(i);
			}
			if(e[i].r>n){
				b[e[i].r-n].push_back(i);
			}
			int fl=f(e[i].l);
			int fr=f(e[i].r);
			if(fl!=fr){
				fa[fl]=fr;
				ans+=e[i].v;
				cnt++;
				if(cnt==n+k-1) break;
			}
			//cout<<e[i].l<<" "<<e[i].r<<" "<<ans<<endl;
		}
		for(int i=1;i<=k;i++){
			if(b[i].size()==1) ans-=b[i][0];
		}
		cout<<ans<<endl;
	}
	return 0;
}
