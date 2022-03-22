#include <bits/stdc++.h>
using namespace std;
#define MAX 4000001
int N, M, K, L, S[MAX], P[MAX];
int find(int n) {
  if(n == P[n]) return n;
  return P[n] = find(P[n]);
}
void union_find(int a, int b) {
  a = find(a);
  b = find(b);
  if(a == b) return;
  P[b] = a;
}
int main() {
  cin >> N >> M >> K;
  for(int i = 0; i < M; i++) {
    scanf("%d ", &S[i]);
    P[i] = i;
  }
  sort(S, S + M);
  for(int i = 0; i < K; i++) {
    scanf("%d ", &L);
    int idx = find(upper_bound(S, S + M, L) - S);
    printf("%d\n", S[idx]);
    union_find(idx + 1, idx);
  }
  return 0;
}
