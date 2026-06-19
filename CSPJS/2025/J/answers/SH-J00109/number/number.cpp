#include<bits/stdc++.h>
using namespace std;

string s;
int nums[1000005],id=1;

int main(){
	//²»ÄÜÉ¾£¡£¡£¡£¡£¡£¡ 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			nums[id++]=s[i]-'0';
		}
	}
	id--;
	sort(nums+1,nums+id+1);
	for(int i=id;i>=1;i--){
		cout<<nums[i];
	}
	return 0;
}

