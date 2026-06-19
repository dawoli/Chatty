#include<bits/stdc++.h>
using namespace std;
string a[53];
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	int n,ans=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	    if(a[i]!=a[i-1])
	        ans++;
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
