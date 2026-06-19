#include<bits/stdc++.h>
#define N 500009
using namespace std;
int n,k;
int a[N];
bool isone(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return 0;
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==1){
		if(a[1]==k) cout<<1;
		else cout<<0<<endl;
	}else if(isone()&&k==0){
		cout<<n/2<<endl;
	}else if(n==2){
		if(a[1]==k&&a[2]==k){
			cout<<2<<endl;
			return 0;
		}
		if(a[1]==k&&a[2]!=k){
			cout<<1<<endl;
			return 0;
		}
		if(a[1]!=k&&a[2]==k){
			cout<<1<<endl;
			return 0;
		}
		if((a[1]^a[2])==k&&a[1]!=k&&a[2]!=k){
			cout<<1<<endl;
			return 0;
		}
	}else{
		if(k==0){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) cnt++;
				if(a[i]==1&&a[i-1]==1){
					cnt++;
				}
			}
			cout<<cnt<<endl;
		}else if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
			}
			cout<<cnt<<endl;
		}else{
			cout<<0;
		}
	}
	return 0;
}
