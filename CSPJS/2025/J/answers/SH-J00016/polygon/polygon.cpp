#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[5005],ans=0,c[5005][5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]!=1){
			flag=false;
		}
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if((a[1]+a[2]+a[3])>2*a[3]){
			cout << 1;
		}
		else{
			cout << 0;
		}
		return 0;
	}
	if(flag==true){
		c[0][0]=1;
		c[1][1]=1;
		c[1][0]=1;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=i;j++){
				c[i][j]=c[i-1][j-1]+c[i-1][j];
				c[i][j]=c[i][j]%mod;
			}
		}
		int sss=0;
		for(int i=3;i<=n;i++){
			sss+=c[n][i];
			sss=sss%mod;
		}
		cout << sss;
		return 0;
	}
	cout << 9;
	
	return 0;
}
