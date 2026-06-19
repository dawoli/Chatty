#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	long long a=1;
	cin>>n>>m;
	string s;
	cin>>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
		if(c==0) cnt++;
	}
	n-=cnt;
	if(m>n){
		cout<<0;
		return 0;
	}
	cout<<"\n"<<n<<" ";
	for(int i=n;i>=1;i--){
		a=(a*i)%mod;
	}
	cout<<a;
	return 0;
}
