#include<bits/stdc++.h>
using namespace std;
int n,m,s[109],a[19][19],r,in[109],ans[19][19]; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=(n*m);i++){
		cin>>in[i];
	}
	r=in[1];
	sort(in+1,in+(n*m)+1);
	for(int i=1;i<=(n*m);i++){
		s[i]=in[(n*m)-i+1];
	}
	for(int i=1;i<=n;i++){
		if(i%2!=0){
			for(int j=m;j>=1;j--){
				a[i][j]=s[(i-1)*m-j+m+1];
			}
		}
		else{
			for(int j=1;j<=m;j++){
				a[i][j]=s[(i-1)*m+j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans[i][j]=a[j][n-i+1];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ans[i][j]==r) cout<<j<<" "<<i<<endl;
		}
	}
	return 0;
}
