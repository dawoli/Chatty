#include<bits/stdc++.h>
using namespace std;
int c[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9') c[i]=s[i]-'0';
	}
	int a=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='a'&&s[i]<='z') a++;
	}
	sort(c,c+s.size());
	long long n=0;
	for(int i=s.size()-1;i>=0;i--){
		n+=c[i];
		n*=10;
	}
	n/=10;
	int m=1;
	for(int i=1;i<=a;i++){
		m*=10;
	} 
	n/=m;
	cout<<n<<endl;
	return 0;
}
