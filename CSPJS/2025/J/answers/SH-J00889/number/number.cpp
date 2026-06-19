#include<bits/stdc++.h>
using namespace std;
string s;
int num[15];
int n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]>='0'&&s[i]<='9'){
			num[s[i]-'0']++;
		} 
	} 
	bool flag=0;
	for(int i=9;i>=0;i--){
		if(i==0&&!flag){
			cout<<0;
		}else{
			for(int j=1;j<=num[i];j++){
				cout<<i;
				flag=1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
