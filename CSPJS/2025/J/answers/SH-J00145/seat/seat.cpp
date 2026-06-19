#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;cin>>n>>m;
	int a;cin>>a;
	int q  =1;
	int s;
	for(int i=1;i<m*n;i++){
		cin>>s;
		if(s>a){
			q++;
		}
	}
	int b,c,d,e;
	d = 2*n;
	b = q%d;
	c = q/d;
	if(b<=n){
		cout<<2*c+1<<" "<<b;
	}else if(b>n){
		e = b-n;
		e = n-e+1;
		cout<<2*c+2<<" "<<e;
	}
	return 0;
}
//3 3 94 95 96 97 98 99 100 93 92

