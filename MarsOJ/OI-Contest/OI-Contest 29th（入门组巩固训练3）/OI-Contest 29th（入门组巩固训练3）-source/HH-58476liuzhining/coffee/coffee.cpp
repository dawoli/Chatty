#include<bits/stdc++.h>
using namespace std;
long long T,n,m,z[10];
string s;
char c;

int main(){
	freopen("r","coffee.in",stdin);
	freopen("w","coffee.out",stdout);
	cin>>T;
	while(T--){
		for(int  i=1;i<=5;i++){
			int js=0;
			for(int j=1;j<=8;j++){
				cin>>s;
				if(s[0]=='m'){
					js++;
				}
			}
			z[i]=z[i-1]+js;
		}
		z[6]=z[5];z[7]=z[5];
		cin>>n>>m;
		long long cf=0;
		if(m!=1){
			n-=(7-m+1);
			cf+=z[7]-z[m-1];
		}
		cf+=(n/7*z[7])+z[n%7];
		printf("%lld\n",cf);
	}
	return 0;
}

