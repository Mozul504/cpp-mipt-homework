#include <stdio.h>

struct date
{
    int day;
    int month;
    int year;
};
typedef struct date Date;

struct book
{
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

struct movie
{
    char title[50];
    float rating;
    Date release_date;
};
typedef struct movie Movie;

int main(void)
{
    // ── 1. Book ───────────────────────────────────────
    Book b = {"Fahrenheit 451", 400, 700.0};

    Book*   pb     = &b;
    float*  pprice = &b.price;
    char*   pc     = &b.title[0];

    printf("pb->title = %s\n", pb->title);
    printf("*pprice   = %.1f\n", *pprice);
    printf("*pc       = %c\n", *pc);

    // ── 2. Movie a ────────────────────────────────────
    Movie a = {"Inception", 8.7, {8, 6, 2010}};
    Movie* p = &a;

    p->rating += 1;
    p->release_date.month += 1;

    printf("rating = %.1f, month = %d\n", a.rating, a.release_date.month);

    // ── 3. Массив Movie ───────────────────────────────
    Movie array[3] = {
        {"Inception", 8.661, {8, 6, 2010}},
        {"Green Mile", 9.062, {6, 12, 1999}},
        {"Leon", 8.679, {14, 9, 1994}}
    };
    Movie* q = &array[1];

    (q - 1)->rating += 1;             // Inception
    (q + 1)->release_date.year *= 2;  // Leon

    printf("Inception rating = %.3f\n", array[0].rating);
    printf("Leon year        = %d\n",   array[2].release_date.year);

    return 0;
}
