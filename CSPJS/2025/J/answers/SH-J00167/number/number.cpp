#include<iostream>
using namespace std;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	/*string  s;
	for(int i=1; i<=100000; i++)s[i]=-1;
	int a[1000000];
	//for(int i=1;i<=s.size();i++)s[i]=-1;
	cin>>s;
	for(int i=1; i<=s.size(); i++)if(s[i]<=9||s[i]>-1)a[i]=s[i];
	for(int i=1; i<s.size(); i++) {
		for(int j=i+1; j<=s.size(); j++) {
			if(a[i]<a[j])swap(a[i],a[j]);
		}
	}
	for(int i=1; i<=s.size(); i++)if(a[i]!=-1)cout<<a[i];*/
	int a,b,c[100000],t=1;
	cin>>a;
	b=a;
	if(a>=10){
		while(b>=10){
		t++;
		b/=10;
		
	}
	for(int i=t;i>=1;i--){
		c[i]=a%10;
		a/=10;
	}
	for(int i=1;i<t;i++){
		for(int j=i+1;j<=t;j++){
			if(c[i]<c[j])swap(c[i],c[j]);
		}
	}
	for(int i=1;i<=t;i++)cout<<c[i];
	}
	else{
		cout<<a;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}
