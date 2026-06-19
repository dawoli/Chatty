#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5;
int n,a[maxn+5][3],s[3];
vector<pair<int,int>> b;

bool cmp(pair<int,int> p1,pair<int,int> p2){
	return max(p1.first,p1.second)>max(p2.first,p2.second);
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin>>t;
	while(t-->0){
		long long score=0;
		s[0]=s[1]=s[2]=0;
		b.clear();
		cin>>n;
		for (int i=0; i<n; i++){
			int k,m=-1;
			for (int j=0; j<3; j++) {
				cin>>a[i][j];
				if (a[i][j]>m) {
					m=a[i][j];
					k=j;
				}
			}
			s[k]++;
		}
		int k,m=-1;
		for (int j=0; j<3; j++) {
			if (s[j]>m) {
				m=s[j];
				k=j;
			}
		}
		
		//cout<<"test: "<<s[0]<<' '<<s[1]<<' '<<s[2]<<'\n';
		
		 
		for (int i=0; i<n; i++){
			vector<int> t;
			for (int j=0; j<3; j++){
				if (j==k) score+=a[i][j];
				else t.push_back(a[i][j]-a[i][k]);
			}
			b.push_back({t[0],t[1]});
		}
		sort(b.begin(),b.end(),cmp);
		for (int j=0; j<n/2; j++){
			score+=max(b[j].first,b[j].second);
		}
		cout<<score<<'\n';
	}
} 
