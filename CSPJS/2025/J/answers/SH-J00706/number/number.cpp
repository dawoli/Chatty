#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,ans[1000009];
string a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	n=a.size();
	for(ll i=0;i<=n;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	m=b.size();
	for(ll i=0;i<m;i++){
		ans[i]=b[i]-'0';
	}
	sort(ans,ans+m);
	for(ll i=m-1;i>=0;i--){
		cout<<ans[i];
	}
	return 0;
} 
