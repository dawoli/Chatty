#include<bits/stdc++.h>
using namespace std;
long long nums[1000001],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(long long i=1;i<=s.size();i++) if(isdigit(s[i-1])) nums[++cnt]=s[i-1];
	sort(nums+1,nums+cnt+1);
	string k="";
	for(long long i=1;i<=cnt;i++) k+=nums[cnt+1-i];
	cout<<k<<endl;
	return 0;
}
