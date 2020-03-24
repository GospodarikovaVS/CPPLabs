// Lab1.cpp: определяет точку входа для консольного приложения.
// crt_snscanf.c
// compile with: /W3

#include "stdafx.h"
#include <stdio.h>
#include <stdarg.h>
#include <vector>
#include<string.h>
#include<string>

void my_snscanf(char* input, size_t length, char* format, ...)
{
	//void* pformat = &format;
	va_list args;
	va_start(args, format);
	size_t counter = length;

	char* pinput = input;
	char* pformat = format;

	while (*pformat != '\0' && counter > 0) {		
		switch (*pformat) {
		case 's': {
			char* cur = va_arg(args, char*);
			int i = 0;
			while ((*pinput != ' ' && *pinput != '\0') && counter > 0) {
				counter -= sizeof(char);
				cur[i] = *pinput;
				pinput++;
				i++;
			}
			cur[i] = '\0';
			pinput++;
			counter -= sizeof(char);
			break;
		}
		case 'd': {
			int* cur_int = va_arg(args, int*);
			char* cur = new char[counter];
			int i = 0;
			while ((*pinput != ' ' && *pinput != '\0') && counter > 0) {
				counter -= sizeof(char);
				cur[i] = *pinput;
				pinput++;
				i++;
			}
			cur[i] = '\0';
			*cur_int = std::atoi(cur);
			pinput++;
			counter -= sizeof(char);
			break;
		}
		case 'f': {
			float* cur_int = va_arg(args, float*);
			char* cur = new char[counter];
			int i = 0;
			while ((*pinput != ' ' && *pinput != '\0') && counter > 0) {
				counter -= sizeof(char);
				cur[i] = *pinput;
				pinput++;
				i++;
			}
			cur[i] = '\0';
			*cur_int = std::stof(cur);
			pinput++;
			counter -= sizeof(char);
			break;
		}
		default: {
			break;
		}
		}
		pformat++;
	}

	va_end(args);
}

int main()
{
	char str1[] = "alter 3 0.7 fr...";
	int i = 2, in = 789;
	float fp=0.127F;
	char* str2 = new char[1000];
	char* str3 = new char[1000];

	/*i = _snscanf(str1, 16, "%s %s %d %f", s1, s2, &in, &fp);
	printf("_snscanf converted %d fields: ", i);
	printf("%s and %s and %d and %f\n", s1, s2, in, fp);*/

	my_snscanf(str1, 13, "%s %d %f\0", str2, &i, &fp);
	printf(str2);
	printf("\n");
	printf(std::to_string(i).c_str());
	printf("\n");
	printf(std::to_string(fp).c_str());
	printf("\n");
	return 0;
}



