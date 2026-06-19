#include<bits/stdc++.h>
#include<cstring>
using namespace std;
int n;
struct node{
	string s1;
	string s2;
}nn[10000];

string tool;

void make();

void solve(string q1,string q2){
	int sum=0;
	int len,loc;
	if(q1.length()!=q2.length()){
		cout<<0<<endl;
		return;
	}
	for(int i=0;i<n;i++){
		loc=q1.find(nn[i].s1);
		if(loc==-1)
		{
		//	cout<<0<<endl;
			continue;
		}
		len=nn[i].s1.length();
		if(q2.find(nn[i].s2)==loc)sum++;
	}
	cout<<sum;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>nn[i].s1>>nn[i].s2;
	}
	string q1,q2;
	for(int i=0;i<q;i++){
		cin>>q1>>q2;
		solve(q1,q2);
	}

	return 0;
}
