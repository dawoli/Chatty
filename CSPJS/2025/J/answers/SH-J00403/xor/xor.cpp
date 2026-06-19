#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k1,ans=0;cin>>n>>k1;
	int a[n];
	bool vis[n]={};
	int max_len=n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<max_len;i++)
		for(int j=0,sum=0;j<n-i;j++,sum=0){
			for(int k=0;k<=i;sum^=a[k+j],k++)
				if(vis[k+j]) goto ccontinue;
			if(sum==k1){
				ans++;
				for(int k=0;k<=i;k++) vis[k+j]=1;
				max_len=0;
				int maxlen=0;
				for(int i=0;i<n;i++){
					maxlen++;
					if(vis[i]==1) maxlen=0;
					max_len=max(max_len,maxlen);
				}
			}
			ccontinue:;
		}
	cout<<ans;
	return 0;
} 
