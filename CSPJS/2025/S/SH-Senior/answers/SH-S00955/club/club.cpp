#include<bits/stdc++.h>
using namespace std;

struct stu{
	int c[4],cl,m1,m2,m3;
};
struct club{
	int sum,cnt;
	vector<int> mem;
};

stu a[100005];



int main(){
	freopen("club.in","r",stdin);
	freopen("club.out", "w", stdout);
	/*int t;
	cin >> t;
	while(t--){
		club club[4];
		for(int i=1;i<=3;i++){
			club[i].mem.clear();
			club[i].cnt=0;
			club[i].sum=0;
		}
		int n;
		cin >> n;
		for(int i=1;i<=n;i++){
			cin >> a[i].c[1] >> a[i].c[2] >> a[i].c[3];
			stu xx = chu(a[i].c[1], a[i].c[2], a[i].c[3]);
			a[i].m1=xx.m1;
			a[i].m2=xx.m2;
			a[i].m3=xx.m3;
			if( max(a[i].c[1], max(a[i].c[2],a[i].c[3])) == a[i].c[1]){
				a[i].cl=1;
				club[1].sum+=a[i].c[2];
				club[1].cnt++;
				club[1].mem.push_back(i);
			}
			if( max(a[i].c[1], max(a[i].c[2],a[i].c[3])) == a[i].c[2]){
				a[i].cl=2;
				club[2].sum+=a[i].c[2];
				club[2].cnt++;
				club[2].mem.push_back(i);
			}
			if( max(a[i].c[1], max(a[i].c[2],a[i].c[3])) == a[i].c[3]){
				a[i].cl=3;
				club[3].sum+=a[i].c[3];
				club[3].cnt++;
				club[3].mem.push_back(i);
			}
		}
		while(club[1].cnt>2/n){
			
		}
	}*/
	int t;
	cin >> t;
	while(t--){
		int n,sum=0;
		cin >> n;
		if(n==2){
			int a[3],b[3];
			for(int i=1;i<=3;i++){
				cin >> a[i]; 
			}
			for(int i=1;i<=3;i++){
				cin >> b[i];
			}
			for(int i=1;i<3;i++){
				for(int j=i+1;j<=3;j++){
	
					sum=max(sum,a[i]+b[j]);
					//cout << a[i]+b[j] << endl;
				}
			}
			for(int i=1;i<3;i++){
				for(int j=i+1;j<=3;j++){
					sum=max(sum,a[j]+b[i]);
					//cout << a[j]+b[i] << endl;
				}
			}
			for(int i=1;i<=3;i++){
				//cout << a[i] << " "; 
			}
			//cout << endl;
			for(int i=1;i<=3;i++){
				//cout << b[i] << " "; 
			}
			//cout << endl;
			cout << sum << endl;
		}else{
			int a[1000005];
			for(int i=1;i<=n;i++){
				int x;
				cin >> a[i] >>x >> x;
				sort(a+1,a+n+1);
				for(int i=1;i<=n/2;i++){
					sum+=a[i];
				}
			}
			cout << sum;
		}
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
