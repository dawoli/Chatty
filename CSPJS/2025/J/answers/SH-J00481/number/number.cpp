#include<bits/stdc++.h>
using namespace std;
string s;
int num[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int idx=0;
	for(int i=0;i<s.size();i++){
		if(s[i]-'0'>=0&&s[i]-'0'<=9){
			num[idx]=s[i]-'0';
			idx++;
		}
	}
	sort(num,num+idx);
	for(int i=idx-1;i>=0;i--){
		cout<<num[i];
	}
	return 0;
}
//csh 
