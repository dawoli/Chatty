#include<bits/stdc++.h>
using namespace std;
string s,ans;
int n;
int nums[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			int k=s[i]-'0';
			nums[k]++;
			//cout<<k;
		}
	}
	for(int i=9;i>=0;i--){
		if(nums[i]){
			for(int j=1;j<=nums[i];j++){
			ans+=char('0'+i);
			}
		}
		
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
