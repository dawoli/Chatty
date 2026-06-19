#include<bits/stdc++.h>
using namespace std;
int v[15];
char a[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int l=strlen(a);
	for(int i=0;i<l;++i)
		if(a[i]>='0'&&a[i]<='9') v[a[i]-'0']++;
	for(int i=9;i>=0;--i)
		for(int j=1;j<=v[i];++j) cout<<i;
}
