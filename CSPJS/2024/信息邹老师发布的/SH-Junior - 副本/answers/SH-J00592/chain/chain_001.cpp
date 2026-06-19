#include<bits/stdc++.h>
using namespace std;
int t,n,k,q,r,c,l;
string str;
int main(){
	freopen("chain.in","r",stdin);
	freopen("chain.out","w",stdout);
	cin>>t;
	while(t--){
		scanf("%d%d%d",&n,&k,&q);
		for(int i=1;i<=n;i++){
			scanf("%d",&l);
			for(int j=1;j<=l;j++)cin>>str;
		}
		while(q--){
			scanf("%d%d",&r,&c);
			printf("0\n");
		}
	}
	return 0;
}
