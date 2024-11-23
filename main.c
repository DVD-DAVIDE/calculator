#include <stdio.h>

int main(int argc, char *argv[]) {
	
	// Declare variables
	float a = 0,
	      b = 0,
	      res = 0;
	char oper = 0,
	     in = 0;

	// Print Prompt Line
	printf("> ");

	// Read input char by char and load variables a, b and oper
	do {
		in = getchar();
		if ('0' <= in && in <= '9') {
			if (oper == 0) {
				a *= 10;
				a += in - '0';
			} else {
				b *= 10;
				b += in - '0';
			}
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
