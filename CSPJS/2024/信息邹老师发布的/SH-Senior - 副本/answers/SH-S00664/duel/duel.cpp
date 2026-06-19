#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
int n,p,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]>a[p])p++;
	}
	printf("%d",n-p+1);
	return 0;
} 
