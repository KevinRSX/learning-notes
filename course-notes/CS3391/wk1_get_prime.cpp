#include <cstdio>
#include <cstring>
#define MAXN 1000000

bool isprime[MAXN];
int prime_list[MAXN];

void eratos(int n)
{
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  for (int i = 2; i * i <= n; i++)
  {
    if (isprime[i])
    {
      for (int j = i * 2; j <= n; j += i)
        isprime[j] = false;
    }
  }
}

void linear_sieve(int n)
{
  memset(isprime, true, sizeof(isprime));
  isprime[0] = isprime[1] = false;
  int cnt = 0;
  for (int i = 2; i <= n; i++)
  {
    if (isprime[i]) prime_list[cnt++] = i;
    for (int j = 0; j < cnt && prime_list[j] * i <= n; j++)
    {
      isprime[prime_list[j] * i] = false;
      if (i % prime_list[j] == 0) break;
    }
  }
}

int main()
{
  eratos(999);
  for (int i = 0; i <= 999; i++)
  {
    if (isprime[i])
      printf("%d ", i);
  }
  printf("\n");

  linear_sieve(999);
  int i = 0;
  while (1)
  {
    printf("%d ", prime_list[i]);
    if (prime_list[i] == 997) break;
    i++;
  }
  printf("\n");
}
