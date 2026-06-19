#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string str;
    cin>>str;
    vector<int> a;
    int l=str.size();
    for(int i=0;i<l;i++){
    	if(isdigit(str[i])){
    		int k=str[i]-'0';
    		a.push_back(k);
		}
	}
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		cout<<a[i];
	}
    return 0;
}
