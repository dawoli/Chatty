#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	int v=0;
	cin>>a;
	int b[a];
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	sort(b,b+a);
	if(a=3){
		for(int i=0;i<a;i++){
		v+=b[i];
		}
		if(v>b[2]*2){
			cout<<1;
		}else{
			cout<<0;
		}	
	}
	else{
		cout<<(a-1)*(a-2)/2;
	}
	return 0;
}
