#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
int n,q;
string a[N],b[N],s,t;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	while(q--){
		int ans=0;
		string p="";
		cin>>s>>t;
		for(int i=0;i<s.size();i++){
			for(int j=1;j<=n;j++){
				if(s.size()-i<a[j].size())continue;
				if(s.substr(i,a[j].size())==a[j])
					ans+=(t==(p+b[j]+s.substr(i+a[j].size(),s.size()-i-a[j].size())));
			}
			p+=s[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
