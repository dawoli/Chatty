#include<bits/stdc++.h>
using namespace std;
int a[100005],i_1=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int x=s.size();
	for(int i=0;i<x;i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[i_1]=s[i]-48;
			i_1++;
		}
	}
	sort(a,a+i_1);
	for(int i=i_1-1;i>=0;i--) cout<<a[i];
	return 0;
}
