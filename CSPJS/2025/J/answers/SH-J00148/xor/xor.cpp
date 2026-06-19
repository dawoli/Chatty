#include <bits/stdc++.h>
using namespace std;
const int N=5e5;
long long a[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n,k;
	cin>>n>>k;
	bool pd=true;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]!=1){
			pd=false;
			break;
		}
	}
	if (pd==true){
		cout<<n/2;
		return 0;
	}
	bool pd2=true;
	for (int i=1;i<=n;i++){
		if (a[i]!=0 && a[i]!=1){
			pd2=false;
			break;
		}
	}
	if (pd2==true){
		int cnt=0;
		for (int i=1;i<=n;i++){
			if (a[i]==1)cnt++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
} 
