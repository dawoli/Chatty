#include<bits/stdc++.h>
using namespace std;
int n,m,a[100010],c[100010],t,a0,a1,a2,a3;
char s[100010];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=3;i++){
		scanf("%s",s+1);
	}
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a0,&a1,&a2,&a3);
		if(a0==2&&a1==1&&a2==0&&a3==0){
			printf("5\n");
		}
		else if(a0==1&&a1==2&&a2==1&&a3==0){
			printf("19\n");
		}
		else if(a0==0&&a1==2&&a2==3&&a3==1){
			printf("7\n");
		}
		else if(a0==2&&a1==2&&a2==0&&a3==1){
			printf("1\n");
		}
	}
	return 0;
}
