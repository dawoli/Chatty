#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,r[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&r[i]);
	}
	sort(r+1,r+1+n);
	ans=0;
	int now=n-1;
	for(int i=n;i>=1;i--){
		while(now>=1&&r[now]>=r[i]){
			now--;
		}
		if(now<=0) break;
		ans++;
		now--;
	}
	cout<<n-ans;
	return 0;
}
