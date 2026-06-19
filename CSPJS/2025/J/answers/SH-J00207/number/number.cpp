#include<bits/stdc++.h>
using namespace std;
long long a[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long sum=0;
	string s;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57)a[s[i]-'0']++;		
	}
	for(int i=9;i>=0;i--){
		for(long long j=a[i];j>0;j--)cout<<i;
	}
	return 0;
}
