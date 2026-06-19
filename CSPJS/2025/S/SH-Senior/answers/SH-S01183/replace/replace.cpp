#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
string s1[N],s2[N];
bool replace(string x,string y,string s11,string s22){
//	cout<<"×Ö·û´®·Ö±ðÎª"<<x<<" "<<y<<" "<<s11<<" "<<s22<<"\n";
	int start=0,cnt=0;
	for(int i=0;i<x.size();i++){
		if(cnt==s11.size()){
//			cout<<"×Ö·û´®"<<x<<"Ìæ»»"<<s11<<"Îª"<<s22<<"\n";
//			printf("×Ö·û´®ÓÉ%dÎ»ÖÃµ½%dÎ»ÖÃ\n",start,start+s11.size());
			string x1=x;
			for(int j=0;j<s11.size();j++){
				x1[start+j]=s22[j];
			}
//			cout<<"ÐÂ×Ö·û´®Îª"<<x1<<"\n";
			if(x1==y) return 1;
			cnt=0;
		}
		if(x[i]==s11[cnt]){
			if(cnt==0)start=i;
			cnt++;
		}else{
			cnt=0;
		}
	}
	if(cnt==s11.size()){
//		cout<<"×Ö·û´®"<<x<<"Ìæ»»"<<s11<<"Îª"<<s22<<"\n";
//		printf("×Ö·û´®ÓÉ%dÎ»ÖÃµ½%dÎ»ÖÃ\n",start,start+s11.size());
		string x1=x;
		for(int j=0;j<s11.size();j++){
			x1[start+j]=s22[j];
		}
//		cout<<"ÐÂ×Ö·û´®Îª"<<x1<<"\n";
		if(x1==y) return 1;
		cnt=0;
	}
	return 0;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i]; 
	}
	while(q--){
		int cnt=0;
		string t1,t2;
		cin>>t1>>t2;
		for(int i=1;i<=n;i++){
			if(replace(t1,t2,s1[i],s2[i])){
				cnt++;
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
