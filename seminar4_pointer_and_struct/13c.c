#include <stdio.h>
#include <string.h>

#define MAX_GAMES 100
#define MAX_TITLE 50

struct game
{
    char title[MAX_TITLE];
    double avg;
};

int main(void)
{
    int n;
    scanf("%d", &n);

    struct game games[MAX_GAMES];

    for (int i = 0; i < n; i++)
    {
        char title[MAX_TITLE];
        char tmp;
        int k;

        scanf(" %[^:]", title);
        scanf("%c", &tmp);
        scanf("%d", &k);

        int sum = 0;
        for (int j = 0; j < k; j++)
        {
            int r;
            scanf("%d", &r);
            sum += r;
        }

        strcpy(games[i].title, title);
        games[i].avg = (double)sum / k;

        scanf("%c", &tmp);
    }

    // сортировка по убыванию среднего
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (games[j].avg < games[j + 1].avg)
            {
                struct game t = games[j];
                games[j] = games[j + 1];
                games[j + 1] = t;
            }

    for (int i = 0; i < n; i++)
        printf("%s, %.3f\n", games[i].title, games[i].avg);

    return 0;
}
