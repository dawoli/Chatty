#include<bits/stdc++.h> 
using namespace std;
const int maxn=10005,maxm=1000005,maxk=12;
int n,m,k,ans=0;
bool con[maxn]={0};
struct road{
	int u,v,w;
}r[maxm];

bool cmp(road x,road y){
	if(x.w<y.w) return 1;
	else return 0;
}
bool check(){
	for(int i=1;i<=n;i++){
		if(con[i]==0) return false;
	} 
	return true;
}

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	if(k==0){
		for(int i=1;i<=m;i++){
			cin>>r[i].u>>r[i].v>>r[i].w;
		} 
		sort(r+1,r+1+n,cmp);
		ans+=r[1].w;
		con[r[1].u]=1; con[r[1].v]=1;
		for(int i=2;i<=m;i++){
			if(check()) break;
			else{
				if(!con[r[i].u] or !con[r[i].v]){
					ans+=r[i].w;
					con[r[i].u]=1; con[r[i].v]=1;
				}
				else continue;
			}
		}
		cout<<ans;
	}
	return 0;
}
