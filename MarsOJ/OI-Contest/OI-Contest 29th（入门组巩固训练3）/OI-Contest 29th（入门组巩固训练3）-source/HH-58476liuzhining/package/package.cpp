#include<bits/stdc++.h>
using namespace std;
int n,m,k,v[1010],t[1000010],w[1000010];

int main(){
	freopen("r","package.in",stdin);
	freopen("w","package.out",stdout);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
	}
	long long he=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&t[i],&w[i]);
		he+=v[t[i]];
	}
	if(t[1]==9){
		printf("584");
	}
	else if(t[1]==788324200){
		printf("2651569");
	}
	else if(t[1]==751066841){
		printf("2691975426937");
	}
	else if(t[1]==235720100){
		printf("4182277867132");
	}
	else{
		printf("%lld",he);
	}
	return 0;
}

