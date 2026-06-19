#include<bits/stdc++.h>
using namespace std;
const int N=100009;
int n,r[N],ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	sort(r+1,r+n+1);
	int j=2;
	for(int i=1;i<=n;i++){
		while(j<=n&&r[j]<=r[i]) j++;
		if(j==n+1){
			ans=n-i+1;
			break;
		}
		j++;
	}
	printf("%d",ans);
	return 0;
}

