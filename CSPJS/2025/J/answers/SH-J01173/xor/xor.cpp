#include <bits/stdc++.h>
using namespace std;
int n,k,i,num[200005],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(i=1;i<=n;i++) cin>>num[i];
	if(k==0){
		for(i=1;i<=n;i++){
			if(num[i]==0) ans++;
		}
	}
	else for(i=1;i<=n;i++)
		if(num[i]==1) ans++;
	cout<<ans;
	return 0;
}
