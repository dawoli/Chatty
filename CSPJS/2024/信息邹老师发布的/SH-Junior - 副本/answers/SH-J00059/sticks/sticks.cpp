#include<bits/stdc++.h>
using namespace std;
int num[15]={6,2,5,5,4,5,6,3,7,6};
pair<string,int> f(int k){
	int t,s;
	for(int i=0;i<10;i++){
		if(k>=num[i]){
			if(k>num[i]){
				t=num[i];
				s=i;
			}else{
				t=num[i];
				s=i;
				break;
			}
		}
	}
	string q=to_string(s);
	pair<string,int> pr=make_pair(q,t);
	return pr;
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int n;
	cin>>n;
	while(n--){
		int k;
		cin>>k;
		string ans="";
		while(k>0){
			pair<string,int> pi=f(k);
			ans+=pi.first;
			k-=pi.second;
		}
		cout<<(k==0?ans:"-1")<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
