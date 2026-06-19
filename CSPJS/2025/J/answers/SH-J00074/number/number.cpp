#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	vector<int> v;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		if (int(s[i])>=int('0')){
			if (int(s[i])<=int('9')){
				v.push_back(int(s[i])-int('0'));
			}
		}
	} 
	sort(v.begin(),v.end());
	for (int i=v.size()-1;i>=0;i--){
		cout<<v[i];
	}
	cout<<endl;
	return 0;
}
