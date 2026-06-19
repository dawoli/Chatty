#include<bits/stdc++.h>
using namespace std;

string ans[]={"0","-1","1","7","4","2","6","8","10","18","22","20","28","68","88","108","188","200","208","288","688","888"};
int n;

void solve(){
	cin>>n;
	if(n<=21)cout<<ans[n]<<'\n';
	else{
		int _n=n%7;
		if(_n==0)_n=7;
		_n+=14;
		cout<<ans[_n];
		n-=_n;n/=7;
		for(int i=1;i<=n;++i)cout<<8;
		cout<<'\n';
	}
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int tc;cin>>tc;
	while(tc--){
		solve();
	}
}
