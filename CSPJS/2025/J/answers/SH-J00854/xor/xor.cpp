#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
struct num{
	int l,r;
}qj[500005];
int idx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=1,flag2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			flag1=0;
			if(a[i]!=0){
				flag2=0;
			}
		}
	}
	if(k==0){
		if(flag1){
			cout<<n/2<<endl;
			return 0;
		}
		else if(flag2){
			int ans=0;
			int k=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					ans++;
					ans+=k/2;
					k=0;
				}
				else{
					k++;
				}
			}
			cout<<ans<<endl;
			return 0;
		}
	}
	else if(k==1&&flag2){
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i];
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		a[i]^=a[i-1];
	}
	for(int j=n;j>=1;j--){
		for(int i=j;i>=1;i--){
			if((a[j]^a[i-1])==k){
				idx++;
				j=i-1;
				i=j+1;
			}
		}
	}
	cout<<idx<<endl;
	return 0;
}
