#include<bits/stdc++.h>
using namespace std;
int T;
const int N=100010;
int d[N],v[N],a[N],p[N],vis[N],wo[N];
double die[N];
bool A,B;
vector<int>G[N];
double check(int v,int a,int s){
	if(a==0) return v;
	return sqrt(v*v+2*a*s);
}
int slove(){
	memset(vis,0,sizeof(vis));
	memset(wo,0,sizeof(wo));
	A=B=false;
	int n,m,L,V;
	cin>>n>>m>>L>>V;
	for(int i=1;i<=n;i++){
		cin>>d[i]>>v[i]>>a[i];
		if(a[i]!=0) A=true;
		if(a[i]<0) B=true;
		if(a[i]<0){
			die[i]=d[i]+(v[i]*v[i])/(a[i]*2);
			if(die[i]>=L) die[i]=L;
		}
		else{
			die[i]=L;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>p[i];
	}
	if(A==false){
		int mx=0,res=0;
		for(int i=1;i<=m;i++){
			mx=max(mx,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(d[i]<=mx && v[i]>V) res++;
		}
		if(res==0){
			cout<<res<<" "<<m<<endl;
		}
		else{
			cout<<res<<" "<<m-1<<endl;
		}
	}
	else if(B==false){
		int mx=0,res=0;
		for(int i=1;i<=m;i++){
			mx=max(mx,p[i]);
		}
		for(int i=1;i<=n;i++){
			if(d[i]<=mx && check(v[i],a[i],mx-d[i])>(double)V) res++;
		}
		if(res==0){
			cout<<res<<" "<<m<<endl;
		}
		else{
			cout<<res<<" "<<m-1<<endl;
		}
	}
	else if(n<=3000 && m<=3000){
		int res=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(p[j]>=d[i]  && check(v[i],a[i],p[j]-d[i])>(double)V){
					vis[i]=1;
					G[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			if(vis[i]==1) res++;
		}
		int ans=100010,cnt=0;
		for(int i=1;i<(1<<m);i++){
			cnt=0;
			memset(wo,0,sizeof(wo));
			for(int j=1;j<=m;j++){
				if(i & (1<<(j-1))){
					for(int u=0;u<G[j].size();u++){
						wo[G[j][u]]=1;
					}
					cnt++;
				}
			}
			bool flag=0;
			for(int k=1;k<=n;k++){
				if(vis[k]==1 && wo[k]==0) flag=1;
			}
			if(flag==0) {
				ans=min(ans,cnt);
			}
		}
		cout<<res<<" "<<m-ans<<endl;
	}
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin>>T;
	while(T--){
		slove();
	}
	return 0;
}
