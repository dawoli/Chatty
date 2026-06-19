#include<bits/stdc++.h>
using namespace std;
char a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			ans++;
			a[ans]=s[i];
		}
	}
	sort(a+1,a+ans+1);
	if(a[ans]==0){
		cout<<"0";
	}
	else{
		for(int i=ans;i>=1;i--){
			if(a[i]!=0){
				cout<<a[i];
			}
			else{
				cout<<"0";
				break;
			}
		}
	}
  return 0;
}
