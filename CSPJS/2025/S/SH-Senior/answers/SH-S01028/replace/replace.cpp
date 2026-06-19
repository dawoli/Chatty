#include<bits/stdc++.h>
using namespace std;
string m[1000000];
int ap[1000000];
int aq[1000000];
int main(){
	//freopen("replace.in","r",stdin);
	//freopen("replace.out","w",stdout);
	int a,b,q=0,p=0;
	string s[11000],p[11000],o,k;
	cin>>a>>b;
	for(int j=1;j<=a;j++){
		cin>>s[j]>>p[j];
		for(int i=1;i<=s.size();i++){
			if(s[i]=="b"){
				q++;
				p++;
				aq[q]=i;
				ap[p]=s.size()-i;
				break;
			}
		}
		for(int i=1;i<=p.size();i++){
			if(s[i]=="b"){
				if(aq[q]==i&&ap[p]==p.size()-i){
					break;
					q--;
				}
				else{
					p--;
					q--;
				}
				break;
			}
		}
	}
	int yyy,xxx;
	for(int i=1;i<=b;i++){
		cin>>o>>k;
		for(int j=1;j<=o.size;j++){
			if(s[i]=="b"){
				yyy=i;
				xxx=s.size()-i;
				break;
			}
		}
	}
	cout<<s;
	return 0;
	//fclose(stdin);
	//fclose(stdout);
} 
