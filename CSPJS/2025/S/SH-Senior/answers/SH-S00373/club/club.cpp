#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<set>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n,cnt=0;
		cin>>n;
		vector<int> v1,v2,v3;
		set<int> p1,p2,p3;
		for(int i = 0;i < n;i++){
			int a,b,c;
			cin>>a>>b>>c;
			v1.push_back(a);
			v2.push_back(b);
			v3.push_back(c);
			if(a>b){
				if(a>c){
					cnt+=a;
					p1.insert(i);
				}else{
					cnt+=c;
					p3.insert(i);
				}
			}else{
				if(b>c){
					cnt+=b;
					p2.insert(i);
				}else{
					cnt+=c;
					p3.insert(i);
				}
			}
		}
		while(p1.size()*2>n){
			int p,v=0x7fffffff,to=0;
			for(int i:p1){
				if(v1[i]-v2[i]<v){
					v=v1[i]-v2[i];
					p=i;
					to=2;
				}
				if(v1[i]-v3[i]<v){
					v=v1[i]-v3[i];
					p=i;
					to=3;
				}
			}
			p1.erase(p);
			if(to==2) p2.insert(p);
			if(to==3) p3.insert(p);
			cout<<v<<endl;
			cnt-=v;
		}
		while(p2.size()*2>n){
			int p,v=0x7fffffff,to=0;
			for(int i:p2){
				if(v2[i]-v1[i]<v){
					v=v2[i]-v1[i];
					p=i;
					to=1;
				}
				if(v2[i]-v3[i]<v){
					v=v2[i]-v3[i];
					p=i;
					to=3;
				}
			}
			p2.erase(p);
			if(to==1) p1.insert(p);
			if(to==3) p3.insert(p);
			cout<<v<<endl;
			cnt-=v;
		}
		while(p3.size()*2>n){
			int p,v=0x7fffffff,to=0;
			for(int i:p3){
				if(v3[i]-v1[i]<v){
					v=v3[i]-v1[i];
					p=i;
					to=1;
				}
				if(v3[i]-v2[i]<v){
					v=v3[i]-v2[i];
					p=i;
					to=2;
				}
			}
			p3.erase(p);
			if(to==2) p1.insert(p);
			if(to==3) p2.insert(p);
			cout<<v<<endl;
			cnt-=v;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
