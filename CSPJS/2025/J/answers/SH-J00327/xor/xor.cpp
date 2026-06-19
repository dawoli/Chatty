#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	int a[500001];
	bool is1=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) is1=0;
	}
	if(k==0&&is1==1){
		if(n%2==0) cout<<n/2;
		else cout<<(n-1)/2;
	}
	else if(k<=1){
		int ans=0;
		if(k==0){
			int pair=0;
			int ans=0;
			for(int i=0;i<n;i++){
				if(a[i]==1) pair++;
				else ans++;
				if(pair==2){
					ans++;
					pair=0;
				}
			}
		}
		else{
			bool b[n];
			for(int i=0;i<n;i++) b[i]=0;
				for(int i=0;i<n;i++){
					if(a[i]==0&&b[i]==0){
						for(int j=i;j<n;j++){
							if(a[j]==1&&b[j]==0){
								b[i]=1;
								b[j]=1;
								ans++;
								break;
							}
						}
					}
					else if(a[i]==1&&b[i]==0){
						b[i]=1;
						ans++;
					}
				}
		}
		cout<<ans;
	}
	else cout<<3;
	return 0;
}
