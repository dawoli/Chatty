#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<int> a;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	for(auto u:s){
		int t = u - '0';
		if(t>=0&&t<=9)a.push_back(t);
	}
	sort(a.begin(),a.end(),cmp);
	if(a[0] == 0) cout<<0;
	else for(auto u:a) cout<<u;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

