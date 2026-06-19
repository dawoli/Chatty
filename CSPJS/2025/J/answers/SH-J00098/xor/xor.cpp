#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500010],ans,cnt;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int q=i;q<=j;q++){
				ans=a[i];
				ans^=a[q];
			}
			if(ans==k){
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}

