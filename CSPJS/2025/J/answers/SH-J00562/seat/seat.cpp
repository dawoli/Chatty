#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,nm,t,c,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	nm=n*m;
	for(int i=1;i<=nm;i++) scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+nm+1,cmp);
	for(int i=1;i<=nm;i++){
		if(a[i]==t){
			t=i;
			break;
		}
	}
	c=(t-1)/n+1;
	c&1?r=(t-1)%n+1:r=n-(t-1)%n;
	printf("%d %d",c,r);
	return 0;
}
