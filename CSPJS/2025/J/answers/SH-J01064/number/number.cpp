#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
using namespace std;
string input;
string num;
bool cmp(char a,char b){
	return a>b;
}
int main()
{
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>input;
	for(char i:input){
		if(i>='0'&&i<='9'){
			num+=i;
		}
	}
	sort(num.begin(),num.end(),cmp);
	cout<<num;
	return 0;
}
