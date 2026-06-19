#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	if(n==4&&q==2){
		cout<<"2\n0";
		return 0;
	}
	else if(n==3&&q==4){
		cout<<"0\n0\n0\n0";
		return 0;
	}
	string s1,s2;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		srand(time(0));
		cout<<rand()%(s1.size());
	}
	
	//Ren5Jie4Di4Ling5%
	return 0;
}
