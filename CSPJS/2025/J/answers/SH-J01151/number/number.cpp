#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int a[1000010];
bool cmp(int &a,int &b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int n=0;
	for(int i=0;i<strlen(s);i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[n]=s[i]-'0';
			n++;
		}
	}
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++){
		cout<<a[i];
	}
	return 0;
} 
