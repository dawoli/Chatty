#include<bits/stdc++.h>
using namespace std;
string s;
long long j=1,a[10000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(isdigit(s[i])) a[j++]=s[i]-'0';
	}
	sort(a+1,a+j,greater<int>());
	for(long long i=1;i<j;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

