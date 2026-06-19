#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	ll nums[10]={0,0,0,0,0,0,0,0,0,0};
	for(ll i=0;i<strlen(s.c_str());i++){
		if(s[i]>='0'&&s[i]<='9')nums[s[i]-'0']++;
	}
	for(ll i=9;i>-1;i--){
		if(nums[i]>0){
			for(ll j=0;j<nums[i];j++)cout<<i;
		}
	}
	return 0;
}
