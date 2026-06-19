#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	string b="";
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			b+=s[i];
		}
	}
	sort(b.rbegin(),b.rend());
	cout<<b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

