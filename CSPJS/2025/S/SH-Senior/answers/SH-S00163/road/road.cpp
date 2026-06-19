#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
struct node{
	int u,v,w;
};
bool cmp(const node &a,const node &b){
	return a.w<b.w;
}
int n,m,k;
bool vis[1000005];
vector<node> ve;
int a[1000005][12];
int c[1000009],fa[1000009];
int find(int x){
	if(fa[x]==x)
		return x;
	return fa[x]=find(fa[x]);
}
void solve1(){
	sort(ve.begin(),ve.end(),cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int ans=0,cnt=0;
	for(auto p:ve){
		if(cnt==n-1)
			break;
		if(find(p.u)==find(p.v))
			continue;
		else{
			fa[find(p.u)]=find(p.v);
			ans+=p.w;
			vis[p.u]=vis[p.v]=true;
			cnt++;
		}
	}
	cout<<ans;
}
void solve2(){
	for(int i=1;i<=k;i++)
		for(int j=1;j<n;j++)
			for(int kk=j+1;kk<=n;kk++)
				ve.push_back({j,kk,a[i][j]+a[i][kk]});
	sort(ve.begin(),ve.end(),cmp);
	for(int i=1;i<=n;i++)
		fa[i]=i;
	int ans=0,cnt=0;
	for(auto p:ve){
		if(cnt==n-1)
			break;
		if(find(p.u)==find(p.v))
			continue;
		else{
			fa[p.u]=find(p.v);
			ans+=p.w;
			cnt++;
		}
	}
	cout<<ans;
}
solve3(){
	cout<<"psyæ»Œ“£°£°£°"; 
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		ve.push_back({u,v,w});
	}
	if(k==0)
		solve1();
	else{
		bool flag=true;
		for(int i=1;i<=k;i++){
			cin>>c[i];
			if(c[i]!=0)
				flag=false;
			for(int j=1;j<=n;j++)
				cin>>a[i][j];
		}	
		if(flag)
			solve2();//–‘÷ A 
		else
			solve3();
	}
	return 0;
}
