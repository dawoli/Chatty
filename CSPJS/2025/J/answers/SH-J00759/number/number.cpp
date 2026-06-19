#include<bits/stdc++.h>
using namespace std;
bool q(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);	
	string s;
	cin>>s;
	int ai=0,si=s.size();
	vector <int> a;
	for(int i=0;i<si;i++){
		if(s[i]<='9'&&s[i]>='0'){
			a.push_back(s[i]-'0');
			ai++;
		}
	}
	sort(a.begin(),a.end(),q);
	for(int i=0;i<ai;i++){
		cout<<a[i];
	}	
	return 0;
}
