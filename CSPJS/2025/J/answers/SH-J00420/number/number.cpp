#include<bits/stdc++.h>
using namespace std;
string s;
char c[1000000];
int cs,sz;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	sz=s.size();
	for(int i=0;i<sz;i++){
		if(s[i]>='0'&&s[i]<='9'){
			c[cs]=s[i];
			cs++;
		}
	}
	sort(c,c+cs);
	for(int i=cs-1;i>=0;i--) printf("%c",c[i]);
	return 0;
}
