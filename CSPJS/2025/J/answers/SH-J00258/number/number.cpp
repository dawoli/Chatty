#include<iostream>
#include<cstring>
using namespace std;
int a[17];
string t;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	int f=t.length();
	for(int i=0;i<f;i++)
	if(int(t[i])>=48&&int(t[i])<=57)
	a[int(t[i])-48]++;
	for(int i=9;i>=0;i--)
	    for(int j=1;j<=a[i];j++)
	    cout<<i;
} 
