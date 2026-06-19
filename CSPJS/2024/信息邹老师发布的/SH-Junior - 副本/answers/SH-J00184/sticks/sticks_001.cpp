#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std; 
int t;
int n;
string s;
int m;
int p[12]={6,2,5,5,4,5,6,3,7,6};
string tst(int n){
	string res="";
	int x=0,y=n;
	while(y!=0){
		x=y%10;
		res+=(char)(x+'0');
		y/=10;
	}
	reverse(res.begin(),res.end());
	return res;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<"-1\n";
			continue;
		}
		for(int i=1;i<=100000;i++){
			s=tst(i);
			m=0;
			for(int j=0;j<s.size();j++){
				m+=p[(int)(s[j]-'0')];
			} 
			if(m==n){
				cout<<i;
				break;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
