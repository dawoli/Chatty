#include<bits/stdc++.h>
using namespace std;
int main(){
	//方片为poker[1][a],草花为[2][a],红桃为[3][a],黑桃为[4][a] 
	freopen("poker1.in","r",stdin);
	freopen("poker.out","w",stdout);
	int poker[5][15]={};
	int n,ans=0;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		int a=s[0],b=s[1]-48;
		if(b==17) b=1;
		else if(b==36) b=10;
		else if(b==32||b==33||b==34) b-=21;
		if(a==68) a=1;
		else if(a==67) a=2;
		else if(a==72) a=3;
		else if(a==83) a=4;
		if(poker[a][b]==0){
			ans++;
			poker[a][b]=1;
		}
	}
	cout<<52-ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
