#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int b[500005];
bool vis[500005];
long long ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=b[i-1]^a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			int num=b[i]^b[j-1];
			if(num==k){
				bool f=0;
				for(int l=j;l<=i;l++){
					if(vis[l]){
						f=1;
						break;
					}
				}
				if(f)continue;
				ans++;
				for(int l=j;l<=i;l++){
					vis[l]=1;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
