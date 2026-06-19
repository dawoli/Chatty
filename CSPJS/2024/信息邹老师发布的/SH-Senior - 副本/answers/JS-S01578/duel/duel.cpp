#include<bits/stdc++.h>
using namespace std;
int n;
int r[100005]={};
int cnt[100005]={};
int k;
int ans=0;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
		cnt[r[i]]++;
	}
	for(int i=1;i<=100000;i++){
		ans=max(ans,cnt[i]);
	}
	cout<<ans;
	return 0;
} 
