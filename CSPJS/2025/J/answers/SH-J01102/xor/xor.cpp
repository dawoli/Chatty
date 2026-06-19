#include <bits/stdc++.h>
using namespace std;

int n,k,a[500005],cnt0,cnt1,ans,pre[500005];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
		if(a[i]==0) cnt0++;
		if(a[i]==1) cnt1++;
	}
	if(cnt1==n&&k==0) cout<<n/2<<endl;
	else if(cnt0+cnt1==n&&(k==0||k==1)){
		if(k==0) cout<<cnt0<<endl;
		else
			cout<<cnt1<<endl;
	}else{
		int l=1,r=1;
		while(true){
			if(l>n) break;
			if(r>n){
				l++;
				r=l;
				if(l>n) break;
			}
			if((pre[r]^pre[l-1])==k){
				ans++;
				l=r+1;
			}
			r++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
