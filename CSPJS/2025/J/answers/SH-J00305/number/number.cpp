#include <bits/stdc++.h>
using namespace std;
int a[10+10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x,ans,y;
	cin>>x;
	for(int i=0;i<x.size();i++){
		if(x[i]>='0'&&x[i]<='9'){
			a[x[i]-'0']++;
		}
	}for(int i=9;i>=0;i--){
		for(int j=0;j<a[i];j++){
			cout<<char(i+'0');
		}
	}
	return 0;
}
