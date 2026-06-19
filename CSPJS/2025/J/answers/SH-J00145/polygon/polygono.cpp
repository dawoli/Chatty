#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
int a;
cin>>a;
long long  q[a];
bool w = 1;
for(int i=0;i<a;i++){
	cin>>q[i];
	if(q[i] != 1){
		w=0;
	}
}
if(a == 3){
	int b = max(q[0],max(q[1],q[2]));
	int c = q[0]+q[1]+q[2];
	 if(c>2*b){
	 	cout<<"1";
	 	
	 }else{
	 	cout<<"0";
	 }
}

}
