//RP++
#include <bits/stdc++.h>
#define N 500020
using namespace std;
int a[N];
int main(){
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	int n,k,cnt=0,lr=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int l=1;l<=n-1;l++){
		if(l<=lr) continue;
		for(int r=l;r<=n;r++){
			int t=a[l];
			for(int j=l+1;j<=r;j++){
				t^=a[j];
			}
			//cout<<l<<' '<<r<<' '<<t<<' '<<lr<<endl;
			if(t==k){
				cnt++;
				lr=r;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
