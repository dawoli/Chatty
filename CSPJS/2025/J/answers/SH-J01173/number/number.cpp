#include <bits/stdc++.h>
using namespace std;
int num[10],i,j;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(i=0;i<a.length();i++)
		if(a[i]-'0'>=0&&a[i]-'0'<=9) num[a[i]-'0']++;
	for(i=9;i>=0;i--)
		for(j=1;j<=num[i];j++) cout<<i;
	return 0;
}
