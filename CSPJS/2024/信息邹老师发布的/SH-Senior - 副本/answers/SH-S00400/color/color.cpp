#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int T,n,a[N];
int c[N];
int ans;
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					c[j]=a[i];
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans+=c[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
