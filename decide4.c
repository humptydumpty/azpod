#include<stdio.h>

typedef struct {
    int val;
    int state;
} no;

int ll = 30000;




int a1[31] = {0, 1, 4, 9, 15, 39, 65, 97, 105, 118, 168, 260, 320, 443, 460, 747, 917, 1150, 1408, 1586, 1748, 1883, 2442, 2741, 3005, 3576, 3958, 4833, 5164, 6055, 6388};
int a2[31] = {0, 1, 4, 9, 15, 39, 65, 97, 105, 118, 168, 260, 320, 404, 588, 708, 888, 1061, 1173, 1550, 1577, 2103, 2427, 2756, 3339, 3569, 3850, 4731, 5174, 5234, 6596};



int cal1(int i) {
    no sc[ll];
    int j;
    for (j = 0; j <= ll; j++) {
        sc[j].val = j;
        sc[j].state = 0;
    }

    int x,y,z,zz;
    for(x=0;x<=i;x++){
        for(y=0;y<=i;y++){
            for(z=0;z<=i;z++){
                for(zz=0;zz<=i;zz++){
                int temp = a1[x]+a1[y]+a1[z]+a1[zz];
                if(sc[temp].state == 0)
                    sc[temp].state=1;
                }
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

    int x,y,z,zz;
    for(x=0;x<=i;x++){
        for(y=0;y<=i;y++){
            for(z=0;z<=i;z++){
                for(zz=0;zz<=i;zz++){
                int temp = a2[x]+a2[y]+a2[z]+a2[zz];
                if(sc[temp].state == 0)
                    sc[temp].state=1;
                }
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

FILE *fp = fopen("X:\\azpod_choose4.out", "w");
    int decision[30];

    int i, j;

    for (i = 1; i <= 30; i++) {
        int res1 = calculate(i, 1);
        int res2 = calculate(i, 2);

        if (res1 >= res2)decision[i] = 1;
        else decision[i] = 2;
    }

    for (i = 1; i < 31; i++) {
        fprintf(fp, "4: ");

        if(decision[i]==1){
        for (j = 1; j <= i; j++) {
            if (j != (i))

                fprintf(fp, "%d, ", a1[j]);
            else
                fprintf(fp, "%d", a1[j]);
        }
        if (i != (30))fprintf(fp, ";\n");
        else fprintf(fp, "\n");
        }
        else if(decision[i]==2){
        for (j = 1; j <= i; j++) {
            if (j != (i))

                fprintf(fp, "%d, ", a2[j]);
            else
                fprintf(fp, "%d", a2[j]);
        }
        if (i != (30))fprintf(fp, ";\n");
        else fprintf(fp, "\n");
        }

    }

    for(i=0;i<30;i++){
        printf("%d",decision[i]);
    }
    fclose(fp);

    return 0;
}

