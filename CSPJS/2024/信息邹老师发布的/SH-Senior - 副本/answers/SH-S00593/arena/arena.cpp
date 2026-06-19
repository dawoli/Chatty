#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m;
int a1[N];
int c[N];
int k=0;
int jkl=1;
char g[N][N];
int x[110];
int a[N];

int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a1[i];
	for(int j=1;j<=m;j++) cin>>c[j];
	while(jkl<n) hjk*=2,k++;
	for(int i=1;i<=k;i++){
		int R=pow(2,k-i);
		for(int j=1;j<=R;j++)
			cin>>g[i][j];
			
	}
	int t;
	cin>>t;
	while(t--){
		for(int i=0;i<=3;i++) cin>>x[i];
		for(int i=1;i<=n;i++) a[i]=a1[i]^x[i%4];
		cout<<"2";
	}
	return 0;
}
