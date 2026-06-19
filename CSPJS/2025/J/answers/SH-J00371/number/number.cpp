#include <bits/stdc++.h>
using namespace std;

string s;
vector<int> v;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int n=s.size();
	if(n==1){
		cout<<s;
		return 0;
	}
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			s[i]-='0';
			v.push_back(s[i]);
		}
	}
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++)
		cout<<v[i];
	return 0;
}
