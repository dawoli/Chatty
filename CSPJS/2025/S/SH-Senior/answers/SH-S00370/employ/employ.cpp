#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int c[505];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++) cin>>c[i];
	bool pian=true;
	for(int i=0;i<s.size();i++)
		if(s[i]!='1')
			pian=false;
	if(pian){
		int cnt=0;
		for(int i=0;i<n;i++)
			if(c[i]==0)
				cnt++;
		int num=0;
		for(int i=0;i<n;i++){
			if(c[i]>cnt)
				num++;
			else cnt++;
		}
		int sum=1;
		for(int i=2;i<=num;i++){
			sum*=i;
			sum%=mod;
		}
		cout<<sum;
	}else if(m==n){
		bool flag=false;
		for(int i=0;i<n;i++)
			if(c[i]==0)
				flag=true;
		if(!pian || flag) cout<<0;
		else{
			int ans=1;
			for(int i=2;i<=n;i++)
				ans=ans*i%mod;
			cout<<ans;
		}
	}
	return 0;
}
