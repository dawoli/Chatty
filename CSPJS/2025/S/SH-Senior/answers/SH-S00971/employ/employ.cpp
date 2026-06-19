#include<bits/stdc++.h>
using namespace std;
int a[10010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long int cnt=1;
	for(int i=n;i>=m;i--){
		cnt*=(long long int)i;
		cnt%=998244353;
	}
	cout<<cnt;
	return 0;
}

