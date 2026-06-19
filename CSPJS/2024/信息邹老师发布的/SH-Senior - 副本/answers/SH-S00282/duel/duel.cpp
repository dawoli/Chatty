#include<bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,r,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>r;
		a[r]++;
	}
	for(int i=0;i<100000;i++){
		if(a[i]>ans){
			ans=a[i];
		}
	}
	cout<<ans;
	return 0;
}
