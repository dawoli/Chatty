#include<bits/stdc++.h>
using namespace std;
int num[200001],b[200001],book[200001],t,n;
int dfs(int a){
	int c,max=-1;
	if(a==n+1){
		for(int l=2;l<=n;l++){
			for(int m=l;m>=0;m--){
				if(b[m]==b[l]&&num[m]==num[l])c+=num[l];
			}
		}if(c>=max)max=c;
		c=0;
		return max;
	}
	for(int k=1;k<=a;k++){
		if(!b[k]){b[k]=1;}
		dfs(a+1);
		b[k]=0;
	}
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&n);
		for(int j=1;j<=n;j++){
			scanf("%d",&num[j]);
		}printf("%d",dfs(1));printf("\n");
		
	}
	return 0;
}
