#include<bits/stdc++.h>
using namespace std;
#define int long long
struct no{
	int u,v,w;
	bool operator<(no b)const{
		return w>b.w;
	}
};
int c[15];
int a[10110][15];
priority_queue<no>q;
int n,m,k;
no y,e[1110100];
int cur;
int b[10110];
int rx,ry;
int rt(int x){
	return b[x]==x?x:b[x]=rt(b[x]);
}
int cnt=0,ans=0;
void un(int x,int y,int w){
	if(x==y)return;
	rx=rt(x),ry=rt(y);
	if(rx==ry)return;
	cnt++;ans+=w;
	if(rx<ry)swap(x,y);
	b[rx]=ry;
}
int hb[15];
bool chkA(){
	for(int i = 1;i<=k;i++){
		if(c[i]!=0)return 0;
		bool fl=0;
		for(int j = 1;j<=n;j++)
			if(a[j][i]==0)fl=1,hb[i]=j;
		if(fl==0)return 0;
	}
	return 1;
}
void hbd(){
	for(int i = 1;i<=k;i++){
		for(int j = 1;j<=n;j++)
			if(hb[i]!=j)q.push({hb[i],j,a[j][i]});
	}
}

void krusc(){
	for(int i = 1;i<=n;i++)b[i]=i;
	cnt=ans=0;
	for(int i = 1;i<=m;i++){
		un(e[i].u,e[i].v,e[i].w);
		if(cnt==n-1)continue;
	}
	cout<<ans;
	
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i = 1;i<=m;i++){
		cin>>y.u>>y.v>>y.w;
		q.push(y);
	}
	for(int i = 1;i<=k;i++){
		cin>>c[i];
		for(int j = 1;j<=n;j++)
			cin>>a[j][i];
	}
	if(chkA())hbd();
	while(!q.empty())e[++cur]=q.top(),q.pop();
	if(k==0 or chkA())krusc();
	
	
}
