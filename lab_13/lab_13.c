#include <stdio.h>
#include <ctype.h>
// 20-26 Есть ли слово, все согласные которого - свистящие
#define SWISH ((1U << ('s' - 'a')) | (1U << ('w' - 'a')) | (1U << ('z' - 'a')) | (1U << ('h' - 'a')))

unsigned int char_to_set(char c) {
    c = tolower(c);

    if (c < 'a' || c > 'z') {
        return 0;
    } else {
        return 1U << (c - 'a');
    }
}

int main() {
    char alpha;
    int c;
    unsigned int letters_set = 0;
    int word_count = 0;
    int in_word = 0;

    while ((c = getchar()) != EOF) {
        if (isspace(c) || (c == '\n')) {
            if (in_word) {
                int is_consonant_word = 1;
                for (alpha = 'a'; alpha <= 'z'; alpha++) {
                    if (letters_set & char_to_set(alpha)) {
                        if ((~SWISH & char_to_set(alpha)) != 0) {
                            is_consonant_word = 0;
                            break;
                        }
                    }
                }
                if (is_consonant_word) {
                    printf("Word %d consists only of consonants", word_count);
                    for (alpha = 'a'; alpha <= 'z'; alpha++) {
                        if (letters_set & char_to_set(alpha)) {
                            if ((~SWISH & char_to_set(alpha)) != 0) {
                                printf("%c", alpha);
                            }
                        }
                    }
                    printf("\n");
                }
            }
            word_count++;
            in_word = 0;
            letters_set = 0;
        } else {
            in_word = 1;
            letters_set |= char_to_set(c);
        }
    }

    letters_set = letters_set & ~SWISH;

    for (alpha = 'a'; alpha <= 'z'; alpha++) {
        if (letters_set & char_to_set(alpha)) {
            if ((~SWISH & char_to_set(alpha))) {
                printf("Set does not consist only of consonants: %c\n", alpha);
            }
        }
    }
    printf("\n");
    return 0;
}
