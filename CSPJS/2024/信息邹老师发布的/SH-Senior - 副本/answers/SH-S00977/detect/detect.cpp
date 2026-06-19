#include<bits/stdc++.h>
using namespace std;
int car_d[100005],car_v[100005],car_a[100005],p[100005];
int n,m,L,V;
int dd,vv,aa;
int find(int num){
	int card = car_d[num],carv = car_v[num],cara = car_a[num];
	if(cara>0){
		if(p[m-1]>double((V*V-carv*carv)/2/cara)+card){
			return 1;
		}
		return -1;
	}
	else if(cara<0){
		if(carv<V) return -1;
		double need = double((V*V-carv*carv)/2/cara)+card;
		int left = 0,right = m-1;
		int mid=(left+right)/2;
		while(left<right){
			mid=(left+right)/2;
			if(p[mid]<need) left=mid+1;
			else if(p[mid]>need) right=mid-1;
			else return mid-1;
		}
		if(p[left]>=card){
			if(right!=-1) return left;
		}
		return -1;
	}
	else{
		if(carv>V){
			int need = card;
			int left = 0,right = m-1;
			int mid=(left+right)/2;
			while(left<right){
				mid=(left+right)/2;
				if(p[mid]<need) left=mid+1;
				else if(p[mid]>need) right=mid-1;
				else return mid;
			}
			return left;
		}
		else{
			return -1;
		}
	}
}

int findp(int num){
	int need = car_d[num];
	int left = 0,right = m-1;
	int mid=(left+right)/2;
	while(left<right){
		mid=(left+right)/2;
		if(p[mid]<need) left=mid+1;
		else if(p[mid]>need) right=mid-1;
		else return mid;
	}
	if(p[left]==need) return left;
	return left+1;
}

int main(){
	freopen("detect.in","r",stdin);
	freopen("detect.out","w",stdout);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		vector<pair<int,int> > v;
		v.clear();
		cin>>n>>m>>L>>V;
		for(int j=0;j<n;j++){
			cin>>dd>>vv>>aa;
			car_d[j] = dd;
			car_v[j] = vv;
			car_a[j] = aa;
		}
		for(int j=0;j<m;j++){
			cin>>p[j];
		}
		int res=0,ans=0,index=0;
		int maxnewj=-1,maxindex=-1;
		for(int j=0;j<n;j++){
			int newj = find(j);	
//			cout<<newj<<endl;
			if(newj>=0) res++;
			if(car_a[j]<0&&newj>=0){
				v.push_back({findp(j),newj});
			}
			if(car_a[j]>=0){
				ans=1;
			}
		} 
		for(int j=0;j<v.size();j++){
			for(int k=j+1;k<v.size();k++){
				if(v[j].second<v[k].second){
					pair<int,int> temp = v[k];
					v[k] = v[j];
					v[j] = temp;
				}
			}
		}
		for(int j=0;j<v.size();j++){
//			cout<<v[j].first<<' '<<v[j].second<<endl;
		}
		if(!v.empty()){
			int left=v[0].first,right=v[0].second;
			ans++;
			for(int j=1;j<v.size();j++){
				if(v[j].first<left&&v[j].second<left){
				    ans++;
					left = v[j].first;
					right = v[j].second;	
				}
				else if(v[j].first>right&&v[j].second>right){
					ans++;
					left = v[j].first;
					right = v[j].second;
				}
				else{
					if(v[j].first>left) left=v[j].first;
					right=v[j].second;
				}
			}
		}
		cout<<res<<' ';
		cout<<m-ans<<endl;
	}
} 
