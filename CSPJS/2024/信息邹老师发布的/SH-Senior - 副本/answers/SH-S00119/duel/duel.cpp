#include<bits/stdc++.h>
using namespace std;
int cards[100001];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&cards[i]);
	}
	sort(cards,cards+n);
	int j=0,ans=n;
	for(int i=1;i<n;i++){
		if(cards[i]==cards[j]) continue;
		ans--;
		j++;
	}
	printf("%d",ans);
	return 0;
}
