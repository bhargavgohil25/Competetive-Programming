#include <iostream>
using namespace std;
#define ll long long

ll floor_div(ll a, ll b) {
	return (a / b - (( a ^ b ) < 0 and a % b != 0));
} 

ll ceil_div(ll a, ll b) {
	return (a / b + (( a ^ b ) > 0 and a % b !=0));
}


int main() {
	ll a, b;

	while(cin >> a >> b) {
		cout << ceil_div(a, b) << ' ' << floor_div(a, b);
	}

}
