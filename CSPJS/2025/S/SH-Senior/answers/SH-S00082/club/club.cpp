#include<bits/stdc++.h>
using namespace std;

void FileIO(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
}
#define ll long long
const int N=1e5+5;

int n,ans;
struct node{
	int a,b,c;
}p[N];
bool cmp(vector<int> &x,vector<int> &y){
	return x.size()>y.size();	
}
bool cmpa(node x,node y){
	return min(x.a-x.b,x.a-x.c)<min(y.a-y.b,y.a-y.c);
}
bool cmpb(node x,node y){
	return min(x.b-x.a,x.b-x.c)<min(y.b-y.a,y.b-y.c);
}
bool cmpc(node x,node y){
	return min(x.c-x.a,x.c-x.b)<min(y.c-y.a,y.c-y.b);
}

void solve(){
	cin>>n;
	int ans=0,suma=0,sumb=0,sumc=0;
	int mina=INT_MAX,minb=INT_MAX,minc=INT_MAX;
	vector<int> v[3];
	bool flag=0;
	for(int i=1;i<=n;i++){
		int u,y,w; cin>>u>>y>>w;
		suma+=u,sumb+=y,sumc+=w;
		mina=min(mina,u),minb=min(minb,y),minc=min(minc,w);
		int mx=max(u,max(y,w));
		if(mx==u) v[0].push_back(i);
		else if(mx==y) v[1].push_back(i);
		else v[2].push_back(i);
		ans+=mx,p[i]={u,y,w};
	}
	sort(v,v+3,cmp);
	if(v[0].size()<=(n/2)) return void(cout<<ans<<"\n");
	
	if(n&1) suma-=mina,sumb-=minb,sumc-=minc; 
	sort(p+1,p+1+n,cmpa);
	for(int i=1;i<=(n/2);i++) suma-=min(p[i].a-p[i].b,p[i].a-p[i].c);
	sort(p+1,p+1+n,cmpb);
	for(int i=1;i<=(n/2);i++) sumb-=min(p[i].b-p[i].a,p[i].b-p[i].c);
	sort(p+1,p+1+n,cmpc);
	for(int i=1;i<=(n/2);i++) sumc-=min(p[i].c-p[i].a,p[i].c-p[i].b);
	cout<<max(suma,max(sumb,sumc))<<"\n";
	
	return;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	FileIO();
	
	int T=1;
	cin>>T;
	while(T--){
		solve();
	}
	
	return 0;
} 
