#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+10;
struct node{
	int d1,d2,d3,big;
}a[N],res; 
int n; 

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int sum = 0;
		res.d1 = 0;
		res.d2 = 0;
		res.d3 = 0;
		for(int i = 1;i<=n;i++){
			cin>>a[i].d1>>a[i].d2>>a[i].d3;
			if(a[i].d1>=a[i].d2&&a[i].d1>=a[i].d3){
				sum += a[i].d1;
				a[i].big = 1;
				res.d1++;
			}
			else if(a[i].d2>a[i].d1&&a[i].d2>=a[i].d3){
				sum += a[i].d2;
				a[i].big = 2;
				res.d2++;
			}
			else{
				sum += a[i].d3;
				a[i].big = 3;
				res.d3++;
			}
		}
		vector<int> s;
		if(res.d1>n/2){
//			cout<<1<<' ';
			for(int i = 1;i<=n;i++){
				if(a[i].big != 1) continue;
				int cha = a[i].d1-a[i].d2<a[i].d1-a[i].d3?a[i].d1-a[i].d2:a[i].d1-a[i].d3;
//				cout<<cha<<endl;
				s.push_back(cha);
			}
			int k = res.d1-n/2;
			sort(s.begin(),s.end());
			for(int i = 0;i<k;i++){
				sum-=s[i];
			}
		}else if(res.d2>n/2){
//			cout<<2<<' ';
			for(int i = 1;i<=n;i++){
				if(a[i].big != 2) continue;
				int cha = a[i].d2-a[i].d1<a[i].d2-a[i].d3?a[i].d2-a[i].d1:a[i].d2-a[i].d3;
//				cout<<cha<<endl;
				s.push_back(cha);
			}
			int k = res.d2-n/2;
			sort(s.begin(),s.end());
			for(int i = 0;i<k;i++){
				sum-=s[i];
			}
		}else{
//			cout<<3<<' ';
			for(int i = 1;i<=n;i++){
				if(a[i].big != 3) continue;
				int cha = a[i].d3-a[i].d1<a[i].d3-a[i].d2?a[i].d3-a[i].d1:a[i].d3-a[i].d2;
//				cout<<cha<<endl;
				s.push_back(cha);
			}
			int k = res.d3-n/2;
			sort(s.begin(),s.end());
			for(int i = 0;i<k;i++){
				sum-=s[i];
			}
		}
		cout<<sum<<endl;
//		cout<<endl;
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

