#include<bits/stdc++.h>
using namespace std;
string d[15];
int n,m,K=0,c[100010],T,k,w[100010];
long long a[100010],x[100010],ans,b[100010];
int main(){
freopen("arena.in","r",stdin);
freopen("arena.out","w",stdout);
scanf("%d%d",&n,&m);
while(pow(2,K)<n){
	K++; 
}
for(int i=1;i<=n;i++){
	scanf("%lld",a+i);
}
for(int i=1;i<=m;i++){
	scanf("%d",c+i);
}
for(int i=1;i<=K;i++){
	cin>>d[i];
}
scanf("%d",&T);
for(int t=0;t<T;t++){
	ans=0;
	for(int i=0;i<4;i++){
		scanf("%lld",x+i);
	}
	for(int i=1;i<=n;i++){
		a[i]=(a[i]^x[i%4]);
	}
	for(int I=1;I<m;I++){
	int R=0;
		for(int j=1;j<=n;j++){
			b[j]=a[j];
		}
		while(1){
			int N=0;
			for(int i=1;i<=n;i++){
				if(w[i]==0){
					N++;
				}
			}
			if(N==1)break;
			R++;
			int G=1,y=0;
			for(int i=1;i<=n;i++){
				if(w[i]==0){//0:win
					if(y==0){
						y=i;
					}
					else{
						if(d[R][G]=='0'){
							if(a[y]>=R){
								w[y]=0;w[i]=1;
							}
							else{
								w[y]=1;w[i]=0;
							}
						}
						else{
							if(a[i]>=R){
								w[i]=0;w[y]=1;
							}
							else{
								w[i]=1;w[y]=0;
							}
						}
						G++;y=0;
					}
				}
			}
		}
		if(I==1){
			for(int i=1;i<=n;i++){
				if(w[i]==0){
					ans=i;break;
				}
			}
		}
		else{
			for(int i=1;i<=n;i++){
				if(w[i]==0){
					ans=ans^(i*I);break;
				}
			}
		}
	}
	printf("%lld\n",ans);
}
return 0;
}
