#include<bits/stdc++.h>
using namespace std;

const int N=1e7+10;
string s;
long long num[N];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int len=0;
	
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			num[++len]=s[i]-'0';
		}
	}
	
	sort(num+1,num+len+1);
	reverse(num+1,num+len+1);
	
	string ans="";
	
	for(int i=1;i<=len;i++){
		ans=ans+char(num[i]+'0');
	}
	
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}
