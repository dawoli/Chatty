#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=10115,M=1000015;
int read(){
	int w=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ret=ret*10+c-'0';
		c=getchar();
	}
	return w*ret;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
struct edge{
	int a,b,w;
};
bool cmp(edge x,edge y){
	return x.w<y.w;
}
edge edges[M];
int p[N];
int find(int x){
	if(p[x]!=x)p[x]=find(p[x]);
	return p[x];
}
vector<edge>VEC,vec;
int n,m,k;
int A,B,W;
void kruskal(){
	sort(edges+1,edges+m+1,cmp);
	for(int i=1;i<=m;i++){
		A=edges[i].a,B=edges[i].b;
		int fa=find(A),fb=find(B);
		if(fa!=fb){
			p[fa]=fb;
			VEC.push_back(edges[i]);
		}
	}
}
void Init(){
	vec=VEC;
	for(int i=1;i<=10105;i++){
		p[i]=i;
	}
}
int val[N][12],c[12];
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++){
		A=read(),B=read(),W=read();
		edges[i]={A,B,W};
	}
	Init();
	kruskal();
	for(int j=1;j<=k;j++){
		c[j]=read();
		for(int i=1;i<=n;i++){
			val[i][j]=read();
		}
	}
	int ans=1e18;
	for(int i=0;i<1<<k;i++){
		Init();
		int tmp=0;
		for(int j=0;j<k;j++){
			if(i>>j&1){
				tmp+=c[j+1];
				for(int p=1;p<=n;p++){
					vec.push_back({j+1+n,p,val[p][j+1]});
				}
			}
		}
		sort(vec.begin(),vec.end(),cmp);
		for(auto x:vec){
			A=x.a,B=x.b,W=x.w;
			int fa=find(A),fb=find(B);
			if(fa!=fb){
				p[fa]=fb;
				tmp+=W;
			}
		}
		ans=min(ans,tmp);
	}
	write(ans);
	return 0;
}
