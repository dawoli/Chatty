#include<bits/stdc++.h>
using namespace std;
int a,b,c[1000000],d;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>a>>b;
	for(int i=1;i<=a;i++){
		cin>>c[i];
		if(c[i]==1)
			d++;
		}
	if(d==a&&b==0){
		cout<<d/2;
	}
	else{
		if(b==1)
			cout<<d;
		else
			cout<<a-d+d/2;
	}
}
