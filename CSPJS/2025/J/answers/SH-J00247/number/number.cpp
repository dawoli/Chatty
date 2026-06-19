//#include<bits/stdc++.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> a;
void sort_(){
	for(int i=0;i<a.size();i++){
		for(int j=i;j>0;j--){
			if(a[j]>a[j-1])swap(a[j-1],a[j]);
		}
	}
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a.push_back(s[i]-'0');
		}
	}
	sort_();
	for(int i=0;i<a.size();i++)cout<<a[i];
	return 0;
}
