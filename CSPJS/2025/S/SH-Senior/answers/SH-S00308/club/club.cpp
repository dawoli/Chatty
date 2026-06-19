#include<bits/stdc++.h>
using namespace std;
int t,n,f[201][201][201];
struct sp{
	int _1,_2,_3; 
}a[100001];
bool cmp(sp a,sp b){
	if(a._1>b._1) return true;
	else return false;
}signed main(void){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d%d%d",&a[i]._1,&a[i]._2,&a[i]._3);
		memset(f,0,sizeof(f));
		if(n>200){
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a[i]._1;
			}printf("%d\n",ans);
		}else{
			int ans=-0x3fffffff;
			for(int lng=1;lng<=n;lng++){
				for(int i=lng;i>=0;i--) for(int j=lng-i;j>=0;j--) for(int k=lng-i-j;k>=0;k--){
					if(i>0) f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+a[lng]._1);
					if(j>0) f[i][j][k]=max(f[i][j][k],f[i][j-1][k]+a[lng]._2);
					if(k>0) f[i][j][k]=max(f[i][j][k],f[i][j][k-1]+a[lng]._3);
//					cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
				}
//				cout<<endl;
			}for(int i=0;i<=n;i++) for(int j=0;j<=n-i;j++) for(int k=0;k<=n-i-j;k++) if(i<=n/2&&j<=n/2&&k<=n/2) ans=max(ans,f[i][j][k]);
			printf("%d\n",ans);
		}
//		for(int i=0;i<=n;i++) for(int j=0;j<=n-i;j++) for(int k=0;k<=n-i-j;k++) if(i<=n/2&&j<=n/2&&k<=n/2) cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<endl;
	}return 0;
}
