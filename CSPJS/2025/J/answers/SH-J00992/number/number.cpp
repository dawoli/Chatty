#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> v;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length();
	for(int i=0;i<l;i++){
		if(s[i]>='0'&&s[i]<='9'){
			v.push_back(s[i]-'0');
		}
	}sort(v.begin(),v.end(),cmp);
	for(int x:v){
		cout<<x;
	}
	return 0;
}

