LL m[N];
void build(int *a, int n) {
    m[0] = a[0];
    for (int i = 1; i < n; ++i) m[i] = a[i] + m[i - 1];
}

LL sum(int l, int r) {
    return m[r] - (l ? m[l - 1] : 0);
}
