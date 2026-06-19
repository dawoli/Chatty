#include<bits/stdc++.h>
using namespace std;
const int maxn = 55;
int a[maxn],b[maxn],c[maxn];
int main(){
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	int T; scanf("%d",&T);
	while(T--){
		int n,ans=0; scanf("%d",&n);
		for(int i = 0 ; i < n ; i ++) scanf("%d",&a[i]);
		for(int i = 0 ; i < (1 << n) ; i ++){
			for(int j = 0 ; j < n ; j ++){
				b[j] = i & (1 << j);
			}
			memset(c,0,sizeof c);
			int res = 0;
			for(int j = 0 ; j < n ; j ++){
				int pos = -1;
				for(int k = 0 ; k < j ; k ++) if(b[k] == b[j] && a[k] == a[j]){
					c[j] = a[j];
				}	
			}
			for(int j = 0 ; j < n ; j ++) res += c[j];
			ans = max(ans,res);
		}
		printf("%d\n",ans);
	}
	return 0;
}
