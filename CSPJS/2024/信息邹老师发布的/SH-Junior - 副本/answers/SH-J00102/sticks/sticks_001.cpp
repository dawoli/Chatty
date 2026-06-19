#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int n,m;
string dp[N]={"0","0","1","7","4","2","6","8","10"};
bool isLess(string val1,string val2){
	int len1=val1.length(),len2=val2.length();
	if(len1!=len2)return len1<len2;
	return val1<val2;
}
string Min(string val1,string val2){
	if(isLess(val1,val2)){
		return val1;
	}
	return val2;
} 
void init(){
	for(int i=8;i<=100000;i++){
		dp[i]=dp[i-2]+"1";
		dp[i]=Min(dp[i],dp[i-3]+"7");
		dp[i]=Min(dp[i],dp[i-4]+"4");
		dp[i]=Min(dp[i],dp[i-5]+"2");
		dp[i]=Min(dp[i],dp[i-6]+"0");
		dp[i]=Min(dp[i],dp[i-7]+"8");
	}
}
int main(){
    freopen("sticks.in","r",stdin);
    freopen("sticks.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	init();
	while(n--){
		cin>>m;
		if(m==1)cout<<-1<<endl;
		else cout<<dp[m]<<endl;
	}
    fclose(stdin);
    fclose(stdout);
    return 0;
}
