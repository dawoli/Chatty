#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	int n,k,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int l=1;l<=n;l++){
		for(int len=1;len<=n-l+1;len++){
			int r=l+len-1,sum=a[l];
			for(int j=l+1;j<=r;j++){
				sum=sum^a[j];
			}
			if(sum==k){
				ans++;
			}
		}
	}
	cout<<ans;
}
