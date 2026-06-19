#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int b;
	cin>>s;
	for(int i=1;i<s.size();i++){
		for(int j=1;j<s.size();j++){
			if (s[j]>s[j-1])
			{
				b=s[j];
				s[j]=s[j-1];
				s[j-1]=b;
			}
		}
		
	}
	cout<<s;
	return 0;
}
