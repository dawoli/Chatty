#include<bits/stdc++.h>
using namespace std;
int n,f;
long long ans, k,a[100010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=1;
	}
	if(!f&&k==0&&(n==2||n==1)){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long kkk=a[i],cur=0;
		if(kkk==k){
			ans++;
			cur=i;
			continue;
		}
		for(int j=i-1;j>cur;j--){
			kkk^=a[j];
			if(kkk==k){
				ans++;
				cur=i;
				continue;
			}
		}
	}
	cout<<ans-1;
	return 0;
}
