#include<bits/stdc++.h>
using namespace std;
int n,m,c[1000000];string x;
const int P= 998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	cin>>n>>m;
	cin>>x;
	for(int i = 1;i<=n;++i){
		cin>>c[i];
		if(c[i]==0&&m==n){
			cout<<0;return 0;
		}
	}
	int ans=1;
	for(int i = 1;i<=n;++i){
		ans*=i;
		ans%=P;
	}
	cout<<ans;
	return 0;
}

