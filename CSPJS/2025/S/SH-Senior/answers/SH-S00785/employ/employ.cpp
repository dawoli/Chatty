#include<bits/stdc++.h>
using namespace std;
int n,m,a,sum=0;
long long ans=1;
string s;
bool flag=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a!=0)sum++;
		if(s[i-1]!='1')flag=false;
	}
	cout<<sum<<endl;
	if(flag&&sum>=m){
		for(int i=1;i<=sum;i++)ans=(ans*i)%998244353;
		cout<<ans;
	}
	else cout<<0;
	return 0;
}

