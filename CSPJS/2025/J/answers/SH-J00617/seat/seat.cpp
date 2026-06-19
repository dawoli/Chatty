#include<bits/stdc++.h>
using namespace std;
int n,m;
int num,rnk;
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d",&num);
	rnk=1;
	for(int i=2;i<=n*m;i++){
		int c;
		scanf("%d",&c);
		if(c>num)rnk++;
	}
	int lne,col;
	lne=rnk/n;
	if(rnk%n!=0)lne++;
	col=rnk%n;
	if(col==0)col=n;
	if(lne%2!=1)col=(n+1)-col;
	printf("%d %d",lne,col);
	return 0;
}
