#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

long long n,m,q,l,ans;
long long a[N];
long long sum[N];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(a[i]^sum[i-1]);
	}
	l=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=l;j--){
			if((sum[i]^sum[j-1])==m){
				ans++;
				l=i+1;
				break;
			}
		}
	}
	cout<<ans;
	
	
	return 0;
}
