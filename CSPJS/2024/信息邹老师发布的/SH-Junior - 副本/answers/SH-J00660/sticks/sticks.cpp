#include<iostream>
#include<cstdio>
using namespace std;
const int N=15;
string decode[N]={"-1","-1","1","7","4","2","6","8"
,"10","18","22","20","28","68","88"};
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int t,n;
	string s;
	cin>>t;
	while(t--){
		s="\n";
		cin>>n;
		while(n>14){
			n-=7;
			s="8"+s;
		}
		s=decode[n]+s;
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
