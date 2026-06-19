#include<bits/stdc++.h>
using namespace std;
string s;
vector<char> ans;
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if(s[i]>=48 && s[i]<58){
			ans.push_back(s[i]);
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(int i=0; i<ans.size(); i++){
		cout<<ans[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
