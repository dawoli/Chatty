#include<bits/stdc++.h>
using namespace std;
int n,number=0;
string poker[60]={};
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin>>n;
	number=52-n;
	for(int i=1;i<=n;i++){
		cin>>poker[i];
	}
	sort(poker+1,poker+n+1);
	for(int i=1;i<=n;i++){
		if(poker[i]==poker[i+1]){
			number++;
		}
	}
	cout<<number;
	return 0;
} 
