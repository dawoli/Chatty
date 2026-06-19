#include<bits/stdc++.h>
using namespace std;
struct qianzhuihe{
	int l,r;
}sum[500001];
int n,k,a[500001],ans=0,top=0;
int c[500001];
int main(){
	freopen("xor.in","R",stdin);
	freopen("xor.out","W",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		c[i]=c[i-1]^a[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if((c[i-1]^c[j])==k){
				sum[++top].l=i,sum[top].r=j;
				break;
			}
		}
	}
	for(int i=1;i<=top;i++){
		int x=1,m=sum[i].r;
		for(int j=i+1;j<=top;j++){
			if(sum[j].l<=m){
				continue;
			}
			m=sum[j].r;
			x++;
			printf("%d\n",x);
		}
		ans=max(ans,x);
		
	}
	printf("%d",ans);
	return 0;
}
