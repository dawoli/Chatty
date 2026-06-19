#include<bits/stdc++.h>
using namespace std;
vector<int> arr;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	int mx=0,bi=0;
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			arr.push_back(s[i]-'0');
		}
	}
	while(arr.size()>0){ 
		mx=0;bi=0;
		for(int i=0;i<arr.size();i++){
			if(arr[i]>mx){
				mx=arr[i];
				bi=i;
			}
		}
		cout<<mx;
		arr.erase(arr.begin()+bi);
	}
	return 0;
}
