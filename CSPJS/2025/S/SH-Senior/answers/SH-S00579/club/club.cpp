#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long int n;
	int si=0;
	int class1=0,class2=0,class3=0;
	int z=0,x=0,c=0;
	cin>>n;
	long long int zu[n+1];
	long long int i[10000001][4];
	for(int q=0;q<n;++q){
		cin>>zu[q];
		for(int j=0;j<zu[q];++j){
			cin>>i[j][1]>>i[j][2]>>i[j][3];
			if(i[j][1]>i[j][3] && i[j][1]>i[j][2] && z<=zu[q]/2)
				class1+=i[j][1];
				++z;
				++si;
			if(i[j][2]>i[j][1] && i[j][2]>i[j][3] && x<=zu[q]/2)
				class2+=i[j][2];
				++x;
				++si;
			if(i[j][3]>i[j][2] && i[j][3]>i[j][1] && c<=zu[q]/2)
				class3+=i[j][3];
				++c;
				++si;
			if(si==0){
				if(i[j][2]>i[j][1]>i[j][3] || i[j][3]>i[j][1]>i[j][2] && z<=zu[q]/2)
					class1+=i[j][1];
					++z;
					++si;
				if(i[j][1]>i[j][2]>i[j][3] || i[j][3]>i[j][2]>i[j][1] && z<=zu[q]/2)
					class2+=i[j][2];
					++x;
					++si;
				if(i[j][2]>i[j][3]>i[j][1] || i[j][1]>i[j][3]>i[j][2] && z<=zu[q]/2)
					class3+=i[j][3];
					++c;
					++si;
			}
			if(si==0){
				if(i[j][1]<i[j][3] && i[j][1]>i[j][2] && z<=zu[q]/2)
				class1+=i[j][1];
				++z;
				++si;
			if(i[j][2]>i[j][1] && i[j][2]>i[j][3] && x<=zu[q]/2)
				class2+=i[j][2];
				++x;
				++si;
			if(i[j][3]>i[j][2] && i[j][3]>i[j][1] && c<=zu[q]/2)
				class3+=i[j][3];
				++c;
				++si;
			}
		}
		cout<<class1+class2+class3<<endl;
		z=0;
		x=0;
		c=0;
		si=0;
	}
	return 0;
}
