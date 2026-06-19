#include <bits/stdc++.h>
using namespace std;
string s;
int n,m,a;
void nice(){
	long long ans=1,mod=998244353;
	for(int i=1;i<=n;i++){
		ans=ans*i%mod;
	}
	cout<<ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int bo=1,len=s.size();
	for(int i=0;i<len;i++)
		if(s[i]=='0'){
			bo=0;
			break;
		}
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a;
		if(a==0)cnt++;
	}
	n-=cnt;
	cout<<n<<'\n';
	if(bo)nice();
	else cout<<0;
	return 0;
} 
