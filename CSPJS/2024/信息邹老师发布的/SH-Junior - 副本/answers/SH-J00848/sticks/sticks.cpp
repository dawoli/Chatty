#include<bits/stdc++.h>
using namespace std;
void open(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
#define N 111111
string ans[15]={"0","-1","1","7","4","2","6","8","10","18","22","20","28","68","88"};
int main(){
	open("sticks");
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		if(n<=14)
			cout<<ans[n];
		else{
			cout<<ans[n%7+7];
			while(n>=14)cout<<'8',n-=7;
		}
		cout<<endl;
	}
}
