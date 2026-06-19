#include <bits/stdc++.h>
using namespace std;
int t,n,y;
int s[19]={6,2,5,5,4,5,6,3,7,6};
long long m;
int main(){
	freopen("sticks.in","r","in");
	freopen("sticks.out","w","out");
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		if(n==1){
			cout<<"-1";
		}
		else{
			for(int x=1,a;;x++){
				for(a=1;a<14285;a++){
					for(int n=0,m=1;n<a;n++){
						m*=10;
					}
					if(x%m==x){
						m-=1;
						break;
					}
				}
				for(;m>=10;){
					y+=s[x/m];
					m=m/10;
				}
				if(y==n){
					cout<<x;
					break;
				}
			}
		}
	}
	return 0;
}
