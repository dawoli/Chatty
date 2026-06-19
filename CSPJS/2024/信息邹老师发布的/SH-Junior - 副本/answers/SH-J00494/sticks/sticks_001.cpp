#include <bits/stdc++.h>
using namespace std;
struct st{
	int num;//shuzhi 
	int value;//Ä¾¹÷ 
};
int flag = 0;
int sticks = 0;
int number;
st v[7];
int double_multiply(int under ,int up )
{
	int sum = 1;
	for( int i = 0 ; i< up ; i ++ ) sum *= under;
	return sum;
}
int step( int stick , int num ,int ever_get , int p )
{
	if ( stick <= 1 or num * 8 <= stick ) return 0;
	//cout << stick << ' ' << num << " " << ever_get << " " << p << endl;
	if ( 2 <= stick and 8 >= stick ){
		for( int i = 0 ; i < 7 ; i ++ )
		{
			if (v[i].value == stick){
				if (v[i].num == 0 and p == 0 ) continue; 
				ever_get += v[i].num*double_multiply(10,(num-1));
				cout << ever_get;
				flag = 1;
				return 0;
			}
		}
	}
		for( int a = 0 ; a < 7 ; a ++ )
		{
			if ( p == 0 and a == 0) continue;
			step( stick - v[a].value , num - 1 , ever_get+ v[a].num*double_multiply(10,(num-1)) , p + 1);
			if ( flag == 1 ) break;
		}
		return 0;
	
}
int main(){
	freopen("sticks.in","r",stdin);
	freopen("sticks.out","w",stdout);
	int T,stick;
	cin >> T;
	v[0].num = 0;
	v[0].value = 6;
	v[1].num = 1;
	v[1].value = 2;
	v[2].num = 2;
	v[2].value = 5;
	v[3].num = 4;
	v[3].value = 4;
	v[4].num = 6;
	v[4].value = 6;
	v[5].num = 7;
	v[5].value = 3;
	v[6].num = 8;
	v[6].value = 7;
	for( int i = 0 ; i< T ; i++ )
	{
		flag = 0;
		cin >> stick;
		if ( stick <= 1){
			cout << "-1" << endl;
			continue;
		}
		number = (stick + 7) / 8;
		step( stick , number , 0 , 0) ;
	}
	return 0;
}

