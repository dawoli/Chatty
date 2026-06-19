/*
  abcdef  s1   len=6
  012345     i
  fedcba
  012345    j         i+j==len-1   i=len-1-j   5+0=5==len-1  4+1=5==len-1   i+j=5==len-1  j==len-1-i
 */
#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int main(){
	char s1[1001]={},s2[1001]={};
	cin>>s1;
	int flag=1,len=strlen(s1);
	for(int i=0;i<len;i++)
		s2[len-1-i]=s1[i];	//s2[j]=s1[i],j=len-1-i  s1[i]==s1[len-1-i]  
	//strrev();
	for(int i=0;i<len;i++)
		if(s1[i]!=s2[i]){
			flag=0;break;
	}
	if(flag==1) cout<<"Yes";
	else		cout<<"No";
	return 0;
}
