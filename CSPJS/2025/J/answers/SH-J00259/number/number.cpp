#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a[1003],t=0,i=0;
	cin>>s;
	while(s[i]){
		
		if('0'<=s[i]&&s[i]<='9'){
			a[t]=s[i]-'0';
			t++;
		}
		i++;
	}
	for(int i=0;i<t;i++)
	{
		for(int j=i+1;j<t;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	for(int i=0;i<t;i++)
	{
		cout<<a[i];
	}
	return 0;
}
