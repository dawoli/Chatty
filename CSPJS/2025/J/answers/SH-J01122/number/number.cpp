#include<iostream>
#include<cstring>
using namespace std;
string s;
int a[10]={};
int main(){
	cin>>s;
	for(int i=0;i<strlen(s.c_str());i++)if(s[i]>47&&s[i]<58){
		a[(int)s[i]-48]++;
	}
	for(int i=9;i>-1;i--)for(int j=0;j<a[i];j++)cout<<i;
}
