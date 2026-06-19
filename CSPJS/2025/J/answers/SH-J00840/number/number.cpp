#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
string a,b="";
map<char,long long> numb;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int y=0;y<a.size();y++){
		if(isdigit(a[y])){
			numb[a[y]]++;
		}
	}
	map<char,long long>::iterator y;
	for(y=numb.end();y!=numb.begin();y--){
		for(long long u=0;u<y->second;u++)cout<<y->first;
	}
	for(long long u=0;u<y->second;u++)cout<<y->first;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
