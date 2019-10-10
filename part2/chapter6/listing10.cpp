LL fen[N], fent[N];

void build(int *a, int n) {
    memset(fen, 0, sizeof(fen));
    memset(fent, 0, sizeof(fent));
    for (int i = 0; i < n; ++i) {
        fen[i] += a[i];
        if ((i | i + 1) < n) fen[i | i + 1] += fen[i];
    }
}

void add(int i, int d) {
    for ( ; i < N; i |= i + 1) fen[i] += d;
}

void add_prefix(int r, int d) {
    if (r < 0) return ;
    for (int i = r; i >= 0; i = (i & i + 1) - 1) fent[i] += d;
    for (int i = r | r + 1; i < N; i |= i + 1) fen[i] += d * (r - (i + 1 & i) + 1);
}

void add(int l, int r, int d) {
    add_prefix(r, d);
    add_prefix(l - 1, -d);
}
