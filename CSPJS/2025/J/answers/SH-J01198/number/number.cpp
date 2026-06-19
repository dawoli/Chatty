#include<bits/stdc++.h>
using namespace std;
long long bucket[20];
string s;
bool f=false;
int main(){
	//取消注释!!!!!!!!!!!!!!!!!!!! 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	//取消注释!!!!!!!!!!!!!!!!!!!! 
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			int x=s[i]-'0';
			bucket[x]++;
		}
	}
	for(int i=9;i>=0;i--){
		if(bucket[i]>0){
			if(i!=0){
				f=true;
			}
			if(i==0&&f==false){
				cout<<"0";
				return 0;
			}
			for(int j=1;j<=bucket[i];j++){
				cout<<i;
			}
		}
	}
	return 0;
}
