#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int n,a[5005],mx[5005][5005],m,f[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		m=max(m,a[i]);	
	}
	sort(a+1,a+1+n);
	mx[2][a[1]]++,mx[2][a[2]]++,mx[2][0]++;
	mx[2][(min(m+1,a[1]+a[2]))]++;
	for(int i=3;i<=n;i++){
		f[i]=f[i-1];
		for(int j=0;j<=m+1;j++){
			mx[i][j]=(mx[i][j]+mx[i-1][j])%N;
			mx[i][(min(m+1,j+a[i]))]=(mx[i][(min(m+1,j+a[i]))]+mx[i-1][j])%N;
			if(j>a[i]) f[i]=(f[i]+mx[i-1][j])%N;
		}
	}
	cout<<f[n];
	return 0;
}
