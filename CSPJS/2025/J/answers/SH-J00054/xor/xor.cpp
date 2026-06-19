#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[MAXN],p=0,d=1,dd=0,e=0,f=1,ff=0;
	bool A=true,b=true,c=true;
	scanf("%d%d",&n,&k);
	a[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=1)A=false;
		if(a[i]!=0&&a[i]!=1)b=false;
		if(a[i]==1)p++;
		if(a[i]==a[i-1])d++;
		else{
			d=1;
			dd+=d/2;
		}
		if(a[i]==0)e++;
		if(a[i]!=a[i-1])f++;
		else{
			f=1;
			ff+=f/2;
		}
	}
	if(A==true){
		if(k==1)printf("%d",n);
		else if(k==0)printf("%d",n/2);
	}
	else if(b==true){
		if(k==1)printf("%d",max(p,dd));
		else if(k==0)printf("%d",max(e,ff));
	}
	return 0;
}
