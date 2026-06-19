#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	short lst[1000005]={0};
	int c=0;
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++)if(s[i]>='0'&&s[i]<='9')lst[c++]=s[i]-'0';
	sort(lst,lst+c);
	for(int i=c-1;i>=0;i--)cout<<lst[i];
	return 0;
}
