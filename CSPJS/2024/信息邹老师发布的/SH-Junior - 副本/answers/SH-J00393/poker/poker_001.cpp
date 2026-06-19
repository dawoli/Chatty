#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans=0,p;
string s[60];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		p=0;
		for(int j=1;j<i;j++){
			if(s[i]==s[j])p++;			
		}
		if(p==0)ans++;
	}
	cout<<52-ans;
	return 0;
}
