#include <bits/stdc++.h>
using namespace std;

signed main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	/*
	1) <algorithm> sort
	-sorts the range [l,r) in ascending order where l and r are Random Access Iterators [Iterators are like pointers]
	 Best case TC->O(N), Average case TC->O(NlogN)
	*/
	int arr[5] = {1, 10, 3, 5, 4};
	sort(arr, arr + 5);
	for (int i = 0; i < 5; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	/*
	2) <algorithm> binary_search
	-bool binary_search(FwdIt l, FwdIt r, val)
	 Searches the range [l,r) for the value val [Must be in ascending order]
	 Best case TC->O(N), Average case TC->O(NlogN)
	*/
	int arr2[10] = {1, 3, 5, 5, 5, 7, 9, 11, 11, 13};
	cout << binary_search(arr2, arr2 + 10, 7) << endl;

	/*
	2.1) <algorithm> lower_bound
	-FwdIt lower_bound(FwdIt l, FwdIt r, val)
	 Finds left-most position that val can be inserted into the range such that range remains sorted.
	 Equivalently finds left-most element >= val
	 Best case TC->O(N), Average case TC->O(NlogN)
	*/
	int arr3[10] = {1, 3, 5, 5, 5, 7, 9, 11, 11, 13};
	cout << lower_bound(arr3, arr3 + 10, 8) - arr3 << endl; //Provides index of element just (<= val)

	/*
	2.1) <algorithm> upper_bound
	-FwdIt upper_bound(FwdIt l, FwdIt r, val)
	 Finds right-most position that val can be inserted into the range such that range remains sorted.
	 Equivalently finds left-most element > val
	 Best case TC->O(N), Average case TC->O(NlogN)
	*/
	int arr4[10] = {1, 3, 5, 5, 5, 7, 9, 11, 11, 13};
	cout << upper_bound(arr4, arr4 + 10, 2) - arr4 << endl; //Provides index of element just (> val)

	/*
	3) <algorithm> next_permutation
	-bool next_permutation(l,r)
	 Rearranges the range to form the next lexographically greater permutation.
	 If the range is already contains greatest permutation {decreasing order} false is returned and range is rearranged to form the smallest permutation
	 Best case TC->O(1) amortized, Average case TC->O(N)
	*/

	int arr5[3] = {2, 3, 1};
	bool res = next_permutation(arr5, arr5 + 3);
	for (int i = 0; i < 3; i++) {
		cout << arr5[i] << " ";
	}
	cout << endl;

	/*
	4) string
	Append a character
		Concatenate: s = s + "t";
		Append: s+="t";
	Time complexity of Appending character is better in comparision to Concatenation as Concatenation creates a new string which takes O(N) time.
	*/

	/*
	4.1) string
		If we want to take a string as an input which contains spaces - "abc 123"
		use - getline(cin,s);

	string s;
	getline(cin, s);
	cout << s << endl;
	*/

	// But if we have some input n which is to be taken before string input, use getline two times
	int n; cin >> n;
	string str;
	getline(cin, str);
	getline(cin, str);
	cout << str << endl;

	/*
	4.2) string
	To get a substring out of a string, use s.substr(index, length);
	*/
}
