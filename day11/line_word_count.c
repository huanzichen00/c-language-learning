#include <stdio.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("用法: ./line_word_count <input> <output>\n");
        return 1;
    }

    FILE *fin = fopen(argv[1], "r");
    if (fin == NULL) {
        printf("无法打开输入文件\n");
        return 1;
    }
    
    FILE *fout = fopen(argv[2], "w");
    if (fout == NULL) {
        printf("无法打开输出文件\n");
        fclose(fin);
        return 1;
    }
    
    char buf[512];
    int lines = 0;
    int words = 0;

    int in_word = 0;
    int i = 0;
    while (fgets(buf, sizeof(buf), fin) != NULL) {
        lines++;
        for (i = 0; buf[i] != '\0'; i++) {
            if (isspace((unsigned char)buf[i])) {
                in_word = 0;
            } else if (!in_word) {
                words++;
                in_word = 1;
            }
        }
    }

    fprintf(fout, "lines=%d\n", lines);
    fprintf(fout, "words=%d\n", words);

    fclose(fout);
    fclose(fin);
    return 0;
}
