#include <stdio.h>

enum shape { ROCK, PAPER, SCISSORS };

enum result { LOSS, DRAW, WIN };

void print_shape(enum shape s)
{
    switch (s)
    {
        case ROCK:     printf("Rock\n");     break;
        case PAPER:    printf("Paper\n");    break;
        case SCISSORS: printf("Scissors\n"); break;
    }
}

void print_result(enum result r)
{
    switch (r)
    {
        case LOSS: printf("Loss\n"); break;
        case DRAW: printf("Draw\n"); break;
        case WIN:  printf("Win\n");  break;
    }
}

enum shape get_strength(enum shape s)
{
    switch (s)
    {
        case ROCK:     return PAPER;      
        case PAPER:    return SCISSORS;  
        case SCISSORS: return ROCK;       
    }
    return s;   
}


enum result get_result(enum shape a, enum shape b)
{
    if (a == b)
        return DRAW;

    if (get_strength(a) == b)
        return LOSS;  

    return WIN;       
}

int main(void)
{
    print_shape(ROCK);             
    print_shape(PAPER);           
    print_shape(SCISSORS);        

    print_result(LOSS);           
    print_result(DRAW);            
    print_result(WIN);              

    print_result(get_result(ROCK, SCISSORS));  
    print_result(get_result(ROCK, PAPER));      
    print_result(get_result(ROCK, ROCK));      

    return 0;
}
