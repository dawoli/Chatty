#include<bits/stdc++.h>
using namespace std;
int s[10]={6,2,5,5,4,5,6,3,7,6};
int s1[8]={-1,-1,1,7,4,2,0,8};
int s2[8]={-1,-1,1,7,4,2,6,8};

void find1(int c,int n){
	if(c==1){
		cout<<s1[n];
		return;
	}
	int f=0;
	for(int i=0;i<10;++i){
		if(s[i]<=f) continue;
		else f=s[i];
		if(c-1==(n-s[i]-1)/7+1){
			cout<<i;
			find1(c-1,n-s[i]);
			break;
		}
	}
}

void find2(int c,int n){
	if(c==1){
		cout<<s2[n];
		return;
	} 
	int f=0;
	for(int i=1;i<10;++i){
		if(s[i]<=f) continue;
		else f=s[i];
		if(c-1==(n-s[i]-1)/7+1){
			cout<<i;
			find1(c-1,n-s[i]);
			break;
		}
	}
}

int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.ans","w",stdout);
	int t;
	cin>>t;
	for(int a=0;a<t;++a){
		int n;
		cin>>n;
		if(n==1||n==0){
			cout<<-1<<endl;
			continue;
		}
		int c=(n-1)/7+1;
		int k=n%7;
		find2(c,n);
		cout<<endl;
	}
	return 0;
}
