#include<bits/stdc++.h>
using namespace std;
#define N 100005//设置大小
typedef long long ll;

int n,st[N]={6,2,5,5,4,5,6,3,7,6};
string dp[N];//dp[i]:使用了i个火柴棒后得出的最小数值 

string _min(string a,string b){
	int la=a.length(),lb=b.length();
	if(a=="-1") return b;
	if(b=="-1") return a;
	if(la>lb) return b;
	else if(la<lb) return a;
	else return (a>b?b:a);
}

string cs(int a){
	if(a==0) return "0";
	if(a==1) return "1";
	if(a==2) return "2";
	if(a==3) return "3";
	if(a==4) return "4";
	if(a==5) return "5";
	if(a==6) return "6";
	if(a==7) return "7";
	if(a==8) return "8";
	if(a==9) return "9";
}

void init(){
	for(int i=1;i<=100002;++i) dp[i]="-1";
	dp[0]="-1",dp[1]="-1",dp[2]="1",dp[3]="7",dp[4]="4",dp[5]="2",dp[6]="6",dp[7]="8",dp[8]="10",dp[9]="18",dp[10]="22",dp[11]="20",dp[12]="28",dp[13]="68",dp[14]="88",dp[15]="108";
	for(int i=16;i<=100002;++i) for(int j=0;j<=9;++j) if(i-st[j]>1) dp[i]=_min(dp[i],dp[i-st[j]]+cs(j));
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	
	init();
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<dp[n]<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


