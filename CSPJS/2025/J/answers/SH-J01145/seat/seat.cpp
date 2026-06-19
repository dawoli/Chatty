#include <bits/stdc++.h>
using namespace std;
int n,m,t,rx,ry;
struct node{
	int sc,yx;
}a[110];
bool cmp(node x,node y){
	return x.sc>y.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	t=m*n;
	for(int i=1;i<=t;i++){
		cin>>a[i].sc;
		a[i].yx=i;
	}
	sort(a+1,a+t+1,cmp);
	for(int i=1;i<=t;i++){
		if(a[i].yx==1){
			if(i%n==0){
				rx=i/n;
			}else{
				rx=i/n+1;
			}
			if(rx%2==1){
				ry=(i-(rx-1)*n)%n;
				if(ry==0){
					ry=n;
				}
			}else{
				ry=n-1+(i-(rx-1)*n)%n;
			}
		}
	}
	cout<<rx<<" "<<ry;
	return 0;
}
