#include<bits/stdc++.h>
using namespace std;
int n=1,m,a[105],b,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]>=a[1])b++;
	}
	
	y=(b/(n*2))*2;
	b%=(n*2);
	
	if(b==0){
		x=1;
	}
	
	else if(b<=n){
		y++;
		x=b;
	}
	else{
		y+=2;
		x=n*2-b+1;
	}
	printf("%d %d",y,x);
	return 0;
}
