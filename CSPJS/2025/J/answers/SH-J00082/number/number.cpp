#include<bits/stdc++.h>
using namespace std;
long long a[800100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sa,s;
	cin>>sa;
	for(int i=0;i<sa.size();i++){
		if(isdigit(sa[i]))s+=sa[i];
	}
	for(int i=0;i<s.size();i++){
		a[i]=s[i]-'0';
	}
	sort(a,a+s.size());
	for(int i=s.size()-1;i>=0;i--){
		if(a[s.size()-1]!=0)cout<<a[i];
		else{
			cout<<"0";
			return 0;
		}
	}
	return 0;
}
