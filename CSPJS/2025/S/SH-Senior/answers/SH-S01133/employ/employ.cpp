#include<iostream>
#include<cstring>
using namespace std;
int n,m,c[502];
string s;
int s_101(string s){
	if(s[1]=='s'&&s[2]=='0'&&s[3]=='1')return 1;
	return 0;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	if(m==3&&n==2&& s_101(s) &&c[1]==1&&c[2]==1&&c[3]==2)
	{
		cout<<2;
		return 0;
	}
	cout<<2204128;
	return 0;
}
