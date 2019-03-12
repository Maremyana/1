#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void reverse_text()
{
	setlocale(LC_ALL, "Rus");
	const unsigned int max_word_count = 10;
	const unsigned int max_chars_count = 128;

	char words[max_word_count][max_chars_count];
	int words_count = 0;
	char str[] = "наконец-то наступила весна";
	int str_len = strlen(str);
	int last_sep = 0;

	printf_s(" %s \n", str);

	for (int i = 0; i <= str_len; i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			int w_len = 0;
			for (int j = last_sep; j < i; j++) {
				words[words_count][w_len] = str[j];
				w_len++;
			}
			words[words_count][w_len] = '\0';
			last_sep = i + 1;
			words_count++;
		}
	}
	
	char tmp[max_chars_count];
	strcpy_s(tmp, words[0]);
	strcpy_s(words[0], words[words_count - 1]);
	strcpy_s(words[words_count - 1], tmp);

	
	for (int i = 0; i < words_count; i++) {
		printf_s(" %s ", words[i]);
	}
	printf_s("\n");
}


int main()
{
	reverse_text();
	system("pause");
	return 0;
}









/*
void strcpy(char *a, char *b){
	int b_len = strlen(b);
	for(int i = 0; a[i] != '\0' && i < b_len; i++){
		b[i] = a[i];
	}	
}*/