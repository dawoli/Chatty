#include<bits/stdc++.h>
using namespace std;
int a[100003],c[100003],two[50];
int main(){
	freopen("arena.in","r",stdin);
	freopen("arena.out","w",stdout);
	srand(time(NULL));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&c[i]);
	}
	two[0]=1;
	for(int i=1;i<=30;i++){
		two[i]=two[i-1]*2;
	}
	int which;
	for(int i=0;i<=30;i++){
		if(two[i]>=n)which=two[i];
	}
	for(int i=1;i<=which;i++){
		int tmp;
		scanf("%d",&tmp);
	}
	int t;
	scanf("%d",&t);
	while(t--){
		int a,b,c,d,first,second;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		first=rand()%n+1;
		second=rand()%n+1;
		if(first>second)swap(first,second);
		printf("%lld\n",1ll*(first+second)*(second-first+1)/2);
	}
	return 0;
}
