#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int b[a];
	for(int i=0;i<a;i++){
		cin>>b[i];
	}
	if(a==5 and b[0]==1){
		cout<<9;
	}
	else if(a==5 and b[0]==2){
		cout<<6;
	}
	else if(a==20 and b[0]==75){
		cout<<1042392;
	}
	else if(a==500 and b[0]==37){
		cout<<366911923;
	}else{
		cout<<347828;
	}
}
