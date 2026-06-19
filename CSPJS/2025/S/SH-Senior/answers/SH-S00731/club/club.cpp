#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int t,n;
struct a1{
	int x,y,z;
}a[maxn];
struct node{
	int a,b,c;
};
int f[maxn>>1][maxn>>1][maxn>>1];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)a[i].x=a[i].y=a[i].z=0;
		for(int i=1;i<=n;i++)
		  scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
		for(int i=1;i<=n;i++)
		  for(int c1=0;c1<=(n>>1);c1++)
			for(int c2=0;c2<=(n>>1);c2++){
				int c3=i-c1-c2;
				if(c3<0)break;
				f[c1][c2][c3]=0;
			}
		for(int i=1;i<=n;i++){
			for(int c1=0;c1<=(n>>1);c1++)
			  for(int c2=0;c2<=(n>>1);c2++){
			  	int c3=i-c1-c2;
			  	if(c3<0)break;
			  	if(c3>(n/2))continue;
			  	if(c1>0)f[c1][c2][c3]=max(f[c1][c2][c3],f[c1-1][c2][c3]+a[i].x);
			  	if(c2>0)f[c1][c2][c3]=max(f[c1][c2][c3],f[c1][c2-1][c3]+a[i].y);
			  	if(c3>0)f[c1][c2][c3]=max(f[c1][c2][c3],f[c1][c2][c3-1]+a[i].z);
			  }
		}
		int ans=0;
		for(int c1=1;c1<=(n>>1);c1++)
			  for(int c2=1;c2<=(n>>1);c2++){
			  	int c3=n-c1-c2;
			  	if(c3<0)break;
			  	ans=max(ans,f[c1][c2][c3]);
			  }
		printf("%d\n",ans);
	}
		
	return 0;
}
