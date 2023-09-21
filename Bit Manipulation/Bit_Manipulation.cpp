#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int         int64_t
#define mod         1000000007
#define PI          3.141592653589793238462
#define __gcd(a,b)  gcd(abs(a),abs(b));
#define INF         1e18
#define ff          first
#define ss          second
#define pb          push_back
#define pii         pair<ll,ll>
#define mii         map<ll,ll>
#define max_heap    priority_queue<ll>
#define min_heap    priority_queue<ll,vector<ll>,greater<ll>>
#define vi          vector<ll>
#define setbits(x)  __builtin_popcountll(x)
#define ps(x,y)     fixed<<setprecision(y)<<x
#define bs          binary_search
#define lbnd        lower_bound
#define ubnd        upper_bound
#define endl        '\n'
#define all(a)      (a).begin(),(a).end()
#define ini(a, i)   memset(a, i, sizeof(a))
#define sz(x)       (ll)x.size()
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define lcm(a,b)    ((a)*(b)) / gcd((a),(b))
int gcd(int a, int b) { if (a == 0) return b; return gcd(b % a, a);}

int pow(int base, int x) {int ans = 1; while (x != 0) {if (x % 2 == 0) {base = base * base; x /= 2;} else ans = ans * base; x = x - 1;} return ans;}

bool isPrime(int N) {if (N < 2)return false; if (N < 4)return true; if ((N & 1) == 0)return false; if (N % 3 == 0)return false; int curr = 5, s = sqrt(N); while (curr <= s) {if (N % curr == 0)return false; curr += 2; if (N % curr == 0)return false; curr += 4;} return true;}


/*------------------------------------------------------------------------------------------------*/

void c_r_g() {
	/*
	Q1- You are given an array containing integers. Every integer occurs twice in array except one.
		Print that number which occurs only once in array.

		Input - arr[] = {2,1,2,5,6,5,7,7,6}

		Ans - Loop over the array and xor with the elements. As it is mentioned every element except one element
			  occurs twice in array {xor of equal numbers is = 0} so finally that number whose frequency is one will be
			  left out with us and that's our answer.
	*/


	vector<int>arr = {2, 1, 2, 5, 6, 5, 7, 7, 6};
	int ans = 0;
	for (int i = 0; i < arr.size(); i++) {
		ans = ans ^ arr[i];
	}
	cout << ans << endl;

	/*
	Q2- Swapping of two numbers using xor
		a = 5, b = 7 and we need to swap these two numbers

		Step 1 - a = a^b
		After this a = 5 ^ 7 , b = 7

		Step 2 - b = a^b
		After this a = 5 ^ 7 , b = 5 ^ 7 ^ 7 = 5

		Step 3 - a = a^b
		After this a = 5 ^ 7 ^ 5 = 7 and b = 5

		Therefore numbers are swapped
	*/

	int a = 5, b = 7;
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	cout << "Value of a: " << a << ", Value of b: " << b << endl;

	/*
	Q3- Given N, find the xor of all elements till N. {Not in O(N) time complexity}
		Input N = 5
		Output - 1 ^ 2 ^ 3 ^ 4 ^ 5 = 1

		Ans - Let's try to figure out some pattern
		N = 1 ------ 1
		N = 2 ------ 3
		N = 3 ------ 0
		N = 4 ------ 4

		N = 5 ------ 1
		N = 6 ------ 7
		N = 7 ------ 0
		N = 8 ------ 8

		The breakdown is in 4's multiple
		if N % 4 == 0 then ans = N
		else if N % 4 == 1 then ans = 1
		else if N % 4 == 2 then ans = N + 1
		else if N % 4 == 3 then ans = 0
		TC- O(1)
	*/

	int n; cin >> n;
	int myans = 0;
	if (n % 4 == 0) {
		myans = n;
	}
	else if (n % 4 == 1) {
		myans = 1;
	}
	else if (n % 4 == 2) {
		myans = n + 1;
	}
	else if (n % 4 == 3) {
		myans = 0;
	}
	cout << myans << endl;

	/*
	Q4- Given a range (L,R), print the xor (L ^ L+1 ^ L+2 ^ ..... R-1 ^ R)
		Input: L = 2, R = 4
		Ouput: 2 ^ 3 ^ 4 = 5

		What we can do is lets say L = 3 and R = 6
		Take out xor from 1 to 6  {1^2^3^4^5^6}
		Take out xor from 1 to 2  {1^2}
		xor these two equations we get 3^4^5^6 which we require.
		ans = XOR(R) ^ XOR(L-1) {TC-O(1)}
	*/

	/*
	Q5- Given a number N, check whether it is an odd number or an even number
	*/

	int num; cin >> num;
	if ((num & 1) == 0) {
		cout << "Even number" << endl;
	}
	else cout << "Odd number" << endl;

	/*
	Q6- Given {N,i} check ith bit of number N is set or not. {set means 1}
		Input N = 13 = (1101) and i = 2
		Output - Yes [Note bits starts from right to left and from 0]

		For i = 1
		Output - No
	*/

	/*

	int x; cin >> x;
	int ith; cin >> ith;
	int count = 0;
	while (x) {
		if (count == ith) {
			if (x & 1) {
				cout << "Bit is set" << endl;
			}
			else {
				cout << "Bit is not set" << endl;
			}
		}
		count++;
		x /= 2;
	}
	*/

	/*
	One Powerful way to do it is -
		Create a mask {containing all 0's except the position for which we have being asked whether bit is set or not}
		then we will do N & mask
		if that bit is 1 - (N & mask) will produce 1 otherwise (N & mask) will always produce 0

		Mask will be - 1 << ithBit
	*/
	int x; cin >> x;
	int ith; cin >> ith;
	int mask = 1 << ith;
	int res = x & mask;
	if (res == 0) {
		cout << "Bit is not set" << endl;
	}
	else cout << "Bit is set" << endl;

	/*
	Q7- Extract the ith bit of a number
		Input: N = 13, i = 3
		Output: 1

		//Similar to above question
	*/

	/*
	Q8- Set the ith bit of a number
		Input: 110010 and ith bit = 2
		Output: 110110

		Create a mask and do | operation it will set the bit
	*/

	int p, i; cin >> p >> i;
	int mymask = 1 << i;
	p = p | mymask;
	cout << p << endl;

	/*
	Q9- Clear the ith bit of a number {Change bit from 1 to 0}
		Input: 110110 and ith bit = 2
		Output: 110010

		Approach - we want something like 111011 {0 symbolizes that is given us to clear} and
		after doing & operation with the number N we will get 110010 which is our output

		Mask - we can create 000100 using 1<<i and we will flip the bits which will form 111011
	*/

	int num1; cin >> num1;
	int ithBit; cin >> ithBit;

	int mask1 = 1 << ithBit;
	mask1 = ~(mask1);
	num1 = num1 & mask1;
	cout << num1 << endl;

	/*
	Q10- Remove the last set bit of a number {Replace set bit with unset bit}
		 Input: N = 13 = 1 1 0 1

		 Approach do N & (N-1)
		 N-1 = 12 = 1 1 0 0
		 N & (N-1) = 1 1 0 0
	*/

	/*
	Q11 - Check if a number is a power of 2
		  Input: N = 16 = 10000
		  N-1 = 15 = 01111
		  if we do N & (N-1) and it comes out 0 then it's a power of 2
	*/

	int num2; cin >> num2;
	if ((num2 & (num2 - 1)) == 0) {
		cout << "Power of 2" << endl;
	}
	else cout << "Not a power of 2" << endl;

	/*
	Q11 - Count number of set bits in a number
		  Input: N = 14 = 1110
		  Number of set bits = 3
	*/

	int N; cin >> N;
	int countBits = 0;
	while (N != 0) {
		if ((N & 1) == 1) {
			countBits++;
		}
		N = N >> 1;
	}
	cout << "Number of countBits: " << countBits << endl;
}
signed main() {
	ios
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int test = 1;
	// cin >> test;
	while (test--) {
		c_r_g();
		cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
	}
}
