#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,sc[105],cnt=1;
	scanf("%d%d%d",&n,&m,&sc[1]);
	for(int i=2;i<=n*m;i++){
		scanf("%d",&sc[i]);
		if(sc[i]>sc[1])cnt++;
	}
	if(cnt%n==0){
		if((cnt/n)%2==1)printf("%d %d\n",cnt/n,n);
		else printf("%d 1\n",cnt/n);
	}
	else if((cnt/n)%2==1)printf("%d %d\n",cnt/n+1,n+1-cnt%n);
	else printf("%d %d\n",cnt/n+1,cnt%n);
	return 0;
}
