/*
  12341234
  10000000000000000000000000000000000000000
  10000000000000000000000000000000000000010
  2147483647
  10000000000
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char a[1000]={},b[1000]={};
	cin>>a>>b;
	int lena=strlen(a),lenb=strlen(b);
	if(lena!=lenb){
		if(lena>lenb) cout<<a;
		else cout<<b;
	}
	else{//lena==lenb
		if(strcmp(a,b)>0)
			cout<<a;
		else cout<<b;		
	}

	return 0;
}
