#include<bits/stdc++.h>
using namespace std;
int rd(){
	char c=getchar();int x=0;
	while(c>='0' && c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
struct gl{
	int s,e;
	long long w;
}s[1100005];
bool cmp(gl a,gl b){
	return a.w<b.w;
}
int n,m,k,fa[10015],f[10015];
long long ans;
int fd(int p){
	int q=p;
	while(fa[p]) p=fa[p];
	if(q!=p) fa[q]=p;
	return p;
}
long long c[15],a[15][10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;getchar();
	for(int i=1;i<=m;i++)
	{s[i].s=rd();s[i].e=rd();s[i].w=rd();}
	bool ff=0;
	for(int i=1;i<=k;i++){
		c[i]=rd();
		if(c[i]>0) ff=1;
		for(int j=1;j<=n;j++)
		a[i][j]=rd();
	}
	if(ff==0){
		for(int i=1;i<=k;i++){
			for(int j=1;j<=n;j++){
				s[++m]=(gl){n+i,j,a[i][j]};
			}
		}
		n+=k;
	}
	sort(s+1,s+1+m,cmp);
	for(int i=1;i<=m;i++){
		int p=fd(s[i].s),q=fd(s[i].e);
		if(p==q) continue;
		fa[p]=q,f[p]=q,ans+=s[i].w;
	}
	if(ff==0){
		cout<<ans;
		return 0;
	}
	return 0;
}
