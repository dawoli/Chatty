#include<bits/stdc++.h> 
using namespace std;
int a[100000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string t;int cnt=0;
	cin>>t;
	for(int i=0;i<t.size();i++){
		if(t[i]>='0'&&t[i]<='9')
		{cnt++;
		a[cnt]=int(t[i]-48);
		}
	}
	sort(a+1,a+1+cnt);
	if(a[cnt]==0){
		cout<<0;return 0;
	}
	for(int i=cnt;i>0;i--)cout<<a[i];
	
	return 0;
}
