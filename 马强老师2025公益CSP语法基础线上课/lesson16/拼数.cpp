#include<bits/stdc++.h>
using namespace std;
int main(){
	string s[20]={};
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	//假设第1个是最大的，s[1]保存最大的s[1]--[2,n], s[2]--[3,n],s[3]--[4,n]
	for(int k=1;k<=n;k++){
		for(int i=k+1;i<=n;i++){
			if(s[k]+s[i]<s[i]+s[k]){
				//交换
				swap(s[k],s[i]);
			}
		}				
	}
	for(int i=1;i<=n;i++)
		cout<<s[i];
	
	return 0;
}
