#include<bits/stdc++.h>
using namespace std;
int a[5060];

int main(){
	ios::sync_with_stdio(false);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,maxn=INT_MIN,sum=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			sum=0,maxn=INT_MIN;
			for(int k=i;k<=j;k++){
				sum+=a[k];
				maxn=max(maxn,a[k]);
			}
			if((j-i+1)>=3&&sum>(2*maxn)) ans++;
		}
	}
	cout<<ans;
	return 0;
}
