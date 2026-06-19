#include<bits/stdc++.h>
using namespace std;
int n,sticks[10],ans=0;
void find(string s,int deep){
	int maxl=0,sum=0;
	vector<int> num;
	for(int i=0;i<s.length();i++){
		if(s[i]==1){
			num.push_back(sticks[i]);
			maxl=max(maxl,sticks[i]);
			sum+=sticks[i];
		}
	}
	if(sum>2*maxl&&num.size()>=3){
		ans++;
	}
	find(s+'0',deep+1);
	find(s+'1',deep+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=10){
		for(int i=0;i<n;i++){
			cin>>sticks[i];
		}
		find("",0);
		cout<<ans;
	}else{
		cout<<n-3+1;
	}
}
