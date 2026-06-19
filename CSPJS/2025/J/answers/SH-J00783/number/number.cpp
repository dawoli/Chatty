#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout); 
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr.push_back(s[i]-'0');
		}
	}sort(arr.begin(),arr.end(),cmp);
	for(int i=0;i<arr.size();i++){
		cout<<arr[i];
	}
	return 0;
}
