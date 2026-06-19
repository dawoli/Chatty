#include<bits/stdc++.h>
using namespace std;
long long n,m,c[505],cnt,ans=1;
bool b=1,f=1;
string s;
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdin);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0) cnt++;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]!='1') b=0;
	}
	if(m==n){
		sort(c+1,c+n+1);
		for(int i=1;i<=n;i++){
			if(c[i]<i) f=0;
		}
		if(f) cout<<"0"<<endl;
		else cout<<"1"<<endl;
	}
	if(b){
		for(int i=1;i<=n-cnt;i++){
			ans*=i;
			ans=ans%998244353;
		}
		cout<<ans<<endl;
	}
	cout<<ans;
}
