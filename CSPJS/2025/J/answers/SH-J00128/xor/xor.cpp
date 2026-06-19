#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005];
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		if (a[i]==1){
			cnt1+=1;
		}
		if (a[i]==0){
			cnt0+=1;
		}
	}
	if (k==1){
		cout<<cnt1;
	}
	else{
		cout<<max(cnt0,cnt1/2);
	}
	return 0;
}
