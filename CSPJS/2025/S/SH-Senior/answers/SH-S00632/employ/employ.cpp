#include<bits/stdc++.h>
using namespace std;
int n,m,Ans,Mod=998244353,cnt,stupidcheckans=1,cnt1,cnt0,numberof0;
char c[505];
bool stupidcheck;
struct node{
	int num;
	bool pass;
} a[505];

bool Check(int k){
	cnt1=0,cnt0=0;
	for(int i=1;i<=n;i++){
		if(a[i].num<=cnt0) a[i].pass=0;
		if(c[i]-'0'==0 or a[i].pass==0) cnt0++;
		else cnt1++; 
	}
	if(cnt1>=m) return 1;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	stupidcheck=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]!='1') stupidcheck=0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		if(a[i].num==0) numberof0++;
	}
	if(n-numberof0<m){
		cout<<0<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(stupidcheck==1){
		for(int i=n-numberof0;i>=1;i--){
			stupidcheckans*=(i%Mod);
			stupidcheckans%=Mod;
		} 
		cout<<stupidcheckans<<endl;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	
	
	for(int j=1;j<=n;j++){
		for(int p=1;p<=n and p!=j;p++){
				if(Check(n)) Ans++;
				swap(a[j],a[p]);
		}
		Ans%=Mod;
	}
	Ans%=Mod;
	cout<<Ans<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
