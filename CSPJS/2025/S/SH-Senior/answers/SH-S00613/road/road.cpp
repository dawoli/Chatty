#include<bits/stdc++.h>
using namespace std;
int read(){
	char ch=getchar();
	int x=0;
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x;
}
void write(long long x){
	if(x/10) write(x/10);
	putchar(x%10+'0');
}
void we(int x){
	write(x);
	putchar('\n');
}
int n,m,k,ci[20],fa[10010],now[10010];
long long ans;
struct edge{
	int ui,vi,wi;
}bb[1000010],cc[20][10010],bb1[10010];
bool cmp(edge x,edge y){
	return x.wi<y.wi;
}
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void link(int x,int y){
	int fx=find(x),fy=find(y);
	fa[fx]=fy;
}
long long calc(int sit){
	long long ret=0;
	for(int i=1;i<=n+k;i++) fa[i]=i;
	int totno=n,tote=0;
	now[0]=1;
	for(int i=0;i<k;i++){
		if(sit&(1<<i)) ret+=ci[i+1],++totno;
		now[i+1]=1;
	}
	if(ret>=ans) return ret;
	//cout<<ret<<endl;
	while(1){
		int id=0,pr=bb[now[0]].wi;
		for(int i=1;i<=k;i++){
			if((sit&(1<<(i-1)))&&cc[i][now[i]].wi<pr) id=i,pr=cc[i][now[i]].wi;
		}
		if(id==0){
			if(find(bb[now[0]].ui)!=find(bb[now[0]].vi)){
				link(bb[now[0]].ui,bb[now[0]].vi);
				ret+=bb[now[0]].wi;
				if(sit==0) bb1[tote+1]=bb[now[0]];
				++tote;
			}
			++now[0];
		}
		else{
			if(find(cc[id][now[id]].ui)!=find(cc[id][now[id]].vi)){
				link(cc[id][now[id]].ui,cc[id][now[id]].vi);
				ret+=cc[id][now[id]].wi;
				++tote;
			}
			++now[id];
		}
		if(ret>ans||tote==totno-1) return ret;
	}
	return -1;
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++){
		bb[i]=(edge){read(),read(),read()};
	}
	for(int i=1;i<=k;i++){
		ci[i]=read();
		for(int j=1;j<=n;j++){
			int x=read();
			cc[i][j]=(edge){j,n+i,x};
		}
		cc[i][n+1].wi=0x3f3f3f3f;
	}
	sort(bb+1,bb+m+1,cmp);
	for(int i=1;i<=k;i++) sort(cc[i]+1,cc[i]+n+1,cmp);
	ans=0x3f3f3f3f3f3f3f3fll;
	for(int i=0;i<(1<<k);i++){
		ans=min(ans,calc(i));
		if(i==0){
			for(int j=1;j<n;j++) bb[j]=bb1[j];
			m=n-1;
		}
	}
	write(ans);
	return 0;
}
