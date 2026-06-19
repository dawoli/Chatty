#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int p[500005];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	p[0]=0;
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]^a[i];
//		cout<<p[i]<<" ";
	}
//	cout<<endl;
	int cnt=0;
	int le=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=le;j--){
			if((p[i]^p[j])==k){
//				cout<<i<<" "<<j<<endl;
				cnt++;
				le=i;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
