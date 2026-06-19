#include<bits/stdc++.h>
using namespace std;
int so[100009];
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	set<int> solve;
	getline(cin,s);
	if(s.size()==1){
		cout<<s<<endl;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]>="1" and s[i]<="9") so[i]+=s[i];
		cout<<so[i]-'0'; 
	}sort(so+1,so+s.size()+1);
	return 0;
} 
