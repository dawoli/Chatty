#include<bits/stdc++.h>
using namespace std;
string s;
int cnt;
multiset<int> st;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(char c:s){
		if(isdigit(c)){
			st.insert('0'-c);
		}
	}
	for(int it:st) {
		if(cnt==0&&it==0) {
			cout<<0;
			goto end; 
		}
		cout<<-it; 
		cnt++;
	}
	end:;
	fclose(stdin); 
	fclose(stdout);
	return 0;
} 
