#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int n,cnt[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++)
		if(s[i]>='0'&&s[i]<='9')
			cnt[s[i]-'0']++;
	for(int i=9;i>=0;i--)
		while(cnt[i]--)cout<<i;
	return 0;
}
