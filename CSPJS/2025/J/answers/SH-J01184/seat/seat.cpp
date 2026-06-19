#include<bits/stdc++.h>
using namespace std;
int a[1005];
bool cmp(int a,int b){
	return a>b;
}
int flag[15][15]; 
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
	}
	int ans=a[1];
	int wei=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]>ans){
			wei++;
		}
	}
	int y=wei/n+(bool)(wei%n),x=wei%n;
	if(x==0) x=n;
	if(y%2==0) x=n-x+1;
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
