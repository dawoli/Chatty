#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int a[1000009];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int num=0,l=s.size();
	for(int i=l;i>=0;i--){
		if(s[i]>='0'&&s[i]<='9'){
			a[num]=s[i]-'0';
			num++;
		}
	}
	sort(a,a+num);
	for(int j=num-1;j>=0;j--){
		cout<<a[j];
	}
	return 0;
}
 
