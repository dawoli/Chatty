#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string m="";
	cin >> m;
	int a[500006]={};
	int n=0;
	for (int i=0;i<m.length();i++){
		if('0'<=m[i]&&m[i]<='9')
		{
			n++;
			a[n]=m[i]-'0';
		}
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		cout << a[i];
	}
	cout << "\n";
	return 0;
}
