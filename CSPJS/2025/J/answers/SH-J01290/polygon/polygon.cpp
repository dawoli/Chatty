#include<bits/stdc++.h>
using namespace std;
int n,a[5002],maxa=0;
long long ans;
void solve(int m,int suml,int maxl,int i){
	m++;
	suml+=a[i];
	maxl=max(maxl,a[i]);
	if(m>=3&&suml>2*maxl)ans++;
	for(int j=i+1;j<n;j++)solve(m,suml,maxl,j);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	if(maxa<=1){
		ans=1;
		for(int i=0;i<n;i++)ans*=2;
		ans-=1+n+n*(n-1)/2;
	}
	else for(int i=0;i<n;i++)solve(0,0,0,i);
	cout<<ans%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
