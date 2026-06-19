#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	long long cnt=0;
	cin>>s;
	for(long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1);
	for(long long i=cnt;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}
