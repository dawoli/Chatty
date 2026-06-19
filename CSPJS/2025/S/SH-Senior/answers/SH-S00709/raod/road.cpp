#include<iostream>
#include<algorithm>
#include<fstream>
using namespace std;
ifstream fin("road.in");
ofstream fout("road.out");
struct Node{
	long long w;
	long long u,v;
}e[2000006];
int fa[10020];
bool cmp(Node a,Node b){
	return a.w<b.w;
}
int f(int a){
	if(fa[a]==a) return a;
	else return fa[a]=f(fa[a]);
}
int main(){
	long long n,m,k;
	fin>>n>>m>>k;
	for(int i=0;i<m;i++){
		fin>>e[i].u>>e[i].v>>e[i].w;
	}
	for(int i=1;i<=n+10;i++){
		fa[i]=i;
	}
	long long ans=0;
	if(k==0){
		sort(e,e+m,cmp);
		for(int i=0;i<m;i++){
			if(f(e[i].u)!=f(e[i].v)){
				ans+=e[i].w;
				fa[f(e[i].v)]=f(fa[e[i].u]);
			}
		}
		fout<<ans;
	}
	else{
		int l=m;
		for(int i=1;i<=k;i++){
			int c;
			fin>>c;
			for(int j=1;j<=n;j++){
				fin>>e[l].w;
				e[l].u=i+n;
				e[l].v=j;
				l++;
			}
		}
		//cout<<l;
		sort(e,e+l,cmp);
		//for(int i=0;i<l;i++){
		//	cout<<e[i].w<<" ";
		//}
		for(int i=0;i<l;i++){
			if(f(e[i].u)!=f(e[i].v)){
				//cout<<f(5);
				//cout<<f(e[i].u)<<" "<<f(e[i].v)<<" "; 
				ans+=e[i].w;
				//cout<<e[i].u<<" "<<e[i].v<<" ";
				fa[f(e[i].v)]=f(fa[e[i].u]);
				//cout<<f(e[i].u)<<" "<<f(e[i].v)<<"\n";
			}
		}
		fout<<ans;
	}
}
