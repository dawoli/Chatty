#include<bits/stdc++.h>
using namespace std;
long long t,n;
string ans="999999999999999999999999999999999999999999999999999999999999";
int a[]={6,2,5,5,4,5,6,3,7,6};
string cmp(string a,string b){
	int n=a.size(),m=b.size();
	if(n!=m){
		if(n>m) return b;
		if(n<m) return a;
	}
	for(int i=0;i<n;i++){
		if(a[i]-'0'<b[i]-'0'){
			return a;
		}
		if(a[i]-'0'>b[i]-'0'){
			return b;
		}
	}
	return a;
}
void f(long long m,bool flag,string num){
	if(m<=0){
		if(m==0) ans=cmp(ans,num);
		return;
	}
	if(flag){
		f(m-6,flag,num+'0');
	}
	for(int i=1;i<=9;i++){
		char k=i+'0';
		f(m-a[i],true,num+k);
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		ans="999999999999999999999999999999999999999999999999999999999999";
		f(n,false,"");
		if(ans=="999999999999999999999999999999999999999999999999999999999999"){
			cout<<-1;
		}
		else{
			cout<<ans;
		}
		cout<<"\n";
	}
	return 0;
}
