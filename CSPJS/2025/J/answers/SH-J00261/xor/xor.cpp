#include<bits/stdc++.h>
using namespace std;
const int N=5e5+9;
int n;
long long k,cnt;
long long a[N];
int f;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=1) f=1;
		if(a[i]!=1 && a[i]!=0) f=2;
	}
	
	if(f==0){
		if(k==0) {
			cout<<n/2;
			return 0;
		}
	}
	if(f==1){
		if(k==1){
			for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
			cout<<cnt;
			return 0;
		}
		if(k==0){
			for(int i=1;i<=n;i++) if(a[i]==1) cnt++;
			cout<<cnt/2;
			return 0;
		}
	}
	
	int i=1;
	while(i<=n){
		long long ans=0;
		for(int j=i;j<=n;j++) {
			ans^=a[j];
			if(ans==k){
				i=j+1;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
