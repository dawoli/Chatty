#include<bits/stdc++.h>
using namespace std;

string s[54]={""};
long long n=0,leng=0;
bool myfind(string a,long long num){
	for(int i=0;i<num;i++){
		if(s[i]==a) return true;
	}return false;
}
int main(){
	freopen("poker.in","r",stdin);
	freopen("poker.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	
	cin>>n;
	string tem;
	for(long long i=0;i<n;i++){
		cin>>tem;
		if(!myfind(tem,leng)){
			s[leng]=tem;
			leng++;
			
		}
	}
	cout<<52-leng;
	return 0;
} 
