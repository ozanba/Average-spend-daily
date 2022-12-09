#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    int t;
    int spendTotal, spendDay;
    float spendAvg;

    int  dayK, dayN;

    t = time(NULL) % 31556926; /* number of seconds elapsed in a year */
    dayN = 1 + t/86400;
    // +1 beacuse we want calculate also this day.

    FILE * fpointer5 = fopen("spend.txt", "r");
    fscanf(fpointer5,"%d",&spendTotal);
    fclose(fpointer5);

    printf("Your total spend: %d",spendTotal);
    printf("\n");
    printf("enter your new spend: ");
    scanf("%d",&spendDay);
    printf("\n");
    spendTotal = spendTotal + spendDay;
    dayK = dayN - 260;
    //Ankaraya yılın 260. günü geldim.
    printf("dayN = %d\n",dayN);
   // printf("Ankaraya geleli kaç gün oldu  = %d\n",dayK);
    //printf("2. Anlaraya geli kaç gün oldu: %d\n",dayN-260);

    spendAvg = spendTotal / (dayK * 1.0);

    FILE * fpointer2 = fopen("spend.txt", "w");
    fprintf(fpointer2,"%d", spendTotal);
    fclose(fpointer2);

    printf("Total Spend = =%d\n", spendTotal);
    //printf("Bugünkü harcma = %d\n",spendDay);
    printf("Your average daily spend:  %.2f", spendAvg);

    return 0;
}
