#include<bits/stdc++.h>
using namespace std;
string ans="";
short hao[10];
void dfs(int s,string now){
	if (s>7*(ans.size()-now.size())&&ans!="") return;
	if (s==0){
		if (ans=="") ans=now;
		else if (ans.size()>now.size()){
			ans=now;
		}
		else if (ans.size()==now.size()){
			if (ans>now){
				ans=now;
			}
		}
		return;
	}
	int st=(now=="");
	for (int i = st; i < 10; i++){
		if (hao[i]<=s&&hao[i]!=0){
			dfs(s-hao[i],now+char('0'+i));
		}
	}
	return;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	hao[0]=6;hao[1]=2;hao[2]=5;hao[4]=4;
	hao[6]=6;hao[7]=3;hao[8]=7;
	int T;
	cin>>T;
	while (T--){
		int n;
		cin>>n;
		if (n%7==0){
			for (int i = 1; i <= n/7; i++) cout<<8;
		}
		else if (n%7==1){
			cout<<"10";
			n-=8;
			for (int i = 1; i <= n/7; i++) cout<<8;
		}
		else {
			ans="";
			dfs(n,"");
			if (ans=="") cout<<-1;
			else cout<<ans;
		}
//		else{
//			ans="";
//			if (n>20){
//				int x=7+n%7;
//				n-=x;
//				dfs(x,"");
//				if (ans=="") cout<<-1;
//				else {
//					cout<<ans;
//					for (int i = 1; i <= n/7; i++) cout<<8;
//				}
//			}
//			else{
//				dfs(n,"");
//				if (ans=="") cout<<-1;
//				else cout<<ans;
//			}
//		}
		cout<<"\n";
	}
	return 0;
}
