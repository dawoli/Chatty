#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int n,m,a[maxn];
bool cmp(int x,int y){
	return x>y;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)scanf("%d",&a[i]);
	int x=a[1];
	sort(a+1,a+n*m+1,cmp);
	int l=1,r=n*m;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]>x)l=mid+1;
		else r=mid;
	}
	int idx=l;
	if(idx%n==0){
		printf("%d ",idx/n);
		if((idx/n)%2==0)printf("1\n");
		else printf("%d\n",n);
	}
	else if(idx%n==1){
		idx--;
		printf("%d ",(idx/n)+1);
		if((idx/n)%2==0)printf("1\n");
		else printf("%d\n",n);
	}
	else{
		printf("%d %d\n",(idx/n)+1,idx%n);
	}
	return 0;
}
