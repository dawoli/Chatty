#include<bits/stdc++.h>
//Ren5Jie4Di4Ling5%
using namespace std;
int t,n,a[100100][3],mx=0,chao,siz,sum=0;
vector<int> num1,num2,num3;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t--){
		cin >> n;
		mx=0;
		sum=0;
		num1.clear();
		num2.clear();
		num3.clear();
		for(int i=1;i<=n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			mx=max({a[i][0],a[i][1],a[i][2]});
			sum+=mx;
			if(mx==a[i][0])num1.push_back(a[i][0]-max(a[i][1],a[i][2]));
			else if(mx==a[i][1])num2.push_back(a[i][1]-max(a[i][0],a[i][2]));
			else if(mx==a[i][2])num3.push_back(a[i][2]-max(a[i][0],a[i][1]));
		}
//		for(int i=0;i<num1.size();i++){
//			cout << num1[i] << ' ';
//		}
//		cout << endl;
//		for(int i=0;i<num2.size();i++){
//			cout << num2[i] << ' ';
//		}
//		cout << endl;
//		for(int i=0;i<num3.size();i++){
//			cout << num3[i] << ' ';
//		}
//		cout << endl;
		sort(num1.begin(),num1.end());
		sort(num2.begin(),num2.end());
		sort(num3.begin(),num3.end());
		if(num1.size()<=n/2 && num2.size()<=n/2 && num3.size()<=n/2)cout << sum << endl;
		else{
			if(num1.size()>n/2){
				chao=1;
				siz=num1.size();
			}
			else if(num2.size()>n/2){
				chao=2;
				siz=num2.size();
			}
			else if(num3.size()>n/2){
				chao=3;
				siz=num3.size();
			}
			if(chao==1){
				for(int i=0;i<num1.size();i++){
					int st=num1[i];
					sum-=st;
					siz--;
					if(siz<=n/2)break;
				}
			}
			else if(chao==2){
				for(int i=0;i<num2.size();i++){
					int st=num2[i];
					sum-=st;
					siz--;
					if(siz<=n/2)break;
				}
			}
			else if(chao==3){
				for(int i=0;i<num3.size();i++){
					int st=num3[i];
					sum-=st;
					siz--;
					if(siz<=n/2)break;
				}
			}
			cout << sum << endl;
		}		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

