#include<bits/stdc++.h>
using namespace std;
int a[500005],n,k,ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			a[i]=-1;
			ans++;
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=n-i+1;j++){
			if(a[j]==-1&&a[j+1]==-1)a[j]=-1;
			else{
				a[j]=(a[j]|a[j+1])-(a[j]&a[j+1]);
				if(a[j]==k){
					ans++;
					a[j]=-1;
				}
			}
			
			
		}
	}
	cout<<ans;
	return 0;
} 
