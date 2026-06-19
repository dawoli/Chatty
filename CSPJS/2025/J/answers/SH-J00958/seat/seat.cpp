#include<bits/stdc++.h>
using namespace std;
int n,m,r,l,x,y,num;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>r;
	l=1;
	for(int i=2;i<=n*m;i++){
		cin>>num;
		if(num>r){
			l++;
		}
	}
	x=(l-1)/n+1;
	y=l-(x-1)*n;
	if(x%2==0){
		y=n-y+1;
	} 
	cout<<x<<' '<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
