#include<bits/stdc++.h>
#include<vector>
using namespace std;
vector<int> a1;
int a[100000];


int main(){
	freopen("duel.in","r",stdin);
	freopen("duel.out","w",stdout);	
	int n;
	cin>>n;

	for(int i=0;i<n;i++){
	int temp=0;			
		cin>>temp;
		a1.push_back(temp);
	}
	sort(a1.begin(),a1.end());
//	for(int k=0;k<n;k++){
//		a[k]=a1[k];
//	}
//	for(int j=0;j<n;j++){
//		cout<<a1[j]<<" ";
//	}
//	cout<<endl;

	int o=n;		
	for (int o=0;o<a1.size();o++){
//		cout <<o<<"  "<<a1[o]<<endl;
		if(a1[o]==-1){
		continue;	
		} 
		for(int l=1;;l++){
			int temp=o-l;			
			if (a1[temp]==-1) continue;
//				cout <<"a__"<<temp<<endl;
			if(temp==-1) break;
			if(a1[o]>a1[temp]){
				a1[temp]=-1;
				break;
			}
		}
	}	
		for(int k=0;k<n;k++){
			a[k]=a1[k];
	}
	
	int sum=0;
	for(int h=0;h<n;h++){
		if(a1[h]!=-1) sum++;
	}
//	for(int j=0;j<n;j++){
//		cout<<a1[j]<<" ";
//	}
cout <<sum;
	return 0;
}
