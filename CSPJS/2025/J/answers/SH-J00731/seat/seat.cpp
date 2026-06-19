#include<bits/stdc++.h>
using namespace std;
int n,m,r,rk,cnt,a[110];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}r=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(r==a[i]){
			rk=n*m-i+1;
		}
	}for(int i=1;i<=n;i++){
		cnt+=m;
		if(cnt==rk){
			if(i%2==1){
				printf("%d %d",i,m);
				return 0;
			}else{
				printf("%d 1",i);
				return 0;
			}
		}else if(cnt>rk){
			if(i%2==1){
				for(int j=1;j<=m;j++){
					if((i-1)*m+j==rk){
						printf("%d %d",i,j);
						return 0;
					}
				}
			}else{
				for(int j=1;j<=m;j++){
					if((i-1)*m+(m-j+1)==rk){
						printf("%d %d",i,j);
						return 0;
					}
				}
			}
		}
	}return 0;
}
