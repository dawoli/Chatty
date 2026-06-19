#include<bits/stdc++.h>
using namespace std;
int a[1000005],l=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0' && s[i]<='9'){
			a[l]=int(s[i])-48;
			l++;
		}
	}
	sort(a,a+l);
	if(a[l-1]==0){
		cout<<0;
		return 0;
	}
	for(int i=l-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

