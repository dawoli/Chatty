#include <bits/stdc++.h>
using namespace std;
int a[1000009]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	bool pd=true;
	int an=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[an]=s[i]-'0';
			if(a[an]!=0){
				pd=false;
			}
			an++;
		}
	}
	sort(a,a+an);
	if(pd) cout<<0;
	else{
		for(int i=an-1;i>=0;i--)
			cout<<a[i];
	}
	
	return 0;
}
