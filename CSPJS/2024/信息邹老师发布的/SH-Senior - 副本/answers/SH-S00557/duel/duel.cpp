#include<bits/stdc++.h>
using namespace std;
int n,a[100010],st[100010],mi,ans;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int w=1;w<=n;w++)scanf("%d",&a[w]);
	sort(a+1,a+n+1);
	for(int w=1;w<=n;w++)if(a[w]>a[mi]){
		st[mi]=1;
		while(st[mi])mi++;
	}
	for(int w=1;w<=n;w++)if(!st[w])ans++;
	printf("%d",ans);
	return 0;
}
