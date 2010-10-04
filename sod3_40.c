#include<stdio.h>

typedef struct {
    int val;
    int state;
} no;

FILE *fp;
no min_left[2000];
int result[45];
no scratch_list[2000+1];

int scratch_length;
int res_length;
int min_left_length;

void search(int t) {
    int i;
    for (i = 0; i < min_left_length; i++) {
        if (min_left[i].val == t)
            min_left[i].state = 1;
    }
}

int find() {
    int i = 0;

    while (min_left[i++].state == 1 && i < min_left_length);

    return (i - 1);

}

int count_one() {
    int i = 0;

    int count = 0;
    while (i < min_left_length) {
        if (min_left[i].state == 1) {
            count++;
        }
        i++;
    }

    return (count);
}

dothework(int nor){
    int ll=2000;
    //int nor;

    //int nod = 3;

    int i;

    scratch_length = 0;
    res_length = 0;
    min_left_length = 0;

    for (i = 0; i <= ll; i++) {
        scratch_list[i].val = i;
        scratch_list[i].state = 0;
    }
    FILE *fp3 = fopen("C:\\scr_back.out","r");
    for (i = 0; i <= 1985; i++) {
        fscanf(fp3,"%d",scratch_list[i].val);
        fscanf(fp3,"%d",scratch_list[i].state);
    }
    fclose(fp3);
    scratch_length=1985;


    result[0] = 0;
    res_length++;

    result[1] = 1;
    res_length++;

    FILE *fp4 = fopen("C:\\upto31.in","r");
    for (i = 1; i <= 31; i++) {
        fscanf(fp4,"%d",result[i]);
    }
    fclose(fp4);
    res_length=33;

    int j, k;
    int t;
    while (res_length < nor + 2) {

        for (i = 0; i < res_length; i++) {
            for (j = 0; j < res_length; j++) {
                for (k = 0; k < res_length; k++) {
                    if (scratch_list[result[i] + result[j] + result[k]].state == 0) {
                        scratch_list[result[i] + result[j] + result[k]].state = 1;
                        if ((result[i] + result[j] + result[k]) > scratch_length)
                            scratch_length = (result[i] + result[j] + result[k]);
                    }
                }
            }
        }

        for (t = 0; t < ll; t++) {
            min_left[t].state = 0;
        }

        min_left_length = 0;

        for (t = 1; t <= ll; t++) {
            if (scratch_list[t].state == 0) {
                min_left[min_left_length].val = scratch_list[t].val;
                min_left[min_left_length++].state = 0;
            }
        }


        int max = result[res_length - 1];
        int score = 0;
        int index = -1;
        int ones = -1;

        for (t = max + 1; t <= min_left[0].val; t++) {

            int k;
            for (k = 0; k < ll; k++)min_left[k].state = 0;
            int myscore = 0;
            for (j = 0; j < res_length; j++) {
                for (k = 0; k < res_length; k++) {
                    search(t + result[j] + result[k]);
                }
            }
            for (k = 0; k < res_length; k++) {
                search(t + t + result[k]);
            }
            search(3 * t);

            myscore = find();

            int myones = count_one();

            if (score < myscore) {
                score = myscore;
                index = t;
                ones = myones;
            } else if (myscore == score) {
                if (myones > ones) {
                    score = myscore;
                    index = t;
                    ones = myones;
                }
            }
        }


        result[res_length++] = index;


    }



    for (i = 1; i < res_length; i++) {
        printf("hello\n");
        if(i<(res_length-1))
        fprintf(fp, "%d,", result[i]);
        else
        fprintf(fp, "%d", result[i]);
    }

}


void print_scratch(){
    FILE *fp2=fopen("X:\\scr.out","w");
    int i;
    for(i=0;i<=scratch_length;i++){
        fprintf(fp2,"{%d,%d},",scratch_list[i].val,scratch_list[i].state);
    }
    fclose(fp2);
}


int main() {
    fp = fopen("X:\\sod3.out", "w");
    printf("Enter the number of regions : ");
    //scanf("%d", &nor);


        dothework(40);


    fclose(fp);

    print_scratch();
    return 0;
}
