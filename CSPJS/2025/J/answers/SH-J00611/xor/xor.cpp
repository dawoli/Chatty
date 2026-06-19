#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],b[500010],cnt,vis[500010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i]^b[i-1];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			if ((b[j]^b[i-1])==k){
				int f=0;
				for (int l=i;l<=j;l++){
					if (vis[l]==1){
						f=1;
						continue;
					}
				}if (f){
					continue;
				}for (int l=i;l<=j;l++){
					vis[l]=1;
				}
				cnt++;
			}
			
		}
	}
	cout<<cnt;
	return 0;
} 
