#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
int n,m;
string s;
int c[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		ans=(ans*i)%Mod;
	}
	cout<<ans;
	return 0;
}
