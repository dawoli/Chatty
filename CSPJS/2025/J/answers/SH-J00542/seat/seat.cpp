#include<bits/stdc++.h>
using namespace std;

int a[100100];
int f[19][19];
int main(){	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int p=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	int k=find(a,a+n*m,p)-a;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(j==1){
					f[j][i]=f[j][i-1]+1;
				}
				else{
					f[j][i]=f[j-1][i]+1;
				}	
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				if(j==n){
					f[j][i]=f[j][i-1]+1;
				}
				else{
					f[j][i]=f[j+1][i]+1;
				}		
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j]==k) cout<<j<<' '<<i<<endl;
		}
	}
}
