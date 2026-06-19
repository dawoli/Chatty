#include<bits/stdc++.h>
using namespace std;
int a[505];
long long sum(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans+=a[i];
	}
	return ans;
}
int maxm(int l,int r){
	int ans=0;
	for(int i=l;i<=r;i++){
		ans=max(ans,a[i]);
	}
	return ans;
}
int main(){
	freopen("polygon1.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n-i+1;j++){
			cout<<i<<" "<<j+i<<" "<<sum(i,j+i)<<" "<<maxm(i,j+i)<<" "<<(sum(i,j+i)>2*maxm(i,j+i))<<endl;
			if(sum(i,j+i)>2*maxm(i,j+i)) ans++;
		}
	}
	cout<<ans;
}
