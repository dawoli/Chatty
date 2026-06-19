#include<bits/stdc++.h>
using namespace std;
int n,a[100005],vis[100005],b[100005],d,now,ans,go[100005];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]==0)b[++d]=a[i];
		vis[a[i]]++;
		go[a[i]]++;
	}
	sort(b+1,b+1+d);
	now=1;
	for(int i=2;i<=d;){
		if(i==now||go[b[i]]==0){
			i++;
			continue;
		}
		if(go[b[i]]<vis[b[now]])vis[b[now]]-=vis[b[i]],go[b[i]]=0;
		else{
			vis[b[now]]=0;
			go[b[i]]-=vis[b[now]];
			now++;
		} 
	}
	for(int i=1;i<=d;i++){
		ans+=vis[b[i]];
	}
	cout<<ans;
	return 0;
}
