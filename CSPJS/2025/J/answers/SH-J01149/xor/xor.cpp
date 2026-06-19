#include<fstream>
#include<iostream>
std::ifstream fin ("xor.in" );
std::ofstream fout("xor.out");
int hashy[1050000]; 
int main() {
	int n, k; fin >> n >> k; 
	hashy[0] = 1; 
	int admit = 1; 
	int count = 0; 
	int run = 0; 
	for (int i = 0; i < n; i++) {
		int x; fin >> x; 
		run ^= x; 
		if (hashy[run ^ k] == admit)
			admit++; 
		hashy[run] = admit; 
	}
	fout << admit - 1; 
}
/**
14 min solve, im pretty proud of this one
actually, i think the code is really neat
and to be honest i dont think theres
much to optimize even, also love how this is
a stream sol. 

did some quick paper sketching on this one, 
found out first that the greedy approach of
"must match the first one then continue" is
pretty obviously bad (you match shit, like
with 1 0 0 0 0 0 0 0 1 and k=0 you fuck up)

then considered the approach of ending the
match as soon as possible which was in
hindsight a much, much more natural greedy
approach. this obviously works; however, 
i didnt find a nice implementation. 

my thought process: 
obviously, the scanning goes left to right. 
when i match, i dont wanna recalculate
everything every time so i must prefix sum
(or, here, prefix xor i guess). 

after prefix xor, it boils down pretty much
to seeing if the previous xor has been seen, 
so my python instincts tell me dictionary
and im like "oh shit, i dont want to fucking
implement a fucking hashmap inside fucking
c++" and then i realized its kinda just
an array since the input was small enough. 

it basically collapsed from there but i think
my approach of reusing "admitted" is quite
nice and elegant. all in all, a pretty elegant
solve. im happy with this problem, a+
**/ 
