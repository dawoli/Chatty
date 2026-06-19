#include <bits/stdc++.h>
using namespace std;
int t,n,m,s[10];
string a[6][10];
int main(){
	//freopen("coffee.in","r",std.in);
	//freopen("coffee.out","w",std.out);
	cin>>t;
	for(int o=1;o<=t;o++){
		int k=0;
		for(int i=1;i<=5;i++){
			int f=0;
			for(int j=1;j<=8;j++){
				cin>>a[i][j];
				if(a[i][j] =='math'){
					f++;
				}
			}
			s[i]=f;
		}
		cin<<n<<m;
		for(int i=1;i<=n;i++){
			if(n<=5){
				k=k+s[n];
			}
			if(n<7){
				n++;
			}
			else{
				n=1;
			}
		}
		cout <<k;
	}
	return 0;
} 
