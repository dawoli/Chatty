#include<bits/stdc++.h>
using namespace std;
int n[11]={6,2,5,5,4,5,6,3,7,6},t,a;
int main(){
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a;
		if(a<9){
			cout<<n[a];
		}
	}
	return 0;
	
}
