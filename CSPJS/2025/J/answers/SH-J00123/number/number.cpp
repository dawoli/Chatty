#include <bits/stdc++.h>
using namespace std;
string s;
int len;
bool fla=true;
bool cmp(char a,char b) {
	return a>b;
}
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	len=s.size();
	for(int i=0;i<len;i++)//是否只包含数字 
	    if(s[i]<='z'&&s[i]>='a') {
	    	fla=false;
	    	break;
		}
	if(fla) {
		sort(s.begin(),s.end(),cmp);//全是数字就直接排序 
		cout<<s;
		return 0;
	} else {
		string an="";//构造另一个只包含数字的字符串 
		for(int i=0;i<len;i++) {
			if(isdigit(s[i])) an+=s[i];//是数字就加进去 
		}
		sort(an.begin(),an.end(),cmp);
		cout<<an;
		return 0;
	}
	return 0;
}
