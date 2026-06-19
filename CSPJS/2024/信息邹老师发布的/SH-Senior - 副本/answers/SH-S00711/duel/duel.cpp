#include<bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int x;
int mx,mn;
int d;
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	mx = 0;
	for(int i = 1;i <= n;i++){
		scanf("%d",&x);
		a[x]++;
		mx = max(a[x],mx);
	}
	printf("%d",mx);
	return 0;
} 
