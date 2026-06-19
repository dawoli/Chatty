#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
ll ans=52;
string pk[55];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>pk[i];
	}
	sort(pk+1,pk+n+1);
	for(int i=1;i<=n;i++){
		if(pk[i]!=pk[i-1]){
			ans--;
		}
	}
	cout<<ans;
	return 0;
}
