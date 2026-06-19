#include<bits/stdc++.h>
using namespace std;
int t,n,s,x,p,ans,m[10]={0,0,1,7,4,2,6,8};
void f(int minn,int maxn,bool a){
	if(a)
		m[6]=0;
	if(maxn>7)
		maxn=7;
	if(minn<2)
		minn=2;
	ans=m[minn];
	p=minn;
	for(int i=minn+1;i<=maxn;++i)
		if(m[i]<ans){
			p=i;
			ans=m[i];
		}
	printf("%d",ans);
	s=s-p;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	scanf("%d",&t);
	for(int i=0;i<t;++i){
		scanf("%d",&n);
		s=n;
		if(n<=1)
			printf("-1");
		else{
			for(int i=0;i<(n+6)/7;++i)
				if(i)
					f(s-7*((n+6)/7-i-1),s-2*((n+6)/7-i-1),1);
				else
					f(s-7*((n+6)/7-i-1),s-2*((n+6)/7-i-1),0);
			
		}
		printf("\n");
	}
	return 0;
}
