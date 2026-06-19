#include<bits/stdc++.h>
using namespace std;
int n,a[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		a[k]++;
	}
	int ans=0;
	for(int i=1;i<=100001;i++){
		ans=max(0,ans-a[i]);
		ans+=a[i];
	}
	cout<<ans;
	return 0;
}
