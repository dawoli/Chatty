#include<bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	if(a.length()<b.length())
		return true;
	else if(a.length()==b.length())
		if(a<b)
			return true;
	return false;
}
string digui(int ws,int n){
	if(n<0||n==1)
		return "x";
	if(n==0)
		return "";
	string ans="100000000";
	if(digui(ws++,n-2)!="x")
		if(cmp("1"+digui(ws++,n-2),ans))
			ans="1"+digui(ws++,n-2);
	if(digui(ws++,n-5)!="x")
		if(cmp("2"+digui(ws++,n-5),ans))
			ans="2"+digui(ws++,n-5);
	if(digui(ws++,n-4)!="x")
		if(cmp("4"+digui(ws++,n-4),ans))
			ans="4"+digui(ws++,n-4);
	if(digui(ws++,n-6)!="x")
		if(cmp("6"+digui(ws++,n-6),ans))
			ans="6"+digui(ws++,n-6);
	if(digui(ws++,n-3)!="x")
		if(cmp("7"+digui(ws++,n-3),ans))
			ans="7"+digui(ws++,n-3);
	if(digui(ws++,n-7)!="x")
		if(cmp("8"+digui(ws++,n-7),ans))
			ans="8"+digui(ws++,n-7);
	for(int i=1;i<ans.length();i++)
		if(ans[i]=='6')
			ans[i]='0';
	if(ans!="100000000")
		return ans;
	else
		return "x";
}
int T,n;

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>n;
		if(n==1) cout<<-1<<endl;
		else cout<<digui(0,n)<<endl;
	}
	return 0;
}

