#include<bits/stdc++.h>
using namespace std;
int nums[100000];
bool check(char n){
	return n-'0'>=0&&n-'0'<=9;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int l=s.length(),d=0;
	for(int i=0;i<l;i++){
		if(check(s[i]))nums[d++]=s[i]-'0';
	}
	sort(nums,nums+d);
	for(int i=d-1;i>=0;i--)cout<<nums[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
