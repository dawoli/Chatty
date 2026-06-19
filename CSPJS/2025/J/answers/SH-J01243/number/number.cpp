#include<bits/stdc++.h>
using namespace std;
int ton[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9')
		{
			ton[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		//cout<<ton[i]<<" "<<endl;
		for(int j=0;j<ton[i];j++){
			cout<<i;
		}
	}
	return 0;
}
