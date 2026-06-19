#include<bits/stdc++.h>
using namespace std;
const int N=1000009;
string s;
int num[N],p;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++)
		if(s[i]>='0' && s[i]<='9')num[++p]=s[i]-'0';
	//for(int i=1;i<=p;i++)cout<<num[i]<<" ";
	sort(num+1,num+p+1);
	for(int i=p;i>=1;i--)cout<<num[i];
	return 0;
}
