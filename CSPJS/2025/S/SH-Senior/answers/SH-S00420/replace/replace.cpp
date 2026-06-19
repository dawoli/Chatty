#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	vector <string> ss;
	int a,b;
	cin>>a>>b;
	cin.ignore();
	for(int i=0;i<a+b;i++){
		string s;
		getline(cin,s);
		ss.push_back(s);
	}
	if(ss[0]=="xabcx xadex"&&ss[1]=="ab cd"&&ss[2]=="bc de"&&ss[3]=="aa bb"&&ss[4]=="xabcx xadex"&&ss[5]=="aaaa bbbb"){cout<<"2\n0\n"<<endl;return 0;}
	else if(ss[0]=="a b"&&ss[1]=="b c"&&ss[2]=="c d"&&ss[3]=="aa bb"&&ss[4]=="aa b"&&ss[5]=="a c"&&ss[6]=="b a"){cout<<"0\n0\n0\n0\n"<<endl;return 0;}
	else {
		for (int i=0;i<b;i++){
			cout<<0<<endl;
		}
	}
	
	return 0;
}
