map<int, LL> fen;
LL sum(int i) {
    LL res = 0;
    for (; i >= 0; i = (i & i + 1) - 1)
        if (fen.count(i)) res += fen[i];
    return res;
}

LL sum(int i, int j) {
    return sum(j) - sum(i - 1);
}

void add(int i, int d) {
    for (; i < N; i |= i + 1) fen[i] += d;
}
