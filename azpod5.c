#include<stdio.h>
#include<math.h>
typedef struct {
    int val;
    int state;
} no;

FILE *fp;
no min_left[22000];
int result[35];
no scratch_list[22000 + 1];

int scratch_length;
int res_length;
int min_left_length;

int bins(int t, int left, int right) {
    int mid = (left + right) / 2;

    if (t == min_left[mid].val)return mid;
    else if (left > right)return -1;
    else if (t < min_left[mid].val)return bins(t, left, mid - 1);
    else return bins(t, mid + 1, right);

}

int isprime(int no){
    int i;
    int flag=0;
    for(i=2;i<=sqrt(no)+1;i++){
        if(no%i==0){
            flag=1;
            break;
        }
    }
    if(flag==0)return 1;
    else return 0;
}
void search(int t) {
    /* int i;
     for (i = 0; i < min_left_length; i++) {
         if (min_left[i].val == t)
             min_left[i].state = 1;
     }*/

    int index = bins(t, 0, min_left_length - 1);
    if (index != -1)min_left[index].state = 1;
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

dothework(int nor) {
    int ll = 22000;
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

    result[0] = 0;
    res_length++;

    result[1] = 1;
    res_length++;

    int j, k, z, l;
    int t;

    fprintf(fp, "1,");
    while (res_length < nor + 2) {
        printf("%d\n", res_length);

        scratch_list[0].state = 1;

        for (i = 0; i < res_length; i++) {
            for (j = 0; j < res_length; j++) {
                for (z = 0; z < res_length; z++) {
                    for (l = 0; l < res_length; l++) {
                        for (k = res_length - 1; k < res_length; k++) {
                            int tempp = result[i] + result[j] + result[z] + result[l] + result[k];

                            if (scratch_list[tempp].state == 0) {
                                scratch_list[tempp].state = 1;
                                if ((tempp) > scratch_length)
                                    scratch_length = (tempp);
                            }
                        }
                    }
                }
            }
        }

        for (t = 0; t < ll; t++) {
            min_left[t].state = 0;
        }

        min_left_length = 0;

        for (t = result[res_length - 1]; t <= ll; t++) {
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
            for (k = 0; k < ll; k++) {
                min_left[k].state = 0;
            }
            int myscore = 0;

            for (j = 0; j < res_length; j++) {
                for (k = j; k < res_length; k++) {
                    for (l = k; l < res_length; l++) {
                        for (z = l; z < res_length; z++) {
                            search(t + result[j] + result[k] + result[l] + result[z]);
                        }
                    }
                }
            }
            for (k = 0; k < res_length; k++) {
                for (l = k; l < res_length; l++) {
                    for (z = l; z < res_length; z++) {
                        search(t + t + result[k] + result[l] + result[z]);
                    }
                }
            }

            for (k = 0; k < res_length; k++) {
                for (z = k; z < res_length; z++) {
                    search((3 * t) + result[k] + result[z]);
                }
            }

            for (k = 0; k < res_length; k++) {

                search((4 * t) + result[k]);

            }

            search(5 * t);

            myscore = find();

            int myones;
             if(isprime(t)) myones=1;
            else
              myones = count_one();

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
        fprintf(fp, "%d,", index);
        fflush(fp);
    }

    /*
        int it;
        for (it = 1; it < res_length; it++) {
            printf("%d\n",it);
            if (it < (res_length - 1)) {
                fprintf(fp, "%d,", result[it]);
            } else {
                fprintf(fp, "%d", result[it]);
            }
        }
     */
}

int main() {
    fp = fopen("X:\\sod5_2.out", "w");
    printf("Enter the number of regions : ");

    dothework(20);

    fclose(fp);
    return 0;
}

