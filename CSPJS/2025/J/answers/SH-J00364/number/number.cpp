#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1000005],cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++){
		if(s[i]>='0'&&s[i]<='9'){
			cnt++;
			a[cnt]=s[i]-'0';
		}
	}
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		cout<<a[i];
	}
	return 0;
}
