#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int n,m,k,v[1000010];
struct node{int id,t,w;}p[10010];
bool cmp(node x,node y){
	return x.t<y.t;}
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>v[i];
	for(int i=1;i<=n;i++){
		cin>>p[i].t>>p[i].w;
		p[i].id=i;
	}
		
	sort(p+1,p+n+1,cmp);
	for(int i=1;i<=n;i++)
		cout<<p[i].id<<" "<<p[i].t<<" "<<p[i].w<<"\n";
}
