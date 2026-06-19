#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(k==0){
		cnt=0;
		for(int i=1;i<=n;i++)if(a[i]==0)cnt++;
		cout<<cnt;
		return 0;
	}
	if(k==1){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(i==1)continue;
			if(abs(a[i]-a[i-1])==1){
				int MAX=max(a[i],a[i-1]);
				if(MAX%2==1)cnt++;
			}
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}
