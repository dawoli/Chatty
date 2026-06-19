#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==n){
		string s;
		cin>>s;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
			else {
				long long ans=1;
				for(int i=1;i<=n;i++){
					ans=(ans*i)%998244353;
				}
				cout<<ans<<endl;
				return 0;
			}
		}
	}
	string s;
	cin>>s;
	bool q=true;
	long long w=n;
	int a[n+1]={};
	for(int i=0;i<s.size();i++)if(s[i]!='1')q=false;
	for(int i=1;i<=n;i++){cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(q){
		for(int i=1;i<=n;i++){
		if(a[i]<=n-w)w--;
		cout<<a[i]<<endl;
	}
	cout<<w<<endl;
		long long ans=1;
		for(int i=1;i<=w;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans<<endl;
		return 0;
}
	cout<<0;
	return 0;
}
