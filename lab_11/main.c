// 22 Подсчитать количество слов, содержащих  не менее 3-х букв
#include <stdio.h>
#include <ctype.h>

int main() {
    char input_string[1000];
    printf("Введите строку: ");
    fgets(input_string, sizeof(input_string), stdin);

    int word_count = 0;
	int char_count = 0; // Счетчик слов

    // Флаг, указывающий, находимся ли мы внутри слова
    int inside_word = 0;

    for (int i = 0; input_string[i] != '\0'; i++) {
		if(char_count == 3){
			word_count++;
		}
        char current_char = input_string[i];

        if (isalpha(current_char)) {
            // Если текущий символ буква, устанавливаем флаг внутри слова
            inside_word = 1;
			char_count++;
        } else if (isspace(current_char) || current_char == '\n') {
            if (inside_word) {
                inside_word = 0;
				char_count = 0;
            }
        }
    }


    printf("Количество слов, содержащих не менее трех букв: %d\n", word_count);

    return 0;
}
