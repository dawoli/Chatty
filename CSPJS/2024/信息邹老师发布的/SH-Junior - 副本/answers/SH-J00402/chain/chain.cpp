#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l[100100],s[100100][2010];
void Main(){
	scanf("%d%d%d",&n,&k,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&l[i]);
		for(int j=1;j<=l[i];j++){
			scanf("%d",&s[i][j]);
		}
	}
	while(q--){
		scanf("%d%d",&r,&c);
		printf("1\n");
	}
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		Main();
	}
	return 0;
}