#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200];
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int ans=a[1];
	//cout<<ans;
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i];
	int x=0,ii=0,jj=0,kk=0;
	for(int i=1;i<=m;i++){
		ii=i;
		if(ii%2==1){
		for(int j=1;j<=n;j++){
			jj=j;
			x++;
			if(a[x]==ans){
				cout<<ii<<" "<<jj<<endl;
			}
		}
	}
	else {
		for(int k=n;k>=1;k--){
			kk=k;
			x++;
			if(a[x]==ans){
				cout<<ii<<" "<<kk<<endl;
			}
		}
		
	}
	}
	return 0;
}
