#include<bits/stdc++.h>
using namespace std;
int a[500005],pre[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	int l=1,cnt=0,r=1;
	while(r<=n){
		for(int i=r;i>=l;i--){
			if((pre[r]^pre[i-1])==k){
				cnt++;
				l=r+1;
				break;
			}
		}
		r++;
	}
	cout<<cnt;
	return 0;
} 
