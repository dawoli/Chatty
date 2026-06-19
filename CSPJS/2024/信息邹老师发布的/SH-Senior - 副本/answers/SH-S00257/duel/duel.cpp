#include<bits/stdc++.h>
using namespace std;
int a[100005],t[100005],pre[100005]/*之前有多少比他弱的*/,n,maxn;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		maxn=max(a[i],a[i-1]);
	}
	int ans=n;
	sort(a+1,a+n+1);
	for(int i=1;i<=maxn;i++){
		pre[i]=0;
	} 
	for(int i=1;i<=maxn;i++){
		pre[i]=t[i]+pre[i-1];
	} 
	
	for(int i=1;i<=maxn;i++){
		if(t[i]>=pre[i-1]){
			ans-=pre[i-1];
			for(int j=i;j<=maxn;j++){
				pre[j]-=pre[i-1];
			}
		}
		else{
			ans-=t[i];
			for(int j=i;j<=maxn;j++){
				pre[j]-=t[i];
			}
		}
	} 
	cout<<ans<<endl;
	return 0;
} 
