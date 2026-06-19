#include<bits/stdc++.h>
using namespace std;
string s;
int ans,a[100003],j; 
int main(){	 
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>47&&s[i]<58){
			a[j]=s[i]-48;
			j++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int k=0;k<j;k++){
			if(a[k]==i){
				cout<<i;
}
		}
	}
} 						 
