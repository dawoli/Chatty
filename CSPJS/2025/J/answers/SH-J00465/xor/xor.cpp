#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,x,counter=0;
	cin>>n>>k;
	vector<int> v;
	vector<bool> pal(n+5);
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		pal[i]=true;
	}
	for(int l=0;l<n;l++){
		for(int r=0;r<n;r++){
			if(l<=r){
				int sum=0;
				bool flag=true;
				for(int i=l;i<=r;i++){
					if(pal[i]==false){
						flag=false;
						break;
					}
					sum=sum^v[i];
				}
				if(flag==false){
					continue;
				}
				if(sum==k){
					/* 
					cout<<l<<" "<<r<<endl;
					for(int i=l;i<=r;i++){
						cout<<v[i]<<" ";
					}
					cout<<endl;
					cout<<sum<<endl;
					cout<<"-------"<<endl;
					*/
					for(int i=l;i<=r;i++){
						pal[i]=false;
					}
					counter++;
				}
			}
		}
	}
	cout<<counter<<endl;
	return 0;
} 
