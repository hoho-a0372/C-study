#include <stdio.h>
#include <time.h>
#include <string.h>
int main() {
	struct tm* t;
	time_t now;
	now = time(NULL);
	t = localtime(&now);

	char* week[7] = {"일","월","화","수","목","금","토" }, apm[] = { "오후" };
	int apm_hour = t->tm_hour+(t->tm_hour>12?-12:0);
	if (t->tm_hour < 12)
		strcpy(apm, "오전");

	printf("오늘은 %d년 %d월 %d일 %s요일입니다.\n", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday, *(week+t->tm_wday));
	printf("현재시간은 %s %d시 %d분 %d초입니다.\n", apm, apm_hour, t->tm_min, t->tm_sec);
}
