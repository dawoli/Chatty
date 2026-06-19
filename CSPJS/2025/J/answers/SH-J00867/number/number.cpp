#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
string s;
int a[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int cnt=1;
	for(int i=0;i<s.size();i++){
		if('0'<=s[i]&&s[i]<='9'){
			a[cnt++]=s[i]-48;
		}
	}
	sort(a+1,a+cnt,cmp);
	for(int i=1;i<=cnt-1;i++){
		if(i==1&&a[i]==0){
			cout<<0;
			return 0;
		}else{
			cout<<a[i];
		}
	}
	return 0;
} 
