#include <bits/stdc++.h>
using namespace std;
int a[15][15];
int ans[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,r;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>ans[i];
		if(i==1){
			r=ans[i];
		}
	}
	sort(ans+1,ans+n*m+1);
	bool x=1;
	int s=n*m;
	for(int i=1;i<=m;i++){
		if(x){
			for(int j=1;j<=n;j++){
				a[j][i]=ans[s--];
				if(a[j][i]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=n;j>=1;j--){
				a[j][i]=ans[s--];
				if(a[j][i]==r){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
		x=!x;
	}
	return 0;
}
