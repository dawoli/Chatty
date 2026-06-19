#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,k;
	cin>>n>>k;
	ll *a=new ll[n+1],*pre=new ll[n+1],*he=new ll[n+1];
	pre[0]=0;he[0]=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=a[i]^pre[i-1];
		he[i]=he[0];
		for(int j=i-1;j>=0;j--){
			if((pre[i]^pre[j])==k){
				he[i]=j;
				break;
			}
		}
	}
	//now pre is dp
	for(int i=1;i<=n;i++){
		if(he[i]==-1){
			pre[i]=pre[i-1];
		}else{
			pre[i]=max(pre[i-1],pre[he[i]]+1);
		}
	}
	cout<<pre[n];
	return 0;
} 
