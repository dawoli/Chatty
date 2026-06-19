#include<bits/stdc++.h>
using namespace std;
string s;
int num[10];
bool check;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(unsigned long long i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			num[s[i]-'0']++;
			if(s[i]!='0'){
				check=1;
			}
		}
	}
	if(!check){
		cout<<0;
		return 0;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<num[i];j++){
			printf("%d",i);
		}
	}
	return 0;
} 
