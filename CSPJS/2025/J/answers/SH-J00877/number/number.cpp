#include<bits/stdc++.h>
using namespace std;
string str;int s[10000050],l;
int main(){
	freopen("number.in","r",stdin);freopen("number.out","w",stdout);
	cin>>str;
	for(int i=0;i<str.length();i++){
		if(str[i]>='0'&&str[i]<='9')s[++l]=int(str[i]-'0');
	}sort(s+1,s+1+l);
	for(int i=l;i>=1;i--)cout<<s[i];cout<<endl;
	return 0;
}
