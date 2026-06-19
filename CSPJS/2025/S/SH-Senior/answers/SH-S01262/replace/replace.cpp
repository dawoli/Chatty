#include<bits/stdc++.h>
using namespace std;
const int N=2e5+100;
int n,q,cnt;
bool book[N];
string ques1,ques2,a1[N],a2[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
//	freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i];
	}
	for (int v=1;v<=q;v++){
		memset(book,0,sizeof book);
		cnt=0;
		cin>>ques1>>ques2;
		for (int i=0;i<ques1.size();i++){
			for (int j=i;j<ques1.size();j++){
				string s1="",s2="";
				for (int k=i;k<=j;k++){
					s1+=ques1[k];
					s2+=ques2[k];
				}
				cout<<s1<<" "<<s2<<"\n";
				for (int t=1;t<=n;t++){
					if (s1==a1[i] && s2==a2[i] && book[i]==0){
						for (int k=i;k<=j;k++){
							ques1[k]=a1[t][k];
							ques2[k]=a2[t][k];
						}
						if (ques1==ques2){
							book[i]=1;
							cnt++;
						}
					}
				}
			} 
		}
		cout<<cnt<<"\n";
	}
	return 0;
}
//4 2
//xabcx xadex
//ab cd
//bc de
//aa bb
//xabcx xadex
//aaaa bbbb
