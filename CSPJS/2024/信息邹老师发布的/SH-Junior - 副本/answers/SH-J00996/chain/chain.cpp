#include<bits/stdc++.h>
using namespace std;
int test,n,k,q,l[100001],a[200001];
char s;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&test);
	for(int i=1;i<=test;i++){
		scanf("%d%d%d",&n,&k,&q);
		int len=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&l[i]);
			for(int j=1;j<=l[i];j++){
				scanf("%d",&a[i+len]);
			}
			len+=l[i];
		}
		for(int i=1;i<=q;i++){
			int r,c;
			scanf("%d%d",&r,&c);
			if(r%2==1){
				printf("1\n");
			}
			else{
				printf("0\n");
			}
		}
	}
	return 0;
}
