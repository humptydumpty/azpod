#include<stdio.h>

typedef struct {
    int val;
    int state;
} no;

int ll = 30000;




int a1[11] = {0, 1, 5, 16, 40, 61, 134, 214, 247, 743, 1112};
int a2[11] = {0, 1, 4, 9, 33, 55, 189, 322, 338, 437, 632};



int cal1(int i) {
    no sc[ll];
    int j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    int x,y,z,zz,zzz,zzzz;
    for(x=0;x<=i;x++){
        for(y=0;y<=i;y++){
            for(z=0;z<=i;z++){
                for(zz=0;zz<=i;zz++){
                    for(zzz=0;zzz<=i;zzz++){
                    for(zzzz=0;zzzz<=i;zzzz++){

                int temp = a1[x]+a1[y]+a1[z]+a1[zz]+a1[zzz]+a1[zzzz];
                if(sc[temp].state == 0)
                    sc[temp].state=1;
                }}}
            }
        }
    }

    int count=0;
    for(i=0;i<=ll;i++){
        if(sc[i].state == 1)count++;
        else if(sc[i].state ==0)break;
    }

    return count;

}

int cal2(int i) {
    no sc[ll];
    int j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    int x,y,z,zz,zzz,zzzz;
    for(x=0;x<=i;x++){
        for(y=0;y<=i;y++){
            for(z=0;z<=i;z++){
                for(zz=0;zz<=i;zz++){
                    for(zzz=0;zzz<=i;zzz++){
                    for(zzzz=0;zzzz<=i;zzzz++){

                int temp = a2[x]+a2[y]+a2[z]+a2[zz]+a2[zzz]+a2[zzzz];
                if(sc[temp].state == 0)
                    sc[temp].state=1;
                }}}
            }
        }
    }

    int count=0;
    for(i=0;i<=ll;i++){
        if(sc[i].state == 1)count++;
        else if(sc[i].state ==0)break;
    }

    return count;

}

int calculate(int i, int door) {
    if (door == 1)return cal1(i);
    else if (door == 2)return cal2(i);
}

int main() {

FILE *fp = fopen("X:\\azpod_choose6.out", "w");
    int decision[10];

    int i, j;

    for (i = 1; i <= 10; i++) {
        int res1 = calculate(i, 1);
        int res2 = calculate(i, 2);

        if (res1 >= res2)decision[i] = 1;
        else decision[i] = 2;
    }

    for (i = 1; i < 11; i++) {
        fprintf(fp, "6: ");

        if(decision[i]==1){
        for (j = 1; j <= i; j++) {
            if (j != (i))

                fprintf(fp, "%d, ", a1[j]);
            else
                fprintf(fp, "%d", a1[j]);
        }
        if (i != (10))fprintf(fp, ";\n");
        else fprintf(fp, "\n");
        }
        else if(decision[i]==2){
        for (j = 1; j <= i; j++) {
            if (j != (i))

                fprintf(fp, "%d, ", a2[j]);
            else
                fprintf(fp, "%d", a2[j]);
        }
        if (i != (10))fprintf(fp, ";\n");
        else fprintf(fp, "\n");
        }

    }

    for(i=0;i<10;i++){
        printf("%d",decision[i]);
    }
    fclose(fp);

    return 0;
}


