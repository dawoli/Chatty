#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int b[1000005];
int main(){
	
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;getline(cin,s);
	int k=0,n=0,m=0;
	for(int i=0;i<s.length();++i){
		if(s[i]>='0'&&s[i]<='9'){
		a[k]=s[i]-'0';
		k+=1;
		}
	}
	for(int i=0;i<k;++i){
		for(int j=0;j<k;++j){
			if(a[j]>n){
				n=a[j];
				m=j;
			}
		}
		b[i]=n;
		a[m]=0;
		n=0;m=0;
	}
	for(int i=0;i<k;++i){
		cout<<b[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
} 
