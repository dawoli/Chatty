#include<iostream> 
#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;cin>>a;
	int q =a.size();
	long long qwe[11];
	for(int i=0;i<10;i++){
		qwe[i] =0;
	}

	for(int i=0;i<q;i++){
		if(a[i]>='0'&&a[i]<='9'){
			qwe[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<qwe[i];j++){
			cout<<i;
		}
	}
}

/*
for(int i=0;i<10;i++){
		cout<<i<<qwe[i]<<endl;
	}
*/
