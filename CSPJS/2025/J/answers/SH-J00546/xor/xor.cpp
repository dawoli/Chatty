#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
ll n,k;
ll a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	ll a0=0,a1=0;
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(a[i]==0)	a0++;
		else if(a[i]==1)	a1++;
	}
	if(a0==0){
		if(k==1){
			cout << n << endl;
		}else if(k==0){
			cout << n/2 << endl;
		}
	}else{
		if(k==1){
			cout << a1 << endl;
		}else if(k==0){
			ll al = 0;
			for(int i=0; i<n; i++){
				if(a[i]==1&&a[i+1]==1){
					al++;
					i++;
				}
			}
			cout << a0+al << endl;
		}
	}
	return 0;
}
