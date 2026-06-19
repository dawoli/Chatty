#include<bits/stdc++.h>
using namespace std;
int n,q;
struct team{
	string s1;string s2;
};
team rule[200005],prob[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){ 
		cin>>rule[i].s1>>rule[i].s2;
	}
	for(int i=1;i<=q;i++){
		cin>>prob[i].s1>>prob[i].s2;
	}
	for(int i=1;i<=q;i++){//run q problems 
//		cout<<i<<endl;
		int ans=0;
		string start=prob[i].s1;
		string end=prob[i].s2;
//		cout<<start<<endl;
//		cout<<end<<endl;
		for(int j=1;j<=n;j++){//go through n rules
			int lenth=rule[j].s1.size();
//			cout<<rule[j].s1<<endl<<rule[j].s2<<endl;
			if(lenth>start.size())continue;//rule is too long
			for(int k=0;k<=start.size()-lenth;k++){//find rule[j].s1 in start
				string find;//from k to k+lenth-1
				string front,last;
				for(int x=k;x<=k+lenth-1;x++) find+=start[x];//get find
				if(find==rule[j].s1){
					for(int x=0;x<k;x++) front+=start[x];
					for(int x=k+lenth;x<start.size();x++) last+=start[x];
					if(front+rule[j].s2+last==end){
						ans++;break;
					}
				}
			}
//			cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
}

