#include<bits/stdc++.h>
using namespace std;

string a;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int n;
	cin>>a;
	n=a.length();
	for(int i=9;i>=0;i--){
		for(int j=0;j<n;j++){
			if(int(a[j])-48==i){
				cout<<i;
			}
		}
	}
	return 0;
}
