#include<iostream>
#include<set>
#include<string>
using namespace std;
set<string> se;
int n;
string s;
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s;
		se.insert(s);
	}
	cout<<52-se.size();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
