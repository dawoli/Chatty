#include<iostream>
#include<string>
using namespace std;

string s;
int a[10];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>s;
	int n = s.size();
	for(int i=0;i<n;i++){
		if(s[i]>='0' && s[i]<='9'){
			int num=s[i]-'0';
			a[num]++;
		}
	}
	for(int i=9;i>=0;i--){
		while(a[i]){
			cout<<i;
			a[i]--;
		}
	}
	
	return 0;
}
