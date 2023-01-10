int multiply(int num1, int num2) {
    return (num1 * 1LL * num2) % mod;
}
    
int add(int num1, int num2) {
    return (num1 + num2) % mod;
}

int divide(int num1, int num2) {
    int inverseOfNum2 = getPow(num2, mod - 2);
    return multiply(num1, inverseOfNum2);
}

int getPow(int a, int b) {
    if(b == 0)
        return 1;
    else if(b & 1)
        return multiply(a, getPow(a, b - 1));
    return getPow(multiply(a, a), b >> 1) % mod;
}
    
void fillFactorial() {
  fact[0] = 1;
  for(int i = 1; i < N; i++) {
      fact[i] = multiply(fact[i - 1], i);
  }
}
