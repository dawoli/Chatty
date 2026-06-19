#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int length=a.length();
	int b[100000],lenb=0;
	for(int i=length-1;i>=0;i--){
		if(a[i]>='0'&&a[i]<='9'){
			b[lenb]=a[i]-48;
			lenb++;
		}
	}
	sort(b,b+lenb);
	for(int i=lenb-1;i>=0;i--){
		cout<<b[i];
	}
	return 0; 
} 
