#include<iostream>
#include<cstdio>
#include<map>
#include<string>
using namespace std;
map<string,short> m;string s;
int main(){
	int n;
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	cin >> n;
	while(n--){
		cin >> s;
		m[s]=1;
	}
	cout<<52-m.size();
	fclose(stdin);fclose(stdout);
	return 0;
} 
