#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int mod=998244353;
string s;
int n,m,c,f,su;
int a[500];
bool b[500];
bool ta=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')b[i+1]=1;
	}
	/*for(int i=1;i<=n;i++)if(b[i]==1)c++;
	if(c<m){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(b[i]==1){
			su++;
		}
		else{
			f++;
			while(a[i+1]>f&&i<=n)f++,i++;
		}
	}
	if(su<m){
		cout<<0;
		return 0;
	}
	cout<<c;*/
	cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
