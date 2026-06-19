#include<iostream>
int n,a[5001];
int f(int i,int sum,int max,int m){
	if(i==n-1)return (m>=3)&&(sum>max*2);
	int x=f(i+1,sum+a[i+1],std::max(max,a[i+1]),m+1);
	int y=f(i+1,sum,max,m);
	return x+y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	std::cin>>n;
	for(int i=0;i<n;i++)std::cin>>a[i];
	std::cout<<f(0,0,0,0)+f(0,a[0],a[0],1);
}
