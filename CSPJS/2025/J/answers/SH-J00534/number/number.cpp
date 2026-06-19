#include<bits/stdc++.h>
using namespace std;
int nums[100000];
string str;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>str;
	int si=str.size();
	int js=0;
	int i;
	for(i=0;i<si;i++){
		if(str[i]>='0' && str[i]<='9'){
			nums[js]=str[i]-'0';
			js++;
		}
	}
	if(js>1){
		for(i=0;i<=js;i++){
			for(int j=0;j<=js-1;j++){
				if(nums[j]<=nums[j+1]){
					int k=nums[j];
					nums[j]=nums[j+1];
					nums[j+1]=k;
				}
			}
		}
	}
	
	for(i=0;i<js;i++){
		cout<<nums[i];
	}
} 
