#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int m,n,c,j=1;
	unsigned long long ans=1,anss=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>c;
	}
	for(int k=m;k<=n;k++){
		j=1,ans=1;
	for(int i=n;i>n-k;i--){
		ans*=i;
		ans/=j;
		j++; 
	}
	cout<<ans<<endl;
	anss+=ans;
}
	cout<<anss%998244353;
}
