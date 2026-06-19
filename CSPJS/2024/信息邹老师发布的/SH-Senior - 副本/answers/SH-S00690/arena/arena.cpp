#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,k;
int a[10],b[10],c[10],ans;
int tmp[10][10],d[10][10];
int cal(){
	for(int i=1;i<=(1<<k);i++){
		tmp[0][i]=i;
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=1<<(k-i);j++){
			int t=tmp[i-1][(j<<1)-1+d[i][j]];
			if(b[t]>=i)tmp[i][j]=t;
			else tmp[i][j]=tmp[i-1][(j<<1)-d[i][j]];
		}
	}
	return tmp[k][1];
}
char sss[10];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	if(n>8||m>8){
		cout<<0;
		exit(0);
	}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	k=__lg(n-1)+1;
	for(int i=1;i<=k;i++){
		scanf("%s",sss+1);
		for(int j=1;j<=1<<(k-i);j++)d[i][j]=sss[j]^48;
	}
	int T;scanf("%d",&T);
	while(T--){
		int ans=0;
		int x[4];for(int i=0;i<4;i++)cin>>x[i];
		for(int i=1;i<=m;i++){
			set<int> tmp;int cnt=0;
			if(c[i]==1) {ans^=i;continue;}
			for(int j=1;j<=c[i];j++)b[j]=a[j]^x[j%4];
			k=__lg(c[i]-1)+1;
			int t=(1<<k)-c[i];
			for(int j=0;j<(1<<t);j++){
				for(int xxx=c[i]+1;xxx<=(1<<k);xxx++){
					b[xxx]=(1&(j>>(xxx-c[i]-1)))*inf;
				}
				tmp.insert(cal());
//				printf("%d %d\n",c[i],cal());
			}
			for(int aaa:tmp){
				cnt+=aaa;
			}
			ans^=i*cnt;
		}
		printf("%d\n",ans);
	}
	return 0;
}
