#include<bits/stdc++.h>
using namespace std;
int dn,ass,T,n,m,l,V,d[100010],v[100010],a[100010],p[100010],P[100010];
int as(){
    int ans=0;
	for(int i=1;i<=n;i++){
		if(v[i]<=V and a[i]<=0){
				continue;
		}
		for(int j=m;j>=1;j--){
			if(p[j]<d[i] or P[j]){
				continue;
			}
			double sv=pow(v[i]*v[i]+2*a[i]*(p[j]-d[i]),0.5);
			if(sv>V){
				ans++;
				break;		
			}
		}
	}
	return ans;
}
void dfs(int d,int sum,int now){
	if(sum>=d){
		if(as()==ass){
			dn=max(dn,d);
		}return;
	}
	for(int i=now;i<=m;i++){
		if(P[i]==0){
			P[i]=1;
			dfs(d,sum+1,now+1);
			P[i]=0;
		}
	}
}
int main(){
freopen("detect.in","r",stdin);
freopen("detect.out","w",stdout);
scanf("%d",&T);
for(int TT=0;TT<T;TT++){
	dn=0;ass=0;
	vector<int>ans;
	memset(d,0,sizeof(d));
	memset(v,0,sizeof(v));
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	scanf("%d%d%d%d",&n,&m,&l,&V);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",d+i,v+i,a+i);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",p+i);
	}
	printf("%d",as());ass=as();
	for(int i=1;i<=m;i++){
		dfs(i,0,1);
	}
	cout<<' '<<dn<<endl;
}
return 0;
}
