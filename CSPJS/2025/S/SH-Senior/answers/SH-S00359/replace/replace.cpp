#include<bits/stdc++.h>
using namespace std;
long long ans;
struct Rule{
	string from,to;
};

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int n,q;
	cin>>n>>q;
	
	vector<Rule> rules(n);
	for(int i=0;i<n;i++){
		cin>>rules[i].from>>rules[i].to;
	}
	
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1==t2){
			cout<<"1"<<endl;
			continue;
		}
		queue<pair<string,int> > que; 
		

		
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
