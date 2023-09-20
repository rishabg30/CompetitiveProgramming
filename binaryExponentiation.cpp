#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

#define ios         ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define int         int64_t
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

//Calculate a^b mod 10^9+7
//1011
int binary_exponentiation(int a, int b, int mod) {
	int ans = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			//This means last bit is 1
			ans = (1LL * ans * a) % mod;
		}
		a = (1LL * a * a) % mod;
		b = b / 2;
	}
	return ans;
}
void c_r_g() {
	int a, b; cin >> a >> b;
	cout << binary_exponentiation(a, b, 1e9 + 7) << endl;
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
