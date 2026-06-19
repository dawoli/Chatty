#include <bits/stdc++.h>
#include<cstdio> 
using namespace std;
long long a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int k=s.size();
	int t=0;
	for(int i=0;i<=k-1;i++){
		if(s[i]=='1'||s[i]=='2'||s[i]=='3'||s[i]=='4'||s[i]=='5'||s[i]=='6'||s[i]=='7'||s[i]=='8'||s[i]=='9'||s[i]=='0'){
			a[s[i]-48]++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=a[i];j++){
			cout<<i;
		}
	}
	return 0;
} 
