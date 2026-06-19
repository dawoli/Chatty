#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int nums[10],a;
string s;
char c;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.length();i++){
		c=s[i];
		a=int(c);
		if(a>=97&&a<=122) continue;
		else nums[c-'0']++;
	}
	for(int i=9;i>=0;i--){
		if(nums[i]>0){
			for(int j=1;j<=nums[i];j++) cout<<i;
		}
	}
}
