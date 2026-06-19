#include<bits/stdc++.h>
using namespace std;
int l[12]= {1,7,4,2,6,8,10,18,22,20,28,68 };
int main() {
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	int t;
	cin>>t;
	while(t--) {
		int n,i=0;
		string s="";
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
			continue;}
		else if(n<14) {
			cout<<l[n-2]<<endl;
			continue; }
		while(n>=15) {
			n-=7;
			s+='8';
			i++; }
		if(n==0)cout<<s<<endl;
		else cout<<l[n-2]<<s<<endl; }
    fclose(stdin);
    fclose(stdout);
	return 0; }
