#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 4096   // максимальная длина строки

int main(int argc, char *argv[])
{
    // ── 1. Проверка количества аргументов ─────────────────────────────
    if (argc != 4)
    {
        printf("Error: Wrong number of arguments!\n");
        printf("Usage: %s <input_file> <output_file> <lines>\n", argv[0]);
        return 1;
    }

    // ── 2. Открытие входного файла на чтение ──────────────────────────
    FILE *in = fopen(argv[1], "r");
    if (in == NULL)
    {
        // файл не существует или нет прав на чтение
        printf("Error: File %s does not exist!\n", argv[1]);
        return 1;
    }

    // ── 3. Разбор третьего аргумента: одна строка или диапазон ────────
    int start = 0;      // начало диапазона (или номер единственной строки)
    int end   = 0;      // конец диапазона
    int is_range = 0;   // 1, если задан диапазон "a:b"; 0, если одно число
    int pos = 0;        // для %n — сколько символов прочитано

    // Сначала пробуем формат "начало:конец"
    if (sscanf(argv[3], "%d:%d%n", &start, &end, &pos) == 2
        && argv[3][pos] == '\0')
    {
        is_range = 1;
    }
    // Иначе пробуем просто одно число
    else if (sscanf(argv[3], "%d%n", &start, &pos) == 1
             && argv[3][pos] == '\0')
    {
        is_range = 0;
        end = start + 1;    // для одной строки "диапазон" [start, start+1)
    }
    else
    {
        // ни "a:b", ни "a" — неверный формат
        printf("Error: Wrong lines format!\n");
        fclose(in);
        return 1;
    }

    // Проверим, что начало не больше конца и оба положительные
    if (start <= 0 || end <= start)
    {
        printf("Error: Wrong lines format!\n");
        fclose(in);
        return 1;
    }

    // ── 4. Открытие выходного файла на запись ─────────────────────────
    FILE *out = fopen(argv[2], "w");
    if (out == NULL)
    {
        printf("Error: cannot open '%s'\n", argv[2]);
        fclose(in);
        return 1;
    }

    // ── 5. Чтение входного файла построчно ────────────────────────────
    char line[MAX_LINE];    // буфер под одну строку
    int line_no = 0;        // текущий номер строки

    // fgets читает строку до '\n' (включительно) или до MAX_LINE-1 символов
    while (fgets(line, MAX_LINE, in) != NULL)
    {
        line_no++;   // увеличиваем номер строки

        // Если текущая строка попадает в диапазон [start, end)
        if (line_no >= start && line_no < end)
        {
            // записываем её в выходной файл
            fputs(line, out);
        }

        // если дошли до конца диапазона — можно остановиться
        if (line_no >= end)
            break;
    }

    // ── 6. Закрытие файлов ────────────────────────────────────────────
    fclose(in);
    fclose(out);

    return 0;
}
