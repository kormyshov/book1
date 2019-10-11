int t[N * 2];
int d;

void build(int *a, int n) {
    d = n;
    for (int i = d; i < d + n; ++i) t[i] = a[i - d];
    for (int i = d + n; i < d + d; ++i) t[i] = INF;
    for (int i = d - 1; i; --i)
        t[i] = t[i * 2] < t[i * 2 + 1] ? t[i * 2] : t[i * 2 + 1];
}

int get_min(int l, int r) {
    int res = INF;
    for (l += d, r += d; l <= r; ++l >>= 1, --r >>= 1) {
        if (l & 1) if (t[l] < res) res = t[l];
        if (~r & 1) if (t[r] < res) res = t[r];
    }
    return res;
}

void set_val(int i, int val) {
    t[i += d] = val;
    for (i >>= 1; i; i >>= 1)
        t[i] = t[i * 2] < t[i * 2 + 1] ? t[i * 2] : t[i * 2 + 1];
}
