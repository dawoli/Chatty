#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],s,f,x,y;
bool cmp(int a,int b){
	return a > b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	s = a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i = 1;i <= n*m;i++){
		if(s == a[i]){
			f = i;
			break;
		}
	}
	x = f/n;
	if(f%n != 0){
		x++;
	}
	y = f%n;
	if(x%2 == 0){
		y = n-y+1;
	}
	cout<<x<<" "<<y<<endl;
	return 0;
}
