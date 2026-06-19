/*
  abcdef”旋转一次后变为“fabcde”。
  fabcde
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int k;
	cin>>k;
	int len=s.size();
	for(int i=len-k;i<=len-1;i++){//[x,len-1] len-k=x
		cout<<s[i];
	}	
	for(int i=0;i<s.size()-k;i++)
		cout<<s[i];
	return 0;
}
