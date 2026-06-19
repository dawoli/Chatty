#include<bits/stdc++.h>
using namespace std;
int n,m,s=1;
int x,y;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	for(int i=2;i<=n*m;++i){
		cin>>a[i];
		if(a[i]>a[1]){
			s++;
		}
	}
	if(s%n==0){
		y=s/n;
		if(y%2==1){
			x=n;
		}
		else{
			x=1;
		}
	}
	else{
		y=(s/n)+1;
		if((y-1)%2==0){
			x=s%n;
		}
		else{
			x=n+1-(s%n);
		}
	}
	cout<<y<<" "<<x<<endl; 
	fclose(stdin);fclose(stdout);
	return 0;
}
