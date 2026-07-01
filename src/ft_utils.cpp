#include <stdio.h>
#include "config.h"

void print_col(const char *color, const char *str)
{
    printf("%s%s%s%s",MSG_ERR , color, str, RESET);
}

// int main()
// {
//     print_col(YELLOW, "Hello Warining\n");
// }