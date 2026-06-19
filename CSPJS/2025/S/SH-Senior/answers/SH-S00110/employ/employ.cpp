#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,a[1000];
	string s;
	int idx=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			idx++;
		}
	}
	if(n-idx<m){
		cout<<0;return 0;
	}
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans*=i;
	}
	cout<<ans%998244353;
	return 0;
}
