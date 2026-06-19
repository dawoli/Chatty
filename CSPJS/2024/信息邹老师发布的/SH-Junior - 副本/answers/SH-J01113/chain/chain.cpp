#include<bits/stdc++.h>
using namespace std;
int t;
int n,k,q;
int a[10005][20005];
int l[10005];
bool ans;
void dfs(int step,int cnot,int tgt){
	if(step==0){
		ans=1;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<l[i];j++){
			if(a[i][j]==tgt &&i !=cnot){
				for(int v=max(0,j-k+1);v+1<=j;v++){
					dfs(step-1,i,a[i][v]);
				}
			}
		}
	}
	return;
}
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	scanf("%d",&t);
	for(int times=0;times<t;times++){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=0;i<n;i++){
			scanf("%d",&l);
			for(int j=0;j<l[i];j++){
				scanf("%d",a[i][j]);
			}
		}
		for(int it=0;it<q;it++){
			int c,r;
			scanf("%d%d",&c,&r);
			for(int i=0;i<n;i++){
				for(int j=0;j<l[i];j++){
					if(a[i][j]==c){
						for(int v=max(0,j-k+1);v+1<=j;v++){
							dfs(r,i,a[i][v]);
						}
					}
				}
			}
			if(ans) printf("1");
			else printf("0");
		} 
	}
}
