#include<bits/stdc++.h>
using namespace std;
int t;
int n,m,l,V;
int d[100005],v[100005],a[100005];
int p[100005];
bool uon[100005];
bool ov_sp[100005];
int anc,fan=0;
void get_rg(int i){
	if(a>0){
		for(int j=1;j<=l;j++){
			if(!uon[j])	continue;
			if(d[i]>p[j])	continue;
			double vv=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
			if(vv>V*1.00){
				ov_sp[i]=1;
				break;
			}
		}
	}
	else if(a<0){
		if(v[i]<V)	return;
		for(int j=1;j<=l;j++){
			if(!uon[j])	continue; 
			if(d[i]>p[j])	continue;
			ov_sp[i]=1;
			double vv=sqrt(v[i]*v[i]+2*a[i]*(p[j]-d[i]));
			if(vv<=V*1.00){
				ov_sp[i]=0;
			}
			else{
				break;
			}
		}
	}
	else if(a==0&&V<v[i]){
		ov_sp[i]=1;
	}
	return;
}
void dfs(int id,int deltn){
	if(id==m+1){
		memset(ov_sp,0,sizeof(ov_sp));
		for(int i=1;i<=n;i++)	get_rg(i);
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(ov_sp[i])	cnt++;
		}
		if(anc==cnt){
			fan=max(fan,deltn);
		}
		return;
	}
	uon[id]=0;
	dfs(id+1,deltn+1);
	uon[id]=1;
	dfs(id+1,deltn);
}
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		int pd_as=0;
		memset(ov_sp,0,sizeof(ov_sp));
		scanf("%d%d%d%d",&n,&m,&l,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
			if(a[i]!=0)	pd_as=1;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
			uon[i]=1;
		}
		if(!pd_as){
			int as_cnt=0;
			for(int i=1;i<=n;i++){
				if(v[i]>V)	as_cnt++;
			}
			printf("%d %d\n",as_cnt,m-1);
		}
		else{
			for(int i=1;i<=n;i++)	get_rg(i);
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(ov_sp[i])	cnt++;
			}
			anc=cnt;
			printf("%d ",cnt);
			fan=0;
			dfs(1,0);
			printf("%d\n",fan);
		}
	}
	return 0;
}

