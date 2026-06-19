#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	short t;
	int n,m,l,v,a,b,c,useless;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&n,&m,&l,&v);
		int ans = 0;
		for(int i = 0;i<n;i++){
			scanf("%d %d %d",&a,&b,&c);
			if(b>v) ans++;
		}
		for(int i = 0;i<m;i++){
			scanf("%d",&useless);
		}
		printf("%d %d\n",ans,m-1);
	}
	return 0;
}
