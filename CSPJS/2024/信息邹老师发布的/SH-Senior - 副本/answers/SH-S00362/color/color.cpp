#include<bits/stdc++.h>
using namespace std;
int t,n,arr[200009],col[200009],cnt[2];
long long ans;

long long check(){
	long long res=0;
	cnt[0]=cnt[1]=0;
	for(int i=1;i<=n;i++){
//		cout<<col[i]<<' ';
//		if(!cnt[col[i]]) continue;
		if(arr[i]==arr[cnt[col[i]]]&&cnt[col[i]]) res+=arr[i];
		cnt[col[i]]=i;
	}
//	cout<<endl;
//	cout<<res<<endl;
	return res;
}

void dfs(int x){
	if(x>n){
		ans=max(ans,check());
		return;
	}
	col[x]=0;
	dfs(x+1);
	col[x]=1;
	dfs(x+1);
}

int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		ans=0;
		for(int i=1;i<=n;i++) scanf("%d",&arr[i]);
		dfs(1);
		printf("%lld\n",ans);
	}
	return 0;
}
