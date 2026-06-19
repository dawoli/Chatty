#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[100005],used[100005];
bool comp(int x,int y){
	return x<y;
}
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1,comp);
	if(n==1){
		printf("1");
		return 0;
	}
	int i=1,j=2;
	while(j<=n){
		while(a[j]==a[i]) j++;
		if(a[j]>a[i]){
			ans++;
			i++;
			j++;
		}
	}
	printf("%d",n-ans);
	return 0;
}
