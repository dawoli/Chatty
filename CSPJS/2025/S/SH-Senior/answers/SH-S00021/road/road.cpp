#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000009;
int b[N];
int n,m,k; 
bool x[N];
ll mn;
struct Edge{
	int u,v,w;
};
bool cmp(const Edge&a,const Edge&b){
	return a.w<b.w;
}
Edge c[N]; 
int main(){
	//freopen("road.in","r",stdin);
	//freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	    cin>>c[i].u>>c[i].v>>c[i].w;
	for(int i=1;i<=k;i++)
	    for(int j=1;j<=n+1;j++)
	        cin>>b[j];
	sort(c+1,c+m+1,cmp);
	for(int i=1;i<=m;i++){
		if(x[c[i].u]==0||x[c[i].v]==0) mn+=c[i].w,x[c[i].u]=x[c[i].v]=1,cout<<mn<<endl;
	}
	cout<<mn<<endl;
	return 0;
}
