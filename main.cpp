#include <stdio.h>

int main( int argc, const char* argv[] )
{
    //Fixes Eclipse console not displaying anything.
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);


    puts("Hello World!");
    getchar();

    return 0;
}
