#include <bits/stdc++.h>
using namespace std;
int n,m,L,V;
int l[100010],r[100010];
int chkpt[100010];
int F,F2;
typedef pair<int,int> pii;
pii c[100010];int t;
bool cmp(pii x,pii y){
	return x.second==y.second?x.first<y.first:x.second<y.second;
}
int BIT[100010];
int qry(int x){
	int tmp=0;for(;x;x-=x&(-x))tmp+=BIT[x];return tmp;
}
int query(int x,int y){
	return qry(y)-qry(x-1);
}
void add(int x){
	for(;x<=m;x+=x&(-x))BIT[x]++;
}
void solve(){
	scanf("%d%d%d%d",&n,&m,&L,&V);
	for(int i=1,d,v,a;i<=n;i++){
		scanf("%d%d%d",&d,&v,&a);
		if(a>0){
			if(v>V){l[i]=d;r[i]=L;}
			else{l[i]=d+(V*V-v*v)/(2*a)+1;r[i]=L;}
		}else if(a==0){
			if(v>V){l[i]=d;r[i]=L;}
			else{l[i]=L+1;r[i]=L;}
		}else{
			if(v>V){l[i]=d;r[i]=min(d+(v*v-V*V-2*a-1)/(-2*a)-1,L);}
			else{l[i]=L+1;r[i]=L;}
		}
	}
	for(int i=1;i<=m;i++)scanf("%d",&chkpt[i]);
	F=0;t=0;F2=m;memset(BIT,0,sizeof(BIT));
	for(int i=1;i<=n;i++){
		if(l[i]<=r[i]){
			int xb1=lower_bound(chkpt+1,chkpt+m+1,l[i])-chkpt;
			int xb2=upper_bound(chkpt+1,chkpt+m+1,r[i])-chkpt-1;
			if(xb1<=xb2){
				c[++t]=make_pair(xb1,xb2);
				F++;
			}
		}
	}
	sort(c+1,c+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(query(c[i].first,c[i].second))continue;
		F2--;add(c[i].second);
	}
	printf("%d %d\n",F,F2);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int T;scanf("%d",&T);
	while(T--)solve();
	return 0;
}
