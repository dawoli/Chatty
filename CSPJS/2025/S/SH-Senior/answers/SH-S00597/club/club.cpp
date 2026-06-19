#include<bits/stdc++.h>
using namespace std;
struct emp{
	int a1,a2,a3;
	int cha;
}c[200010];
vector<emp>x,y,z;
vector<int>v;
bool cmpd(emp a,emp b){
	return a.cha>b.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>c[i].a1>>c[i].a2>>c[i].a3;	
			v.push_back(c[i].a1);
			v.push_back(c[i].a2);
			v.push_back(c[i].a3);
			sort(v.begin(),v.end());
			c[i].cha=v[2]-v[1];
			v.clear();
		}
		
		
		for(int i=0;i<n;i++){
			if(max(max(c[i].a2,c[i].a3),c[i].a1)==c[i].a1)x.push_back(c[i]);
			else if(max(max(c[i].a2,c[i].a3),c[i].a1)==c[i].a2)y.push_back(c[i]);
			else z.push_back(c[i]);
		}
		//cout<<x.size()<<" "<<y.size()<<" "<<z.size()<<endl;
		
		
		
		
		
		
		
		
		
		
		if(x.size()>n/2){
			sort(x.begin(),x.end(),cmpd);
			for(int i=n/2;i<x.size();i++){
				if(max(x[i].a2,x[i].a3)==x[i].a2)y.push_back(x[i]);
				else z.push_back(x[i]);
			}
			x.erase(x.begin()+n/2,x.end());
		}
		//cout<<x.size()<<" "<<y.size()<<" "<<z.size()<<endl;
		if(y.size()>n/2){
			sort(y.begin(),y.end(),cmpd);
			for(int i=n/2;i<y.size();i++){
				if(max(y[i].a1,y[i].a3)==y[i].a1)x.push_back(y[i]);
				else z.push_back(y[i]);
			}
			y.erase(y.begin()+n/2,y.end());
		}
		//cout<<x.size()<<" "<<y.size()<<" "<<z.size()<<endl;
		if(z.size()>n/2){
			sort(z.begin(),z.end(),cmpd);
			for(int i=n/2;i<z.size();i++){
				if(max(z[i].a1,z[i].a2)==z[i].a2)y.push_back(z[i]);
				else x.push_back(z[i]);
			}
			z.erase(z.begin()+n/2,z.end());
		}
		//cout<<x.size()<<" "<<y.size()<<" "<<z.size()<<endl;
		
		long long sum=0;
	
		for(int i=0;i<x.size();i++){
			sum+=x[i].a1;
		}
		for(int i=0;i<y.size();i++){
			sum+=y[i].a2;
		}
		for(int i=0;i<z.size();i++){
			sum+=z[i].a3;
		}
		cout<<sum<<" "<<endl;
		
		
		
		x.clear();
		y.clear();
		z.clear();
	} 
	fclose(stdin);
	fclose(stdout);
	return 0;
}
