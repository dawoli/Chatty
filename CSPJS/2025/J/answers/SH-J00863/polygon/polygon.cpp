#include<bits/stdc++.h>
using namespace std;
int n,l[5010];
long long ans;
bool f(int L,int R){
	int sum=0,maxn=0;
	for(int i=L;i<=R;i++){
		sum+=l[i];
		maxn=max(l[i],maxn);
	}
	if(sum>maxn*2)return 1;
	return 0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(f(i,j))ans++;
		}
	}
	ans=ans%998;
	ans=ans%244;
	ans=ans%353;
	cout<<ans;
	return 0;
}
