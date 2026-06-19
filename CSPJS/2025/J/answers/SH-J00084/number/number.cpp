#include<bits/stdc++.h>
using namespace std;
string s;
int cnt[11],n;
int main(){
	freopen("number.in","r",stdin); 
	freopen("number.out","w",stdout); 
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		for(int j=0;j<cnt[i];j++)
			cout<<i;
}
