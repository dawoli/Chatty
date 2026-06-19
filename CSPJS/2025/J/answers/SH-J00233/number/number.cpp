#include<bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int tot=0;
	for(auto i:s){
		if(i>='0'&&i<='9'){
			a[++tot]=i-'0';
		}
	}
	sort(a+1,a+tot+1,cmp);
	for(int i=1;i<=tot;i++){
		cout<<a[i];
	}
	cout<<endl;
	return 0;
} 
