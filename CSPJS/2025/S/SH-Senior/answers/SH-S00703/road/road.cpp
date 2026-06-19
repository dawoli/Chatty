#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n,a[100009][5],ax,bx,cx,ans,zd;
ll b[100009][5],zx;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n;
		for(ll i=1;i<=n;i++){
			zx=1e9,zd=-1;
			for(ll j=1;j<=3;j++){
				cin>>a[i][j];
				zd=max(zd,a[i][j]);
				zx=min(zx,a[i][j]);
			}
			if(a[i][1]==zx){
				a[i][1]=0;
				b[i][2]=n-i+1;
				b[i][3]=n-i+1;
			}
			else if(a[i][2]==zx){
				a[i][2]=0;
				b[i][1]=n-i+1;
				b[i][2]=n-i+1;
			}
			else if(a[i][3]==zx){
				a[i][3]=0;
				b[i][1]=n-i+1;
				b[i][2]=n-i+1;
			}
		}
	}
	return 0;
}       
