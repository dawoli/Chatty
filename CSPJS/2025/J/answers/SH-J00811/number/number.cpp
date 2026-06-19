#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >>s;
	vector<int> a;
	for(int i=0;i<s.size();i++){
		if(s[i]<='9' && s[i]>='0'){
			a.push_back(s[i]-'0');
		}
	}
	sort(a.begin(),a.end(),greater<int>());
	for(int i=0;i<a.size();i++){
		if(i==0 && a[i]==0){
			cout <<0;
			break;
		}else{
			cout << a[i];
		}
	}
	return 0;
}
