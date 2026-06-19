#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	scanf("%d",&n,&m);
	for(int i=0;i<n;i++){
		int s;
		scanf("%d",&s);
	}
	for(int i=0;i<n;i++){
		int c;
		scanf("%d",&c);
	}
	int t=1;
	for(int i=1;i<=n;i++){
		t=t*i;
		t=t%998244353;
	}
	printf("%d",t);
	return 0;
} 
