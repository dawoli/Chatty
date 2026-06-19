#include<bits/stdc++.h>
using namespace std;
int a[100005],n,k,st[505][505],ans=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int flag=0;
	bool flaga=1,flagb=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)flaga=0;
		if(a[i]!=0&&a[i]!=1)flagb=0;
	}
	if(flaga==1){
		if(k==1)cout<<n;
		if(k==0)cout<<n/2;
		return 0;
	}
	else if(flagb==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1)ans++;
				else if(a[i]!=a[i+1]){
					ans++;
					i++;
				}
			}
		}
		else if(k==0){
			for(int i=1;i<=n;i++){
				if(a[i]==0)ans++;
				else if(a[i]==a[i+1]){
					ans++;
					i++;
				}
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
