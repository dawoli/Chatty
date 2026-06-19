#include<bits/stdc++.h>
using namespace std;
int a[10000000];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int cnt=1;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[cnt]=s[i]-'0';
			cnt++;
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
} 
