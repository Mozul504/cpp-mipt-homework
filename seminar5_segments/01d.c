#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book {
    char title[50];
    int pages;
    float price;
};
typedef struct book Book;

void print_book(const Book* b) {
    printf("Book: %s, Pages: %d, Price: %.2f\n", b->title, b->pages, b->price);
}

struct library {
    Book* books;
    int number_of_books;
};
typedef struct library Library;

void library_create(Library* lib, int num) {
    lib->number_of_books = num;
    lib->books = (Book*)malloc(num * sizeof(Book)); 
}

void library_set(Library* lib, int i, const char* title, int pages, float price) {
    strcpy(lib->books[i].title, title);
    lib->books[i].pages = pages;
    lib->books[i].price = price;
}

Book* library_get(Library* lib, int i) {
    return &lib->books[i];
}

void library_print(Library* lib) {
    for (int i = 0; i < lib->number_of_books; i++) {
        print_book(&lib->books[i]);
    }
}

void library_destroy(Library* lib) {
    free(lib->books);
    lib->books = NULL;
    lib->number_of_books = 0;
}

int main() {
    size_t* p_sz = (size_t*)malloc(sizeof(size_t));
    *p_sz = 42;
    printf("a: %zu\n", *p_sz);
    free(p_sz);

    char* str1 = (char*)malloc(5 * sizeof(char));
    strcpy(str1, "Cat");
    printf("b: %s\n", str1);
    free(str1);

    char** str2 = (char**)malloc(sizeof(char*));
    *str2 = (char*)malloc(5 * sizeof(char));
    strcpy(*str2, "Dog");
    printf("c: %s\n", *str2);
    free(*str2);
    free(str2);

    Book* b1 = (Book*)malloc(sizeof(Book));
    strcpy(b1->title, "War and Peace");
    b1->pages = 1225;
    b1->price = 2000.0;
    printf("d: "); print_book(b1);
    free(b1);

    Book b2 = {"Stack Book", 100, 500.0};
    Book* ptr_b2 = &b2;
    printf("e: "); print_book(ptr_b2);

    Book* b3 = (Book*)malloc(sizeof(Book));
    Book* ptr_b3 = b3;
    strcpy(ptr_b3->title, "Heap Book");
    ptr_b3->pages = 200;
    ptr_b3->price = 600.0;
    printf("f: "); print_book(ptr_b3);
    free(b3);

    Book* arr_b = (Book*)malloc(2 * sizeof(Book));
    strcpy(arr_b[0].title, "Book 1"); arr_b[0].pages = 10; arr_b[0].price = 1.0;
    strcpy(arr_b[1].title, "Book 2"); arr_b[1].pages = 20; arr_b[1].price = 2.0;
    printf("g:\n"); print_book(&arr_b[0]); print_book(&arr_b[1]);
    free(arr_b);
  
    Book* b4 = (Book*)malloc(sizeof(Book));
    

    Library lib;
    library_create(&lib, 2);
    library_set(&lib, 0, "Don Quixote", 1000, 750.0);
    library_set(&lib, 1, "Oblomov", 400, 250.0);
    printf("i:\n"); library_print(&lib);
    library_destroy(&lib);

    return 0;
}
