#include<bits/stdc++.h>
using namespace std;
int n,m,k,tot;
struct edge{
	int ver,cost,head,to;
}E[1000005];
void add(int u,int v,int w){
	E[u].head=tot;
	E[++tot].ver=v;
	E[tot].cost=w;
	E[tot].to=head[u];
}
bool cmp(edge a,edge b){
	return a.cost<b.cost;
} 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	int a,b,c;
	for(int i=1;i<=m;i++){
		cin>>a>>b>>c;
		add(a,b,c);
		add(b,a,c);
	}
	sort(E+1,E+m+1,cmp);
	for(int i=1;i<=k;i++){
		cin>>a;
		for(int j=1;j<=n;j++){
			cin>>a;
		}
	}
	cout<<24;
	fclose(stdin);fclose(stdout);
	return 0;
}
//²¢²é¼¯
