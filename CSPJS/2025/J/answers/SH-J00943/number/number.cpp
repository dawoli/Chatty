#include<iostream> 
using namespace std;
string s;
int f[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);ios::sync_with_stdio(false);
	cin>>s;
	for(int i=0;i<s.length();i++){
		if(s[i]<='9'&&s[i]>='0'){
			f[s[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=0;j<f[i];j++){
			cout<<i;
		}
	}
}
