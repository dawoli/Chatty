#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int nums[maxn];
int tong[10];
int main(){
	freopen("number.in","r");
	freopen("number.out","w");
	string s;
	cin>>s;
	int j=0;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i] && '9'>=s[i]){
			nums[j]=s[i]-'0';
			j++;
		}
	}
	for(int i=0;i<j;i++){
		tong[nums[i]]++;
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<tong[i];j++)cout<<i;
	}
	return 0;
}
