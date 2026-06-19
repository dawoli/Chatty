#include<bits/stdc++.h>
using namespace std;
int a[1000010];

bool cmp(int n,int m){
	return n>m;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int cnt=0;
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		if(str[i]>=48&&str[i]<=57){
			a[cnt]=str[i]-48;
			cnt++;
		}
	}
	sort(a,a+cnt,cmp);
	for(int i=0;i<cnt;i++){
		cout<<a[i];
	}
	return 0;
}

