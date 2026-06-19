#include<bits/stdc++.h> 
using namespace std;
int c[100100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b,d;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]<='9'&&a[i]>='0')b+=a[i];
	}
	for(int i=0;i<b.size();i++)c[i]=b[i];
	sort(c,c+b.size());
	int n=b.size();
	for(int i=0;i<n;i++)b[i]=c[i];
	for(int i=n-1;i>=0;i--)cout<<b[i];
	return 0;
}
