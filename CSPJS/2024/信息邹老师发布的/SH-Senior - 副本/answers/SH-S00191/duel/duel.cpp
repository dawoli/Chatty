#include <bits/stdc++.h>
using namespace std;

int n,ans,cnt,a[100010],vis[100010],t[100010];
bool flag=true;

int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==2)
			++cnt;
		if(a[i]>2)
			flag=false;
	}
	if(flag){
		printf("%d",max(n-cnt,cnt));
		return 0;
	}
	printf("%d",cnt);
	return 0;
}
