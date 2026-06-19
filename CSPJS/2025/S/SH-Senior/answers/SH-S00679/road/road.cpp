#include<bits/stdc++.h>
using namespace std;
const int N=1e6+2e5+5;
int n,m,k,gc[N],ak[N];
struct node{
	int u,v,w;
}q[N];
bool cmd(node a,node b){
	return a.w<b.w;
}
int find(int n){
	if(gc[n]==n)return n;
	return gc[n]=find(gc[n]);
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=N;i++)gc[i]=i;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		q[i].u=a;
		q[i].v=b;
		q[i].w=c;
	}
	int cnt=m;
	for(int i=1;i<=k;i++){
		int sp;
		cin>>sp; 
		for(int i=1;i<=n;i++){
			cin>>ak[i];
		}
		if(sp==0){
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					if(i!=j){
						cnt++;
						q[cnt].u=i;
						q[cnt].v=j;
						q[cnt].w=ak[i]+ak[j];
					}
				}
			}
		}
	}
	sort(q+1,q+cnt+1,cmd);
	for(int i=1;i<=cnt;i++){
		if(find(q[i].u)!=find(q[i].v)){
			ans+=q[i].w;
			gc[q[i].v]=gc[q[i].u];	
		}
		
	}
	cout<<ans;
}
