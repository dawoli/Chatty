#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int num=0,a[1000050];
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			num++;
			a[num]=s[i]-'0';
		}
	}
	sort(a,a+1+num);
	if(a[num]==0) cout<<0;
	else {
		for(int i=num;i>0;i--){
		    cout<<a[i];
		}
	}
	return 0;
}
