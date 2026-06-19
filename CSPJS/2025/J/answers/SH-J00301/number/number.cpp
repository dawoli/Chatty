#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a,b;
	string x,num="";
	cin>>x;
	for(int i=0;i<x.size();i++){
		a=x[i];
		if(a-'0'>=0&&'9'-a>=0){
			num+=a;
		}
	}
	for(int i=0;i<num.size();i++){
		for(int j=0;j<num.size();j++){
			if(num[j]<num[j+1]){
				b=num[j+1];
				num[j+1]=num[j];
				num[j]=b;
			}
		}
	}
	cout<<num;
	return 0;
} 
