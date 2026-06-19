#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum^=a[k];
			}
			if(sum==k){
				ans++;
				i=j+1;
				continue;	
			}
		}
	}
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
