#include<bits/stdc++.h>
using namespace std;
int _,n,ans;
const int N=1e5+5;
struct node{
	int a,b,c;
}a[N];
vector<int> ato;
vector<int> bto;
vector<int> cto;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>_;
	while(_--){
		ans=0;
		ato.clear();
		bto.clear();
		cto.clear();
		cin>>n;
		int lena=0,lenb=0;
		
		for(int i=0;i<n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
			ato.push_back(i);
			lena++;
		}
		
		for(int i=0;i<ato.size();i++){
			for(int j=i;j<ato.size();j++){
				if(a[i].a<a[j].a){
					int ta=a[i].a;
					int tb=a[i].b;
					int tc=a[i].c;
					a[i].a=a[j].a;
					a[i].b=a[j].b;
					a[i].c=a[j].c;
					a[j].a=ta;
					a[j].b=tb;
					a[j].c=tc;
				}
			}
		}
		for(int i=ato.size()-1;i>=n/2;i--){
			bto.push_back(i);
			lenb++;
			lena--;
		}
		
		for(int i=0;i<lenb;i++){
			for(int j=i;j<lenb;j++){
				if(a[i].b<a[j].b){
					int ta=a[i].a;
					int tb=a[i].b;
					int tc=a[i].c;
					a[i].a=a[j].a;
					a[i].b=a[j].b;
					a[i].c=a[j].c;
					a[j].a=ta;
					a[j].b=tb;
					a[j].c=tc;
				}
			}
		}
		int lenb14=lenb;
		if(lenb14>n/2){
			for(int i=lenb14-1;i>=n/2;i--){	
				lenb--;
			}	
		}
		for(int i=0;i<lena;i++){
			ans+=a[ato[i]].a;
		}
		cout<<ans<<endl;
		for(int i=0;i<lenb;i++){
			ans+=a[bto[i]].b;
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
