#include<fstream>
#include<iostream>
std::ifstream fin ("polygon.in" );
std::ofstream fout("polygon.out");
long long M = 998244353; 
long long p(int n) {
	if (n == 0) return 1LL;
	if (n % 2 == 1) return 2LL * p(n-1) % M; 
	return 1LL * p(n/2) * p(n/2) % M; 
}

int n;
int a[5002]; 
long long knap[5002]; 
int count[5002]; 
int summing[5002]; 

int main () {
	fin >> n; 
	for (int i = 0; i < n; i++) {
		fin >> a[i]; 
		count[a[i]]++; 
	}
	// build knapsack
	knap[0] = 1; 
	for (int i = 0; i < n; i++) {
		for (int s = 5000 - a[i]; s >= 0; s--) {
			int odex = s + a[i]; 
			knap[odex] += knap[s]; 
			knap[odex] %= M; 
		}
	}
	
//	for (int i = 0; i <= 5000; i++) {
//		std::cout << i << ' ' << knap[i] << '\n'; 
//	}

	// build interval sum
	for (int i = 5000; i >= 0; i--) {
		summing[i] = summing[i+1] + count[i]; 
	}
	
	long long ans = p(n); 
	for (int i = 1; i <= 5000; i++) {
		ans -= (knap[i] - count[i]) * summing[i]; 
		ans %= M; 
	}
	ans -= n*(n-1)/2; 
	ans -= n; 
	ans -= 1; 
	ans %= M; 
	ans += M; 
	ans %= M; 
	fout << ans;  
}

/**


you might notice that, for once, there are
comments! hooray! that's because this shit
is hard. 

well, not like that hard, but yah. 

first i had no good ideas so looked at
data range, found a=1 case to be easily
bashable (quickpow 2^n for all cases, 
subtract degenerates which are n*(n-1)/2
for two, n for one, and 1 for none). 

then i also bashed the n<=20 case, since
it was fine as well. i didnt do a particularly
elegant solution - nor do i believe one exists
- but its basically bit for 0 to 2^n, check
over bits for >=3 sides, sum>2*max. nothing
crazy. 

(this is when i find out i have 2+ hours left)

then i started thinking. data range being
5000 is pretty lenient so nothing i could
really get from that (i guess in retrospect
it could have hinted at my sol? but not that
i would recognize anyways)

ok now is a lot of thought reconstruction
im doing by looking at my scratch paper

i wrote "what i really want:", then under
that ">= 10001 auto admit" - this subproblem
i wrote "(BAG)" for, and it was clearly
just knapsack. then i wanted to do this
for all cases (for a_i being 1 through 5000).

let me remind you that i fucking use python
and that c++ fucking sucks and i dont really
do oi comp that seriously anyways. so beside
it i wrote "2.5x10^7 doable?" because im
fucking stupid as shit and thought knapsack
was like fucking O(n). its not, you fucking
retard, its fucking O(n^2) 

well, O(mn), but its the same thing here

i wrote "complementary counting", which
i thought was pretty much the only way doable
(i did also consider brute in/ex-clusion, but
that was pretty badly tle)

i wrote 350-360 since that was how much i was
expecting to get by brute force. now its been
bumped to 400. 

then i thought about how i could consider
"violators", essentially the max element
in a non-polygonal non-degenerate. so like
in 1 1 2 5, the violator would be 5. and this
was nice because you can't have >1 violators,
which meant i just had to solve for each
violator. 

so then i wrote "PROPER INVALIDS" which is
basically just non-polynomial non-degenerates.

so i then wrote "RATHER THAN case-by-case
basis" which i honestly dont know what i
really really wanted but i guess its part of
my train of thought. 

then i drew a graph like this

| sorry, i have to interrupt myself as an
| aside; im writing increasingly like
| christopher (from the book called "the
| curious incident of the dog in the
| night-time"), so i thought id plug my
| medium.com account which is like probably
| NumberBasher or something which has a
| fanfiction called "the curious incident
| of the **fork** in the night-time" 
| (emphasis mine) which is currently in
| release so go check it out i guess

i digress; i drew a graph like this

1  2  3  4  5
x  x  x  x  x
x  x  x  x
x  x  x
x  x  x
x  x
x
x

which is supposed to be like the
count of all the different a_i's? 
although im not sure why i thought the
distribution was like this, probably since
i thought this was the most interesting case.

i then wrote "what"
(i wrote "WHAAAAAT?" but i guess its the
same thing)

then i wrote
"calculate: # arrangements which FAIL me"

at this point i returned to the idea of
violators that i had earlier which was a
correct idea (ill refer to my sol as 
"intended" for sake of ease, even though it
may or may not be intended) so it was intended

for a given violator, the sets that satisfy
it must sum to at most it. lemme give a 
concrete example: if the violator is 5, then
the sets which constitute this violator
are sets which sum to 5 or less. 

but thats not exactly what i wrote since
i was considering the violators that a set
can constitute. but i guess both are equally
fine and solveable. so for sets which sum to
5, they constitute violators of all numbers
equal or greater than 5. 

finally i reconsider the added constraint that
the invalids i generate must be what i term
proper invalids, so that means that set must
have at least two numbers, which was as simple
as removing the count of numbers which are 5.

so i wrote down the algorithm: start with, 
again, the quickpow result of 2^n (mod that
thing), then subtract off [the number of
sets which sum to x, minus the number of
numbers which are x], multiplied by the
number of numbers of x or higher. and then
finally subtract off n(n-1)/2 and n and 1. 

then i implemented the knapsack, the
counting, the suffix sums

i personally really like how i resolve mods,
im pretty sure its established waaaaay before
me but something strikes me as elegant with

ans %= M; 
ans += M; 
ans %= M; 

(but also this proves my point of c++ being
stupid. i never could understand why modulus
and integer division respected sign and not
math. its fucking stupid. fuck you, c++, 
fuck you)

and so after all that was implemented, 
ale li pona (which is toki pona for
"all is good". i should plug wasona.com
for being an excellent resource to learn
toki pona; im currently contributing chinese
translations for it)

or so i thought.

it passed test case 1.

it passed test case 2. 

it passed test case 3. 

it failed test case 4. 

by this point i had a pretty good idea of
what went wrong. 

you see, c++ is not just fucked because
of its fucking declaration and initiation, 
not just fucked because of its fucking
fucked i/o fuckery, not just fucked because
of its modulus operator fucking around all
over the fucking place, but also fucked 
because of the fucking integer limit
being fucking stupid as fucking shit. 

(i guess this is a good time to say that im
not claiming c++ is actually bad, im just
fucking around. there are obviously reasons
for many of its design choices and i respect
them. well, all of them except the modulus
operator. just why. why. just why.) 

so this was an integer overflow issue, 
and specifically inside of my (then int)
knapsack. because holy shit can the numbers
get fucking huge. so i just changed it to
long long and i passed test case 4. 

ni la (and so), ale li pona

if i was fucking stupid, which i fucking wasnt

you see, c++ is not just fucked because
of its fucking declaration and initiation, 
not just fucked because of its fucking
fucked i/o fuckery, not just fucked because
of its modulus operator fucking around all
over the fucking place, not just fucked
because of its fucking integer limit
being fucking stupid as fucking shit, 
but also fucked because of the fucking
long long limit also being fucking stupid 
as fucking shit. 

(i dont actually mean any of this lol
obviously im the one at fault here)

clearly, 2^5000 is not within long long
[citation needed], so i had to mod it
beforehand to not fuck things up. 

ni la, ale li pona a. 

this is a nice problem. a+*. 

now, you probably dont know this but its
currently 11:12 am, which is to say that
i still have 48 minutes left. oh well. 

i guess there's not much to do except for me
to dump my life philosophy on whoever may be
reading this. 

and i also thought about coming out as
autistic through this piece of writing but i
guess its pretty obvious anyways. i do really
like yapping, huh. 

uh well if we met in person id ask if you'd
like to receive a toki pona lesson or a brief
piece of writing on tulpamancy. but i really
dont think i know enough about tulpamancy and
there are a lot of excellent resources online
so really really you should just check them
out. 

and on this topic im suddenly aware of the
fact that i may or may not have accidentally
created a christopher tulpa, or, for that
matter, if that had now been part of me. such
interesting questions, however, require
further thought before they are conveyed. 

who knows, you might see them on csp-s. but
csp-s is like hard so i probably won't have
the 30+ mins i require to type it all out. 

so i guess that leaves toki pona huh. ok,
brace for infodump. 

id also strongly recommend you to fact-check
me especially with places which i have
attached a question mark to since these are
things that im not completely certain about
from memory. 

anyhow, toki pona is a conlang, which means
its a "constructed language" as opposed to
a natlang which is a "natural language". it
was created by californian polyglot (which
means one who speaks many languages)
Sonja Lang (the j is pronounced as in the
"y" from "yellow"; its IPA is, &lit (and
literally), /j/). 

some say toki pona was designed to be
minimalist. it isnt. maybe it can be
considered slightly minimalist, but the
original design choice was for it to simplify
thought because sonja lang was then going
through depression, but not in such a 
way as to render the language minimal. 
(i know that there have been some
attempts to further minimalize toki pona
which you can read about but i cant fetch
from memory.)

anyhow, you're probably excited to learn of
toki pona vocabulary. and maybe one of your
questions is "why is it called 'toki pona'?",
in which case i have just the answer for you.

the short answer is that "toki" means
language and "pona" means good. the long
answer, well you'd have to read on. 

before we delve deep into the abyss of vocab
in toki pona like

kijetesantakalu (raccoon or squirrel)

, we should start of learning about how
sentences work. sentences usually have:

      HE          EAT          APPLE. 
    ------      -------      ---------
   subject,     verb,        object. 

(you can have sentences without objects, 
but that's usually it. S, V, O.) now toki pona
also has S-V-O in this order, BUT it has
specific markers for verb and object. these
are, for the most part, hard requirements for
a sentence to be even minimally grammatically
correct. these are also necessary to clear up
cases of ambiguity, as we'll talk about later
after we touch on modifiers. 

The specific markers are `li` and `e`. 


      ona    li   moku    e     kili. 
    ------      -------      ---------
   subject,     verb,        object. 
 (    HE          EAT          APPLE.   )

the exception to the requirement is that `li`
can be omitted when the subject is just
`mi` (me) or `sina` (you), since it is more
convenient that way. 

(you may note that the english sentence as is
isn't correct since you'd have to have either
"an apple" or "the apple". but toki pona
doesn't have such constructs - or at least
they are not required. the two here would be
translated as "ona li moku e kili wan" and
"ona li moku e kili ni", respectively. 
its also probably worthwhile to note that
"ona li moku e kili" does not imply that there
are multiple apples, either; that would be
"ona li moku e kili mute". its just missing
any identifying information about the apples.)

if you've read the above, you can probably
make some educated guesses on what "wan", 
"ni", and "mute" are: "one", "this/that", 
and "many". one thing you may notice is that
they come AFTER "kili", which is to say that
in toki pona, modifiers come AFTER the things
they describe. 

ona		li		moku	e		kili	suli. 
he		[verb]	eat		[obj]	fruit	big. 

here, for instance, "suli" (big) modifies
"kili" (fruit), so the kili is suli. 

if we were to want to describe the fruit
as, say, suwi (sweet) as well, then we would
write "big sweet fruit" as "kili suwi suli". 

one issue which may arise is when grouping
modifiers, since modifiers can act on other
modifiers. for instance, consider "the door
of my house". me modifies house, yet my house
modifies door. in such cases, we use "pi" for
grouping. 

lupa	pi		tomo	mi
door	(		house	me

so evaluating would be "tomo mi" = my house, 
then "lupa pi tomo mi" = my house's door. 

a clearer case for why this matters:

kasi	ma		mi
plant	land	me

"land's plant" would be interpreted as "grass"
, so "kasi ma mi" would be (kasi ma) mi, my
grass. however, 

kasi	pi		ma		mi
plant	(		land	me

would more likely mean a plant (or any plant)
which is on or belongs to my land. 

now let's talk about prepositions! common
prepositions are "tawa" (move to) and "lon"
(at, on, existing). for instance, 

mi		tawa	tomo
i		go to	house

literally means, i am going to house.
similarly, 

mi		lon		ma
i 		exist	land

means, i am here (i exist on this land). 

note that prepositions do not and can not
have the `e` marker! 

mi		lon		e		ma
i		exist	[obj]	land

here, the exist becomes a 使动用法, meaning
"i make land exist" or "i create a world"! 
quite an unusual statement... unless you're
playing minecraft. 

i should probably mention the effect of 
replacing `li` (or with `mi` or `sina`
sentences, just adding) with `o` - turning
a statement into a command. 

sina	moku
you		eat
(you are eating.)

sina	o		moku
you		command	eat
(oh you, eat!)

now is time to introduce linking sentences! 

"la" is the context modifier. it can be used
a variety of ways, like

mi (me) la = to me / from my perspective
ni (this) la = if so / if this is the case
ken (can) la = if this is possible
ala (not) la = otherwise
ona (it) la = as compared to it

this also works with more complex stuff, like

tenpo (time) kama (come) la
 = in the coming time, in the future
wile (require) sina (you) la
 = if you require so

or even full on sentences! 

sina wile sona la sina o   pali mute. 
you  want know -> you  cmd work many
(if you want to learn, then you should
put in a lot of work.) 

taso is "but", and basically works like
the two-sentence la. 

tan is a preposition for "because", like this:

mi la sina pona tan ni:   sina suwi
me -> you  good b/c this: you  sweet
(to me, you're good because you're sweet)

note how the "ni:" transition is required
for tan. mi la sina pona tan sina suwi
is grammatically incorrect. 

its 11:52, ill have to hurry up lol
there are two types of yes/no questions in
toki pona - asking and checking. 

sina moku ala moku?
you  eat  not eat?

pretty obvious how that works. 

sina moku, ansm (short for anu seme)?
you  eat,                  or  what

latter is just checking, showing the
inclination of sina moku. it is not intended
to be rude. 

for "what / who / when" kind of questions, 
just use seme. 

sina pali  e  seme? 
you  build >> what? 

jan    seme li pali? 
person what >  build?

tenpo seme la sina pali? 
time  what -> you  build?

ok now im submitting, i think thats all there
is to toki pona except the vocab

oh and pronouns. im jan Nanpa. 

i guess you should check out wasona. 


**/
