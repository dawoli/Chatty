#include<bits/stdc++.h>
using namespace std;
long long w[500050],g;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,m;
	cin>>a>>m;
	for(int i=1;i<=a;i++){
		cin>>w[i];
	}
	if(m==0){
		cout<<a/2;
	}
	else{
		for(int i=1;i<=a;i++){
		    if(w[i]==m){
		    	g++;
			}
	    }
	    cout<<g;
	}
	return 0;
} 
