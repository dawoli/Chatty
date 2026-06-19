#include<bits/stdc++.h>
int c[510];
using namespace std;
long long jie(int t){
	long long sum=1;
	for(int i=t;i>0;i--)sum*=i;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool check_one=true;
	for(int i=0;i<n;i++)cin>>c[i];
	for(int i=0;i<n;i++){
		if(s[i]='1')continue;
		else{
			check_one=false;
			break;
		}
	}
	if(check_one)cout<<jie(n)/(jie(m)*jie(n-m));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
