#include<bits/stdc++.h>
using namespace std;
int num[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int pos=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[pos++]=s[i]-'0';
		}
	}
	sort(num,num+pos);
	for(int i=pos-1;i>=0;i--)
		cout<<num[i];
	return 0;
} 
