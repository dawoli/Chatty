#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,a,s,high=1;
	scanf("%d%d%d",&n,&m,&a);
	for(int i=0;i<m*n-1;i++){
		scanf("%d",&s);
		if(s>a)high++;
	}
	if(high%(2*n)<n && high%(2*n)!=0)printf("%d %d\n",(high)/n+1,high%(2*n));
	else if(high%(2*n)==0)printf("%d %d\n",(high)/n,1);
	else if(high%(2*n)==n)printf("%d %d\n",(high)/n,n);
	else printf("%d %d\n",(high-1)/n+1,n-high%n+1);
	return 0;
}
/*
4 4

*/
