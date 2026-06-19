#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,t;
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++) scanf("%d",&a[i]);
	t=a[1];
	sort(a+1,a+(n*m)+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==t){
			printf("%d ",(i-1)/n+1);
			if(((i-1)/n+1)&1) printf("%d\n",((i-1)%n)+1);
			else printf("%d\n",n-((i-1)%n)); 
			break;
		}
	}
	return 0;
}
