#include<stdio.h>

typedef struct {
    long val;
    long state;
} no;

long ll = 250000;

long a2[42];

long cal2(long i) {
    no sc[ll];
    long j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    long x, y, z, zz, zzz, zzzz;
    for (x = 0; x <= i; x++) {
        for (y = 0; y <= i; y++) {
            long te1 = a2[x] + a2[y];
            for (z = 0; z <= i; z++) {
                long te2 = te1 + a2[z];
                for (zzz = 0; zzz <= i; zzz++) {
                    long te3 = te2 + a2[zzz];
                    for (zzzz = 0; zzzz <= i; zzzz++) {
                        long te4 = te3 + a2[zzzz];
                        for (zz = 0; zz <= i; zz++) {
                            long temp = te4 + a2[zz];
                            if (sc[temp].state == 0)
                                sc[temp].state = 1;
                        }
                    }
                }
            }
        }
    }

    long count = 0;
    for (i = 0; i <= ll; i++) {
        if (sc[i].state == 1)count++;
        else if (sc[i].state == 0)break;
    }

    return count;

}

long calculate(long i, long door) {
    if (door == 2)return cal2(i);
}

long main() {

    FILE *fo = fopen("X:\\d\\sod6.out", "r");

    long a[10][10];
    long score[10];
    long p;
    for (p = 0; p < 10; p++) {
        score[p] = 0;
    }

    long t, tt;

    a2[0] = 0;
    for (t = 1; t <= 92; t++) {

        printf("%d\n", t);
        for (tt = 0; tt < 11; tt++) {
            fscanf(fo, "%d,", &a2[tt + 1]);
        }
        long decision[10];
        long i, j;
        for (i = 1; i <= 10; i++) {
            long res1 = score[i];
            long res2 = calculate(i, 2);
            if (res1 >= res2)decision[i] = 1;
            else decision[i] = 2;
        }

        for (i = 1; i < 11; i++) {
            if (decision[i] == 2) {
                for (j = 1; j <= i; j++) {
                    a[i - 1][j - 1] = a2[j];
                    score[i] = calculate(i, 2);
                }
            }
        }

    }

    fclose(fo);

    FILE *fpe = fopen("X:\\d\\sod6_result.out", "w");
    long i, j;
    for (i = 1; i <= 10; i++) {
        fprintf(fpe, "\n6: ");
        for (j = 1; j <= i; j++) {
            if (j != i)
                fprintf(fpe, "%d, ", a[i - 1][j - 1]);
            else
                fprintf(fpe, "%d", a[i - 1][j - 1]);
        }
        if (i != 10)fprintf(fpe, ";");
    }
    fclose(fpe);

    return 0;

}
