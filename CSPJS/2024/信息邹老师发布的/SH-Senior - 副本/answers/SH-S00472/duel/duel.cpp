#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,a[N];
int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	int cont=1,ans=0,now=a[1],last=0;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cont++;
		if(a[i]!=a[i-1]||i==n){
			ans+=min(cont,last);
			last=max(cont,last);
			cont=1;
		}
	}
	printf("%d",last);
	return 0;
}
