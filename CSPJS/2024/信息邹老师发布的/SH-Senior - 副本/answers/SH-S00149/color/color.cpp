#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[200010];
int b[200010];
int ans;
void dfs(int m,int c){
	b[m]=c;
	if(m==n){
		int ansl=0;
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(b[i]==b[j]){
					if(a[i]==a[j]){
						ansl+=a[j];
					}
					break;
				}
			}
		}
		ans=max(ans,ansl);
		return;
	}
	dfs(m+1,0);
	dfs(m+1,1);
	return;
}
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
    scanf("%d",&t);
    while(t>0){
    	ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		dfs(1,0);
		printf("%d\n",ans);
		t-=1;
	}
}
