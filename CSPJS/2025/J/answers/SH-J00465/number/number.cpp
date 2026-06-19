#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> v;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=49){
			continue;
		}
		else
		{
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		cout<<v[i];
	}
	return 0;
} 
