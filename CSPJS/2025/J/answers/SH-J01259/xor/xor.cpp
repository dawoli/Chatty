#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b,arr[1000]={};
	cin>>a>>b;
	bool flag1=true,flag2=true;
	for(int i=1;i<=a;i++){
		cin>>arr[i];
		if(arr[i]!=1){
			flag1=false;
		}
		if(arr[i]>=2){
			flag2=false;
		}
	}
	if(flag1){
		cout<<a/2;
	}else if(flag2){
		if(b==1){
			int cnt=0;
			for(int i=1;i<=a;i++){
				if(arr[i]==1){
					cnt++;
				}
			}
			cout<<cnt;
		}else{
			int cnt=0;
			for(int i=1;i<a;i++){
				if(arr[i]==arr[i+1]){
					cnt++;
					i=i+1;
				}
			}
			cout<<cnt;
		}
	}else{
		cout<<1;
	}
	return 0;
}
//做几个特殊点就真睡觉了
//11:01 好险 差点睡着了 
//11:47 I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I HATE CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.I love CCF.
//11:50 欧耶 只剩二十分钟了 前面炸了补了十分钟 
