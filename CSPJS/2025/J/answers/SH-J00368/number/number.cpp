#include<bits/stdc++.h>
using namespace std;
int a[1000010],k;
int main(){
	freopen("r","number.in",stdin);
	freopen("w","number.out",stdout);
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			k++;
			a[k]=s[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	for(int i=k;i>=1;i--)
	cout<<a[i];
	return 0;
}
