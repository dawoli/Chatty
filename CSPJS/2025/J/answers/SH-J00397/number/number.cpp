#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	char x;
	cin >> s;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			x=s[j];
			if(x>'A'){
				s[j]=s[s.size()];
			}
			if(s[j]<=s[j+1]){
			int n;
			n=s[j];
			s[j]=s[j+1];
			s[j+1]=n;
		    }
		}
	}
	cout << s << endl;
	return 0;
}
