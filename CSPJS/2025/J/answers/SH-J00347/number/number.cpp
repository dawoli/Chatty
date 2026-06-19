#include<bits/stdc++.h>
using namespace std;
int num[15];
int main(){
	string x;
	cin>>x;
	int n=x.size();
	for(int i=0;i<=9;i++) num[i]=0;
	for(int i=0;i<n;i++){
		if(x[i]>='0'&&x[i]<='9') num[x[i]-48]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=num[i];j++) cout<<i;
	}
	return 0;
}
