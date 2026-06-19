#include <bits/stdc++.h>
using namespace std;
int sum[10]={6,2,5,5,4,5,6,3,7,6};
string ans;
int cnt=0;
string Change(int a){
	string b;
	if(a==0)b+="0";
	else if(a==1)b+="1";
	else if(a==2)b+="2";
	else if(a==3)b+="3";
	else if(a==4)b+="4";
	else if(a==5)b+="5";
	else if(a==6)b+="6";
	else if(a==7)b+="7";
	else if(a==8)b+="8";
	else if(a==9)b+="9";
	return b;
}
void Comp(int pos,int stk,string num){
	if(stk==0){
		if(ans.size()>num.size())ans=num;
		else if(ans>num)ans=num;
	}else{
		for(int i=0;i<10;i++){
			if(pos!=0){
				if(i==6)continue;
			}
			if(i==3||i==9||i==5)continue;
			if(i==0){
				if(pos!=0&&stk>=sum[i]){
					Comp(pos+1,stk-sum[i],num+Change(i));
				}
			}else{
				if(stk>=sum[i]){
					Comp(pos+1,stk-sum[i],num+Change(i));
				}
			}
		}
	}
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cnt=0;
		int n;
		cin>>n;
		string a;
		ans="zzzzzzzzzzzzzz";
		Comp(0,n,a);
		if(ans=="zzzzzzzzzzzzzz")cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
