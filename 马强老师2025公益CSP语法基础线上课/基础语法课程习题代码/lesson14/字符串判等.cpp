/*
  
 */
#include<bits/stdc++.h>
using namespace std;
int main(){
	char s1[300]={},s2[300]={};
	char st1[300]={},st2[300]={};
	int len1=0,len2=0;
	cin.getline(s1,300);
	cin.getline(s2,300);
	for(int i=0;i<strlen(s1);i++){// abcd ef  aa
		if(s1[i]!=' ')
			st1[len1++]=s1[i];
	}
	for(int i=0;i<strlen(s2);i++){// abcd ef  aa
		if(s2[i]!=' ')
			st2[len2++]=s2[i];
	}	
	if(strcmp(st1,st2)==0) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
