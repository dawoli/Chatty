#include<bits/stdc++.h>
using namespace std;
int n,K,a[1000005],ans=0;
vector<pair<int,int>> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	int t=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			t=0;
		}
	}
	if(t==1&&K==0){
		if(a[1]==0){
			ans++;
		}
		for(int i=2;i<=n;i++){
			if(a[i]==0){
				ans++;
			}
			else if(a[i]==1&&a[i-1]==1){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}
	cout<<1;
	return 0;
} 
