#include<bits/stdc++.h>
using namespace std;
const int N=1e3+9;
int a[N],n,m,x,rk;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",a+i);
	x=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)
		if(a[i]==x){
			rk=n*m-i;
			break;
		}
	printf("%d %d",rk/n+1,((rk/n)%2?n-(rk%n):(rk%n)+1));
	return 0;
}
