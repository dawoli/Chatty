#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,score,tep,c,r;/*c¡–r––*/ 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&score);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&tep);
		if(tep>score)cnt++;
	}
	c=cnt/n+1;
	r=(cnt+1)%n;
	if(r==0)r=n;
	if(c%2==0)r=n-r+1;
	printf("%d %d",c,r);
	return 0;
}
