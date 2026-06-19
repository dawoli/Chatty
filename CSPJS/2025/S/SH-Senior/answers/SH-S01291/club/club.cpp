#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=100010;
int a[N][N][N]; 
int b[N][N][N];
bool vis[N][N];
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++{
		for(int k=n;k>=1;k--){
			t(x)=max(a[i][1][k]+b[i][j][k],a[1][1][k]+a[k+1][i][j]);
		}
	}
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=n;j++){
		for(int k=1;k<=n;k++){
			t(x)=max(ans,t[n][j][k]);
			cout<<endl;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdin);
	int t;
	cin>>t;
	int n;
	cin>>n;
	t[2]=t[3]=true;
	for(int i=1;i<=n;i++){
		for(ll j=1;j<=3;j++){
			for(ll k=1;k<=t;k++){
				cin>>a[i][j][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(a[i][j]!=0)bool vis=false;
		}
	}
	return 0;
} 
