#include<bits/stdc++.h>
using namespace std;
int a[105];
int d,e;
bool flag=false;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1){
			d=a[i];
		}
	}
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++){
		if(a[i]==d){
			e=n*m-i+1;
		}
	}	
	int c;
	int r;
	if(e%m==0){
		c=e/m;
		flag=true;
	}else{
		c=e/m+1;
	}
	if(c%2==0){
		if(flag){
			r=1;
		}else{
			r=m-e%m+1;
		}
	}else{
		if(flag){
			r=m;
		}else{
			r=e%m;
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
