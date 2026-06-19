#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int needs[10]={0,1,0,2,1,0,0,0};
		int nums[10]={0,-1,1,7,4,2,6,8};
		int n;
		cin>>n;
		if(n<=7){
			cout<<nums[n]<<endl;
			continue;
		}
		string num;
		while(n>=7){
			n -= 7;
			num = '8'+num;
		}
		int m = needs[n];
		if(m==1) num[0]='0';
		if(m==2) num[0]='2';
		m += n;
		num = char(nums[m]+'0')+num;
		cout<<num<<endl;
	}
	return 0;
}
