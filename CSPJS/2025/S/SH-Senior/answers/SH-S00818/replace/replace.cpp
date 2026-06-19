#include<bits/stdc++.h>
using namespace std;
string s1[200005],s2[100005];
int f(string s1,string s2,int start){
	char k=s2[0];
	for(int i=start;i<s1.length();i++){
		bool flag=true;
		if(s1[i]==k){
			for(int j=0;j<s2.length();j++){
				if(s1[i+j]!=s2[j]) flag=false;
			}
			if(flag==true) return i;
		}
	}
	return -1;
}
int cnt;
void change(string x,string x0,string s1,string s2){
	int cnt=0;
	if((x.length()-s1.length())!=(x0.length()-s2.length())){
		return; 
	}
	int q=0;
	while(q!=-1){
		bool fl=true;
		q=f(x,s1,q);
		if(q==-1) break;
		if(f(x0,s2,q)==q){
			for(int i=0;i<q&&fl==true;i++){
				if(x[i]!=x0[i]) fl=false;
			}
			for(int i=q+s1.length();i<x.length()&&fl==true;i++){
				if(x[i]!=x0[i-s1.length()+s2.length()]) fl=false;
			}
			if(fl==true) cnt++;
		}
		q++;
	}
}
int main(){
	freopen("replce.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<n;i++){
		//scanf("%s %s",&s1[i],&s2[i]);
		cin>>s1[i]>>s2[i];
	}
	for(int i=0;i<q;i++){
		string a,b;
		string t="b";
		//scanf("%s %s",&a,&b);
		cin>>a>>b;
		printf("%d",n);
		cout<<endl;
		cnt=0;
	}
	return 0;
} 

