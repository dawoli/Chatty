#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,k,ls[500005],c1,c0,c;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		cin>>ls[i];
		if(ls[i]==1){
			c++;
			if(c==2){
				c=0;
				c0++;
			}
			c1++;
		}else{
			c=0;
			c0++;
		}
	}
	if(k==1) cout<<c1;
	else cout<<c0;
	return 0;
}
