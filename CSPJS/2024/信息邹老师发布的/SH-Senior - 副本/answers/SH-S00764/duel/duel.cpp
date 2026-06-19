#include<bits/stdc++.h>
using namespace std;
int vis[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n,ans;
	cin>>n;
	ans=n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	sort(a,a+n);
	int last=0;
	for(int i=0;i<n;i+=vis[a[i]]){
		if(last<=vis[a[i]]){
			ans-=last;
			last=vis[a[i]];
		}
		else{
			ans-=vis[a[i]];
		}
	}
	cout<<ans;
	return 0;
}
