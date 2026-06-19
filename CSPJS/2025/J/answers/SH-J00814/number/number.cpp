#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005];
bool f(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int k=0;
	for(int i=0;i<s.length();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[k]=s[i]-'0';
			k++;
		}
	}
	sort(a,a+k,f);
	for(int i=0;i<k;i++){
		printf("%d",a[i]);
	}
	return 0;
} 
