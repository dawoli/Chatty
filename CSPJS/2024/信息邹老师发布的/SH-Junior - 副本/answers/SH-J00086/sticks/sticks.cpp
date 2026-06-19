#include<bits/stdc++.h>
using namespace std;
typedef long long i64;
i64 stick[10]={6,2,5,5,4,5,6,3,7,6};
string tp[15]={"","","1","7","4","2","6","8","10","24","23","20","60","68","88"};
string ans[7]={"8","10","18","23","20","38","68"};
string s;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	i64 t;
	cin>>t;
	for(i64 var=1;var<=t;var++){
		i64 n;
		cin>>n;
		if(n==1){cout<<-1;continue;}
		for(int i=1;i<=(n-n%7-7)/7;i++){
			s+='8';
		}
		if(n>14)
			s=ans[n%7]+s;
		else
			s=tp[n%7];
		cout<<s;
		s="";
	}
	return 0;
}

