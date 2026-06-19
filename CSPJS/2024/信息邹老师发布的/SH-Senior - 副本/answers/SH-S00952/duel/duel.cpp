#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N],n,num[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),++num[a[i]];
	int sum=0;
	for(int i=1;i<=100000;++i){
		sum-=min(sum,num[i]);
		sum+=num[i];
	}
	printf("%d",sum);
	return 0;
}
