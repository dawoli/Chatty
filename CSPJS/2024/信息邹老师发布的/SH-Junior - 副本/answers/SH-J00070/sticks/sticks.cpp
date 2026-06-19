#include <bits/stdc++.h>
using namespace std;
long long t,n;
string ls[6]={"1","7","4","2","0","8"};
long long cnt[6]={6,2,5,4,7,8};
string solve(long long m){
	string s="";
	if(m == 1)return "-1";
	long long k=m/7+(m%7 != 0);
	if(m==6 and m!=n)return "0";
	else if(m==2)return "1";
	else if(m==5)return "2";
	else if(m==4)return "4";
	else if(m==3)return "7";
	else if(m==7)return "8";
	else if(m == n and m==6)return "6";
	else for(long long i=0;i<6;i++)if(((m-cnt[i])/7+((m-cnt[i])%7 != 0)) < k and !(n == m and i==0))return ls[cnt[i]-2] + solve(m-cnt[i]);
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	for(long long i=0;i<t;i++){
		cin>>n;
		cout<<solve(n)<<"\n";
	}
	return 0;
}
