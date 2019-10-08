LL fen[N];
LL sum(int i) {
    LL res = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1) res += fen[i];
    return res;
}

LL sum(int i, int j) {
    return sum(j) - sum(i - 1);
}

void add(int i, int d) {
    for (; i < N; i |= i + 1) fen[i] += d;
}

void build(int *a, int n) {
    memset(fen, 0, sizeof(fen));
    for (int i = 0; i < n; ++i) {
        fen[i] += a[i];
        if ((i | i + 1) < n) fen[i | i + 1] += fen[i];
    }
}
