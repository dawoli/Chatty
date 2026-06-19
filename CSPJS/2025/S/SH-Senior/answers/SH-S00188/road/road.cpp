#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=10019;
const ll M=4000009;
ll id[N],n,m,k,cnt,w[N];
ll root(ll x){
	return (id[x]==x)?x:id[x]=root(id[x]);
} 
struct Node{
	ll u,v,c;
}; 
bool cmp(const Node&a,const Node&b){
	return a.c<b.c;
}
Node e[M];
ll ans,eused;
void Kruskal(){
	cnt=0; 
	while(eused<n-1){
		ll idx=root(e[++cnt].u);
		ll idy=root(e[cnt].v);
		//cout<<idx<<" "<<idy<<" ";
		if(idx==idy) continue ;
		ans+=e[cnt].c;
		id[e[cnt].u]=e[cnt].v;
		//cout<<root(e[cnt].u)<<" "<<root(e[cnt].v)<<" ";
		eused++;
		//cout<<e[cnt].u<<"->"<<e[cnt].v<<endl;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n+k;i++) id[i]=i;
	for(int i=1;i<=m;i++){
		ll op1,op2,op3;
		cin>>op1>>op2>>op3;
		e[++cnt]=(Node){op1,op2,op3};
	}
    /*
	for(int i=1;i<=k;i++){
		ll fcity;
		cin>>fcity;
		for(int j=1;j<=n;j++){
			cin>>w[j];
			for(int p=1;p<j;p++){//p-j Á¬±ß£¨p,j,w[j]+w[p]+fcity£© 
				
				
			}
		}
	}*/
	sort(e+1,e+cnt+1,cmp);
	Kruskal(); 
	return 0;
}

