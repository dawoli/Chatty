#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,a[200005],r,c;
bool sf[200005];
//int dp[11][1001][2001];
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d%d",&n,&k,&q);
		for(int j=1;j<=n;j++){
			int l1;
			scanf("%d",&l1);
			memset(a,0,sizeof(a));
			for(int l=1;l<=l1;l++){
				scanf("%d",&a[l]);
			}
			for(int l=1;l<=l1;l++){
				if(a[l]==1){
					for(int _=l+1;_<=l+k-1;_++){
						sf[a[_]]=1;
					//	dp[j][1][_-l+1]=a[_];
					}
				}
			}
		}
      //  int flag=1;
		for(int m=1;m<=q;m++){
			scanf("%d%d",&r,&c);
			if(r==1){
				if(sf[c]==1){
					printf("1\n");
				}else{
					printf("0\n");
				}
			}else{
			//	flag=0;
			}
		}/*if(flag==0){
			//寻找上一步末尾数字开头的
			for(int m=2;m<=q;m++){
				
			}
		}	*/		
	}
	
	
	
	
	return 0;
}
