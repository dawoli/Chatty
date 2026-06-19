#include<bits/stdc++.h>
using namespace std;
int n,a[100009],cnt[100009],ans,maxa;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
		if(x>maxa)maxa=x;
	}
	for(int i=1;i<=maxa;i++){
		a[i]=a[i-1]+cnt[i];
	}
	for(int i=2;i<=maxa;i++){
		if(cnt[i]>0){
			ans+=min(cnt[i],a[i-1]-ans);
		}
	}
	cout<<n-ans;
	return 0;
} 
