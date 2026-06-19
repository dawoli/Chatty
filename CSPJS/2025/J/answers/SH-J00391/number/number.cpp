#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000009],cnt;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
		if('0'<=s[i]&&s[i]<='9'){
			cnt++;
			a[cnt]=(int)(s[i]-'0');
		}
	sort(a+1,a+cnt+1);
	for(int i=cnt;i>0;i--)
		cout<<a[i];
	return 0;
}
