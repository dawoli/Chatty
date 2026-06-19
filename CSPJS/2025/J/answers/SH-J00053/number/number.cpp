#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;

bool cmp(int a,int b){
	return a>b;
}

int num[N],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i<len;++i){
		if(s[i]>='0'&&s[i]<='9'){
			num[cnt++]=s[i]-'0';
		}
	}
	sort(num,num+cnt,cmp);
	if(num[0]==0) cout<<0;
	else{
		for(int i=0;i<cnt;++i) cout<<num[i];
	}
	return 0;
}
