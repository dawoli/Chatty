#include<bits/stdc++.h>
using namespace std;
string s;
int n;
char a[1000010];
bool cmp(char a,char b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		a[i]=s[i];
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		if('0'<=a[i]&&a[i]<='9'){
			cout<<a[i];
		}
	}
	return 0;
} 
