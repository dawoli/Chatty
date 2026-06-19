#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

vector<int> d_f(int a,int b,int c){
	if(a>b){
		if(b>c){
			return {a-b,0,1};
		}else{
			if(a>c){
				return {a-c,0,2};
			}else{
				return {c-a,2,0};
			}
		}
	}else{
		if(b>c){
			if(a>c){
				return {b-a,1,0};
			}else{
				return {b-c,1,2};
			}
		}else{
			return {c-b,2,1};
		}
	}
}

bool cmp(vector<int> a,vector<int> b){
	return a[0]<b[0];
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		long long answer=0;
		cin >> n;
		int a[n][3];
		int counter[3];
		fill(counter,counter+3,0);
		vector <int> d[n];
		for(int j=0;j<n;j++){
			cin >> a[j][0] >> a[j][1] >> a[j][2];
            d[j]=d_f(a[j][0],a[j][1],a[j][2]);
		}
		for(int j=0;j<n;j++){
			answer+=a[j][d[j][1]];
			counter[d[j][1]]++;
		}
		
		for(int j=0;j<3;j++){
			if(counter[j]>n/2){
				sort(d,d+n,cmp);
				for(int k=0;counter[j]!=n/2;k++){
					if(d[k][1]==j){
						answer-=d[k][0];
						counter[j]--;
					}
				}
				break;
			}
		}
		cout<<answer<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
