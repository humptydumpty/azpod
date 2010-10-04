#include<stdio.h>
#include<ctype.h>

char t[] = {
    0, 0, 0, 0, 0, 0, 12, 18, 33, 63,
    33, 33, 62, 32, 62, 33, 33, 62, 30, 33,
    32, 32, 33, 30, 62, 33, 33, 33, 33, 62,
    63, 32, 62, 32, 32, 63, 63, 32, 62, 32,
    32, 32, 30, 33, 32, 39, 33, 30, 33, 33,
    63, 33, 33, 33, 4, 4, 4, 4, 4, 4,
    1, 1, 1, 1, 33, 30, 33, 34, 60, 36,
    34, 33, 32, 32, 32, 32, 32, 63, 33, 51,
    45, 33, 33, 33, 33, 49, 41, 37, 35, 33,
    30, 33, 33, 33, 33, 30, 62, 33, 33, 62,
    32, 32, 30, 33, 33, 37, 34, 29, 62, 33,
    33, 62, 34, 33, 30, 32, 30, 1, 33, 30,
    31, 4, 4, 4, 4, 4, 33, 33, 33, 33,
    33, 30, 33, 33, 33, 33, 18, 12, 33, 33,
    33, 45, 51, 33, 33, 18, 12, 12, 18, 33,
    17, 10, 4, 4, 4, 4, 63, 2, 4, 8,
    16, 63
};

int main(int argc, char** argv) {

    int r, pr;
    for (r = 0; r < 6; ++r) {
        char *p = argv[1];

        while (pr && *p) {
            int o = (toupper(*p++) - 'A')*6 + 6 + r;
            o = (o < 0 || o >= sizeof (t)) ? 0 : o;
            for (pr = 5; pr >= -1; --pr) {
                printf("%c", (((pr >= 0) && (t[o]&(1 << pr))) ? '#' : ' '));

            }
        }
        printf("\n");
    }
    return 0;
}
