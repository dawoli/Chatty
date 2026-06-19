#include <bits/stdc++.h>
using namespace std;
int t;
int l[10]= {6,2,5,5,4,5,6,3,7,6};
string x;
int expectation,f;
string construct(string a,int now) {
	while(now!=0) {
		if((now)/7<expectation-f) {
			a+="0";
			now-=6;
		} else {
			a+="8";
			now-=7;
		}
		f++;
		if(now<=5 && now!=0){
			return "fail";
		}
	}
	if(a.size()==expectation && now==0)
		return a;
	else return "fail";
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int ii=0; ii<t; ii++) {
		vector<string>v;
		int n;
		string s="";
		cin>>n;
		expectation=(n+6)/7;
		if(n<2)
			cout<<-1<<"\n";
		if(n>7){
			for(int i=1; i<=9; i++) {
				x="";
				f=1;
				if(n-l[i]>=2){
					x=construct(s+char(i+'0'),n-l[i]);
					if(x!="fail"){
						cout<<x<<"\n";
						break;
					}
				}
			}
		}
		else{
			for(int i=1;i<=9;i++){
				if(l[i]==n){
					cout<<i<<"\n";
					break;
				}
			}
		}
	}
	return 0;
}
