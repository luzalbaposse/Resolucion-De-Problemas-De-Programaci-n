#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
#define mx 200005
#define ll long long

ll a[mx];
ll tree[mx * 3];
int indx;

// idea: uso un segment tree p/#habitaciones
void init(ll node, ll b, ll e) {
    if (b == e) {
        tree[node] = a[b];
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
    tree[node] = max(tree[left], tree[right]);
}

// chequeo el primer hotel con hab >= k
void query(ll node, ll b, ll e, ll k, ll n) {
    if (b == e) {
        if (tree[node] >= k) {
            indx = b;
        }
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;

    if (tree[left] >= k) {
        query(left, b, mid, k, n);
    } else {
        query(right, mid + 1, e, k, n);
    }
}

// cambia segment tree después de las habitaciones
void update(ll node, ll b, ll e, ll i, ll newvalue) {
    if (i > e || i < b) return;
    if (b == e) {
        tree[node] -= newvalue;
        return;
    }
    ll left = node * 2;
    ll right = node * 2 + 1;
    ll mid = (b + e) / 2;
    update(left, b, mid, i, newvalue);
    update(right, mid + 1, e, i, newvalue);
    tree[node] = max(tree[left], tree[right]);
}

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> qq(q);

    // num d habitaciones de cada hotel
    for (ll i = 1; i <= n; i++) cin >> a[i];

    // requisitos de cada grupo
    for (ll i = 0; i < q; i++) cin >> qq[i];

    //  segment tree
    init(1, 1, n);

    // grupso
    for (int i = 0; i < q; i++) {
        indx = -1;
        query(1, 1, n, qq[i], n);
        if (indx == -1) {
            cout << 0 << " ";
        } else {
            cout << indx << " ";
            update(1, 1, n, indx, qq[i]);
        }
    }

    cout << endl;
    return 0;
}
