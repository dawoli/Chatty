#include<bits/stdc++.h>
using namespace std;
long long sticks[200];
long long n,t;
bool f=1;
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>n;
	sticks['0']=6;
	sticks['1']=2;
	sticks['2']=5;
	sticks['3']=5;
	sticks['4']=4;
	sticks['5']=5;
	sticks['6']=6;
	sticks['7']=3;
	sticks['8']=7;
	sticks['9']=6;
	for(int i=0;i<n;++i){
		cin>>t;
		f=1;
		if(t<2){
			cout<<-1<<endl;
			continue;
		}
		if(t%7==0){
			for(int a=0;a<t/7;++a){
				cout<<'8';
			}
			cout<<endl;
			continue;
		}
		for(int j=pow(10,t/7-1);j<=21888;j++){
			string s=to_string(j);
			long long l=s.size(),sum=0;
			for(int k=0;k<l;++k){
				sum+=sticks[s[k]];
			}
			if(sum==t&&j!=0){
				cout<<j<<endl;
				f=0;
				break;
			}
		}
		if(f)cout<<-1<<endl;
	}
	return 0;
}
