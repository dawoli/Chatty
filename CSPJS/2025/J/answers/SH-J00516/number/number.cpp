#include<bits/stdc++.h>
using namespace std;
string a;
int b[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<10;i++)
		b[i]=0;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0'&&a[i]<='9')
			b[(a[i]-'0')]++;
	for(int i=9;i>=0;i--)
		for(int k=0;k<b[i];k++)
			cout<<i;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
