#include<bits/stdc++.h>
using namespace std;
vector<char>v;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			v.push_back(int(s[i]));
		}
	}
	sort(v.begin(),v.end());
	for(int i=v.size()-1;i>=0;i--){
		if(v[i]=='0'){
			cout<<0;
			break;
		}
		cout<<v[i];
	}
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
