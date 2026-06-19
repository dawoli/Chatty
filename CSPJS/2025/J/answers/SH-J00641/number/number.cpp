#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int b[11]={};
	cin>>a;
	for(int i=0;a[i]!=0;i++){
		if(a[i]-'0'>=0&&'9'-a[i]>=0){
			b[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=b[i];j>0;j--){
			cout<<i;
		}
	}
	return 0;
} 
