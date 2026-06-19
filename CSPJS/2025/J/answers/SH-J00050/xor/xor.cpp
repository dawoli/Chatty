#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+7;

int n,k;
int a[N];
int xorz[N];

void solve(){
	cin>>n>>k;
	xorz[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		xorz[i]=xorz[i-1]^a[i];
	}
	
	int ans=0;
	int syg=1;
	for(int i=1;i<=n;i++){
		for(int j=syg;j<=i;j++){
			int z=xorz[i]^xorz[j-1];
			if(z==k){
				ans++;
				syg=i+1;
				break;
			}
		}
	}
	
	cout<<ans;
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	solve();
	
	return 0;
}

