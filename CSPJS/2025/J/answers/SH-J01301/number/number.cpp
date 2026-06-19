#include<bits/stdc++.h>
using namespace std;
string s;
int num,cnt[15];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if(s[i]>='0'&&s[i]<='9') cnt[int(s[i]-'0')]++;
	bool flag=false;
	for(int i=9;i>=1;i--)
		if(cnt[i]>0) {
			flag=true;
			for(int j=1;j<=cnt[i];j++) printf("%d",i);
		}
	if(!flag) printf("0");
	else {
		for(int j=1;j<=cnt[0];j++) printf("0");
	}
	return 0;
}
