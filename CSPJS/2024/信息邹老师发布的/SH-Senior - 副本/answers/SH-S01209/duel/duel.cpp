#include<bits/stdc++.h>
using namespace std;
int n;
int a[100005];
int cnt=1,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d", &a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			cnt++;
		}
		if(a[i]!=a[i-1]){
			ans=max(ans,cnt);
			cnt=1;
		}
	}
	ans=max(ans,cnt);
	printf("%d", ans);
	return 0;
} 
