#include <bits/stdc++.h>
using namespace std;
int k,n,j;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>k;
	while(k--){
		cin>>n;
		if(n%7==0){
			for(int i=n/7;i>0;i--){
				j*=10;
				j+=8;
			}
			cout<<j<<endl;
			j=0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
