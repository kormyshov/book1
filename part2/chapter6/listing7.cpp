int fen[N][M];
LL sum(int i, int jj) {
    LL res = 0;
    for (; i >= 0; i = (i & i + 1) - 1)
        for (int j = jj; j >= 0; j = (j & j + 1) - 1)
            res += fen[i][j];
    return res;
}

LL sum(int li, int lj, int ri, int rj) {
   return sum(ri, rj) — sum(ri, lj - 1) — sum(li - 1, rj) + sum(li - 1,lj - 1);
}

void add(int i, int jj, int d) {
    for (; i < N; i |= i + 1)
        for (int j = jj; j < M; j |= j + 1)
            fen[i][j] += d;
}
