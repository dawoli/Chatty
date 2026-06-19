#include<bits/stdc++.h>
using namespace std;
int m,n,a,c=1;
void walk(int i,int j,int k){
	if(k==1){
		cout<<i<<" "<<j<<endl;
		return;
	}
	if(i%2)
		if(j==n)
			walk(i+1,j,k-1);
		else
			walk(i,j+1,k-1);
	else
		if(j==1)
			walk(i+1,j,k-1);
		else
			walk(i,j-1,k-1);
}
int main(){
	freopen("seat.in","r",stdin); 
	freopen("seat.out","w",stdout);
	scanf("%d%d%d",&n,&m,&a);
	for(int i=1,t;i<n*m;i++){
		scanf("%d",&t);
		c+=t>a;
	}
	walk(1,1,c);
}
