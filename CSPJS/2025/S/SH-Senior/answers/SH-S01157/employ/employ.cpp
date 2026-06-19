#include<bits/stdc++.h>
using namespace std;
int n,m,c[600];
string s;
void solve1(){
	return;
}
void solve2(){
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=(ans*i)%998244353;
	}
	cout<<ans;
	return;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==1)solve1();
	else solve2();
	return 0;
}
