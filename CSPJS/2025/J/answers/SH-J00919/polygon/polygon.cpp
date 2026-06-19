#include<bits/stdc++.h>
using namespace std;
int m,n,rf,wz,yj,jl,rjh,rjl;
int a[1010];
bool cmp(int x,int y){
	return x>y;
}
bool check(int x){
	if(x==rf) return true;
	else return false;
}
int main(){
	//freopen("polygon.in","r",stdin);
	//freopen("polygon.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		rf=a[1];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n*m;i++){
		bool flag=check(a[i]);
		if(flag==true) wz=i;
		else continue;
	}
	jl=(wz-1)/n;
	yj=(wz-1)%n;
	if((wz-1)<n){
		rjh=wz;
		rjl=1;
	}
	if((yj==0)&&(jl%2==0)){
		rjh=1;
		rjl=jl+1;
	}
	else if((yj==0)&&(jl%2==1)){
		rjh=n;
		rjl=jl+1;
	}
	else if((yj!=0)&&(jl%2==0)){
		rjl=jl+1;
		rjh=yj+1;
   }
   	else if((yj!=0)&&(jl%2==1)){
   		rjl=jl+1;
   		rjh=yj-1;
   }
   	cout<<rjl<<" "<<rjh;
	return 0;
}
