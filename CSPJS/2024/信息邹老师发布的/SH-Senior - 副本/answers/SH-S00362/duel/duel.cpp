#include<bits/stdc++.h>
using namespace std;
int n,ton[100009],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		ton[x]++;
		ans=max(ans,ton[x]);
	}
	cout<<ans;
	return 0;
} 
