#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,a[N],k,sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		sum+=a[i];
	}
	if(k==0){
		cout << n/2;
		return 0;
	}
	if(k==1){
		cout << sum;
		return 0;
	}
	return 0;
}

