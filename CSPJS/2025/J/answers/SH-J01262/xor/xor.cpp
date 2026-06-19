#include<bits/stdc++.h>
using namespace std;
int num[500010];
long long a[1000010];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,cnt=1,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=2;j<=n;j++){
			a[cnt]=num[i];
			for(int k=i+1;k<=j;k++){
				a[cnt]^=num[k];
			}
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(a[i]==k) ans++;
	}
	cout<<ans;
	return 0;
}
