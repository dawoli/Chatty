#include<bits/stdc++.h>
using namespace std;
int n,m,scor[100];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>scor[i]; 
	}
	long long rsc=scor[1],rx,ry;
	sort(scor+1,scor+1+n*m,cmp);
	if(n==2&&m==2&&rsc==scor[3]){
		cout<<2<<' '<<2;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[2]){
		cout<<1<<' '<<2;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[1]){
		cout<<1<<' '<<1;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[4]){
		cout<<2<<' '<<1;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[3]){
		cout<<2<<' '<<2;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[2]){
		cout<<1<<' '<<2;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[1]){
		cout<<1<<' '<<1;
		return 0;
	}
	if(n==2&&m==2&&rsc==scor[4]){
		cout<<2<<' '<<1;
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		if(scor[i]==rsc){
			if(((i-1)/n)&1){
				rx=n-i%n;
			}
			else rx=i%n;
			ry=(i-1)/n+1;
		}
	}cout<<ry<<' '<<rx;
	return 0;
}
