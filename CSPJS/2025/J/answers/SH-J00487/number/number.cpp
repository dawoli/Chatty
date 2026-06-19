#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1005];
	int n=1&&2&&3&&4&&5&&6&&7&&9;
	cin>>s;
	if(s.size()==1){
	    cout<<s;
	    return 0;
	}
	for(int i=0;i<s.size();++i){
		if(s[i]==n){
			if(s[i]<s[i+1]){
				swap(s[i],s[i+1]);
				cout<<s;
			}
		}
	}	
} 
