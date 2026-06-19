#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	string a;
	cin>>a;
	vector<int> num;
	int len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]-'0'<=9){
			num.push_back(a[i]-'0');
		}
	}
	sort(num.begin(),num.end());
	string ans;
	for(int i=num.size()-1;i>=0;i--){
	    ans+=to_string(num[i]);
	}
	cout<<ans;
	return 0;
} 
