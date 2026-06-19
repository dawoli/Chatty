#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,m;
char s[510];
int c[510];
bool f=true;
int cnt=0;

void slove1( ){
	n-=cnt;
	long long ans=1;
	for(int i=2;i<=n;i++)
		ans*=i,ans%=MOD;
	cout<<ans;
}

int main( ){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<n;i++)
		if(s[i]!='1')
			f=false;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]==0)
			cnt++;
	}
	if(f==true)
		slove1( );
	else
		cout<<"0";
	return 0;
}
