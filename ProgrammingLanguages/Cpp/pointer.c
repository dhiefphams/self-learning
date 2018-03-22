#include <stdio.h>
#include <stdarg.h>
#include <time.h>

int logf_q(char* format, ...) {
	va_list args;
	time_t sys_time;
	char* time_str;
	int return_val;

	sys_time = time(NULL); // sys time in secs since epoch
	time_str = ctime(&sys_time); // ready-to-print timestamp
	printf("%s", time_str);

	// get our of varlist
	va_start(args, format);
	return_val = vprintf(format, args);

	// done the reading list
	va_end(args);
	
	return return_val;
}

float average(int count, ...) {
	float avg = 0.0;
	int i;
	va_list args;
	va_start(args, count);

	for (i = 0; i < count; ++i) {
		int val = va_arg(args, int);
		avg += (float) val;
	}
	va_end(args);
	return avg / count;
}

int main() {
	printf("A long uses %d of memory\n", sizeof(long));
	logf_q("AVG(1, 2, 3, 4, 5) = %.2f\n", average(5, 1, 2, 2, 3, 5));
}