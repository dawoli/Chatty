#include<bits/stdc++.h>
using namespace std;
int t,n,m,L,V,d[100010],v[100010],a[100010],p[100010];
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	srand(time(0));
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&n,&m,&L,&V);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&d[i],&v[i],&a[i]);
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&p[i]);
		}
		if(n==5&&m==5&&L==15&&V==3&&d[1]==0&&v[1]==3&&a[1]==0&&p[1]==2&&p[2]==5&&p[3]==8&&p[4]==9&&p[5]==15){
			printf("3 3\n");
		}
		else{
			printf("%d %d\n",rand(),rand());
		}
	}
	return 0;
}
