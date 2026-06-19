#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("explore.in","r",stdin);
	freopen("explore.out","w",stdout);
	int ni;cin>>ni;for(int i=0;i<ni;i++){
		int n,m,nx,ny,nd,r=0;long long k;char temp;cin>>n>>m>>k>>nx>>ny>>nd;
		int a[n+2][m+2]={0};for(int j=1;j<=n;j++)for(int ij=1;ij<=m;ij++){cin>>temp;if(temp=='.')a[j][ij]=1;}a[nx][ny]=2;
		for(long long j=0;j<k;j++){
			switch(nd){
				case 0:if(a[nx][ny+1])ny++;else nd=1;break;
				case 1:if(a[nx+1][ny])nx++;else nd=2;break;
				case 2:if(a[nx][ny-1])ny--;else nd=3;break;
				case 3:if(a[nx-1][ny])nx--;else nd=0;break;
			}if(a[nx][ny])a[nx][ny]=2;
		}
		for(int j=1;j<=n;j++)for(int ij=1;ij<=m;ij++)if(a[j][ij]==2)r++;
		cout<<r;if(i<ni-1)cout<<"\n";
	}
	return 0;
}
