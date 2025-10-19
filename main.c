#include <stdio.h>

int ten_pow(int n);

int main(int argc, char *argv[]) {

  // Declare variables
  float a = 0, b = 0, res = 0;
  char a_dec_depth = 0, b_dec_depth = 0, oper = 0, in = 0;

  // Print Prompt Line
  printf("> ");

  // Read input char by char and load variables a, b and oper
  do {
    in = getchar();
    if ('0' <= in && in <= '9') {
      int tmp;
      if (oper == 0) {
        tmp = ten_pow(a_dec_depth);
        if (a_dec_depth == 0)
          a *= 10;
        else
          a_dec_depth++;
        a += (float)(in - '0') / tmp;
      } else {
        tmp = ten_pow(b_dec_depth);
        if (b_dec_depth == 0)
          b *= 10;
        else
          b_dec_depth++;
        b += (float)(in - '0') / tmp;
      }
    } else if (in == '.') {
      if (oper == 0)
        a_dec_depth = 1;
      else
        b_dec_depth = 1;
    } else if (in == '*' || in == '+' || in == '-' || in == '/') {
      oper = in;
    }
  } while (in != '\n' && in != EOF);

  // Actually do the operation
  if (oper == '+') {
    res = a + b;
  } else if (oper == '-') {
    res = a - b;
  } else if (oper == '*') {
    res = a * b;
  } else if (oper == '/') {
    res = a / b;
  }

  printf("%f\n", res);

  return 0;
}

int ten_pow(int n) {
  int x;
  if (n == 0)
    return 1;
  if (n % 2 == 0) {
    x = ten_pow(n / 2);
    return x * x;
  } else
    return 10 * ten_pow(n - 1);
}
