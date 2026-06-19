#include <bits/stdc++.h>
using namespace std;
struct rule{
	string ex,ad,prefix,postfix;
};
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	vector<rule> rules;
	rules.reserve(n);
	for(int i=0;i<n;i++){
		string a,b;
		cin>>a>>b;
		int prefix=0,postfix=0;
		for(int j=0;j<a.size();j++){
			if(a[j]==b[j]){
				prefix++;
			}else{
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]==b[j]){
				postfix++;
			}else{
				break;
			}
		}
		if(prefix+postfix<a.size()){
			rule rul;
			rul.ex=a.substr(prefix,a.size()-postfix-prefix);
			rul.ad=b.substr(prefix,a.size()-postfix-prefix);
			rul.prefix=a.substr(0,prefix);
			rul.postfix=a.substr(a.size()-postfix);
			//cout<<"prefix:"<<rul.prefix<<" postfix:"<<rul.postfix<<" a:"<<rul.ex<<" b:"<<rul.ad<<endl;
			rules.push_back(rul);
		}
	}
	for(int qwerty=0;qwerty<q;qwerty++){
		string a,b;
		cin>>a>>b;
		if(a.size()!=b.size()){
			cout<<0<<endl;
			continue;
		}
		int prefix=0,postfix=0;
		for(int j=0;j<a.size();j++){
			if(a[j]==b[j]){
				prefix++;
			}else{
				break;
			}
		}
		for(int j=a.size()-1;j>=0;j--){
			if(a[j]==b[j]){
				postfix++;
			}else{
				break;
			}
		}
		string dif1=a.substr(prefix,a.size()-postfix-prefix);
		string dif2=b.substr(prefix,a.size()-postfix-prefix);
		int cnt=0;
		for(int i=0;i<rules.size();i++){
			if(dif1==rules[i].ex&&dif2==rules[i].ad){
				bool flag=true;
				if(prefix>=rules[i].prefix.size()){
					for(int j=1;j<=rules[i].prefix.size();j++){
						if(rules[i].prefix[rules[i].prefix.size()-j]!=a[prefix-j]){
							flag=false;
							break;
						}
					}
				}else{
					flag=false;
				}
				if(postfix>=rules[i].postfix.size()){
					for(int j=0;j<rules[i].postfix.size();j++){
						if(rules[i].postfix[j]!=a[a.size()-postfix+j]){
							flag=false;
							break;
						}
					}
				}else{
					flag=false;
				}
				if(flag){
					cnt++;
				}
			}
		}
		cout<<cnt<<endl;
	}
}
