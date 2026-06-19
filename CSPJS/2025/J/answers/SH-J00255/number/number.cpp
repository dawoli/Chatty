#include<bits/stdc++.h>
using namespace std;
string str;
int nums[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	bool flag=true;
	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if(ch>='0'&&ch<='9'){
			nums[ch-'0']++; 
			if(ch!='0') flag=false;
		}
	}
	if(flag) cout<<0<<endl;
	else{
		string ans;
		for(int i=9;i>=0;i--){
			for(int j=1;j<=nums[i];j++){
				ans+=(i+'0');
			}
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
