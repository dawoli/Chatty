#include<iostream>
#include<string>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s; 
	int count[10]={0};
	for(int i=0;i<<s.size();++i){
		char c=s[i];
		if(c>='0'&&c<='9'){
			count[c-'0']++;
		}
	}
		string result;
		for(int i=9;i>=0;--i){
	result+=string(count[i],'0'+i);
	}
	cout<<result<<endl;
	return 0;
}
