#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	freopen("poker3.in","r",stdin);
	freopen("poker3.out","w",stdout);
	int n;
	cin>>n;
	set<string> se;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		se.insert(str);
	}
	cout<<52-se.size();
	fclose(stdin);
	fclose(stdout);
} 
