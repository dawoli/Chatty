#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int j=0,a[1145140];
	bool f=0;
	cin>>s;
	for(char c:s){
		if(c>='0'&&c<='9')a[j++]=c-'0';
		if(c>'0'&&c<='9')f=1;
	}
	sort(a,a+j,cmp);
	if(!f){
		cout<<0;
		return 0;
	}
	for(int i=0;i<j;i++)cout<<a[i];
}
