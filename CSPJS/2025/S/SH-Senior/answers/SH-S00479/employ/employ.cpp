#include<bits/stdc++.h>
using namespace std;
string s;
int n,m;
int a[600],ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		ans*=a[i]%998244353;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0; 
}
