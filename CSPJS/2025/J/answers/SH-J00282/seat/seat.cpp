#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,r,a=1,b=1;
	cin>>n>>m;
	cin>>r;
	for(int i = 1; i < m*n; i++){
		cin>>x;
		if(r<x){
			if(a%2==1){
				if(b!=n){
					b++;
				}else{
					a++;
				}
			}else{
				if(b!=1){
					b--;
				}else{
					a++;
				}
			}
		}
	}
	cout<<a<<" "<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
