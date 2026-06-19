#include<bits/stdc++.h>
using namespace std;
long long qpow(long long a,long long b){
	long long ret=1;
	while(b){
		if(b%2==1){
			ret*=a;
		}b/=2;
		a*=a;
	}return ret;
}
int n,m,t,a[100010],c[100010],x[10];
map<int,map<int,int> >d;
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}int cnt=0;
	for(int i=1;i<=31;i++){
		if(qpow(2,i)>=n){
			cnt=i;
			break;
		}
	}for(int i=1;i<=cnt;i++){
		for(int j=1;j<=qpow(2,cnt-i);j++){
			scanf("%1d",&d[i][j]);
		}
	}scanf("%d",&t);
	while(t --> 0){
		for(int i=0;i<4;i++){
			scanf("%d",&x[i]);
		}for(int i=1;i<=n;i++){
			a[i]^=x[i%4];
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=cnt;j++){
//			int cnt1=0,tmp1=a[i],tmp2;
//			if(i%2==1){
//				
//			}else if(i%2==0){
//				
//			}
//		}
//	}
	return 0;
}//赛场上唯一的遗憾，T=1没写完。 
