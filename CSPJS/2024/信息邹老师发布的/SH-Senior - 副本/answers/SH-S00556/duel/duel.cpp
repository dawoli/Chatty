#include<bits/stdc++.h>
using namespace std;
int n,r[100010],a[100010];
int main(){
freopen("duel.in","r",stdin);
freopen("duel.out","w",stdout);
scanf("%d",&n);
for(int i=1;i<=n;i++){
	scanf("%d",r+i);
}
sort(r,r+n+1);
int l=1,i,m=n;
for(int i=2;i<=n;i++){
	if(r[i]>r[l]){
		m--;
		l++;
	}
}
printf("%d",m);
return 0;
}
