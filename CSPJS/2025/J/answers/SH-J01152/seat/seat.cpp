#include<bits/stdc++.h>
using namespace std;
int n,m,s[105],t,b,h,l;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
		scanf("%d",&s[i]);
	t=s[1];
	sort(s+1,s+1+n*m,cmp);
    for(int i=1;i<=n*m;i++)
		if(s[i]==t) b=i; 
	l=(b-1)/n+1;
	b=b%n;
	if(b==0) b=n;
	if(l%2==1) h=b;
	else h=n+1-b;
    cout<<l<<" "<<h;
	return 0;
} 
