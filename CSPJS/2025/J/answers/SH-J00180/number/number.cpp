#include <bits/stdc++.h>
using namespace std;
char arr[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int a=0,b=0,c;
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]=='0'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='1'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='2'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='3'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='4'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='5'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='6'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='7'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='8'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		if(s[i]=='9'&&a==0){
			arr[b]=s[i];
			a=1;
			b+=1;
		}
		a=0;
	}
	int d=b;
	while(d>1){
		for(int i=0;i<d;i++){
			if(arr[i]<arr[i+1]){
				c=arr[i];
				arr[i]=arr[i+1];
				arr[i+1]=c;
			}
		}
		d-=1;
	}
	for(int i=0;i<b;i++){
		cout<<arr[i];
	}
	return 0;
} 
