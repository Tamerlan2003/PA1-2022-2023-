#include "stdio.h"
#include "math.h"
#define DBL_EPSILON __DBL_EPSILON__
int main(){
    double bod_A_X,bod_B_X,bod_C_X;
    double bod_A_Y,bod_B_Y,bod_C_Y;


    printf("Bod A:\n");
    if(scanf(" %lf %lf", &bod_A_X, &bod_A_Y )!=2){
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Bod B:\n");
    if(scanf(" %lf %lf", &bod_B_X, &bod_B_Y )!=2){
        printf("Nespravny vstup.\n");
        return 1;
    }

    printf("Bod C:\n");
    if(scanf(" %lf %lf", &bod_C_X, &bod_C_Y )!=2){
        printf("Nespravny vstup.\n");
        return 1;
    }


    int check = 0;
    double math3 = (bod_C_X - bod_A_X)*(bod_B_Y - bod_A_Y) - (bod_C_Y - bod_A_Y) * (bod_B_X - bod_A_X);
    double math = ((bod_C_X - bod_A_X)*(bod_B_Y - bod_A_Y));
    double math2 = ((bod_C_Y - bod_A_Y) * (bod_B_X - bod_A_X));

    double cheto = fabs( math - math2);

    math = fabs(math);
    math2 = fabs(math2);

    double scaledEpsilon = DBL_EPSILON * (fmax(math, math2)*1000);


    if ((bod_A_X == bod_B_X && bod_A_Y == bod_B_Y) || ((bod_A_X == bod_C_X) && (bod_A_Y == bod_C_Y)) || ((bod_B_X == bod_C_X) && (bod_B_Y == bod_C_Y))){
        printf("Nektere body splyvaji.\n");
        return 1;
    }
    else if (cheto <= scaledEpsilon)
    {
        printf("Body lezi na jedne primce.\n");

        if(((bod_A_X >= bod_B_X) && (bod_C_X >= bod_A_X) && (bod_A_Y >= bod_B_Y) && (bod_C_Y >= bod_A_Y)) || ((bod_A_X >= bod_C_X) && (bod_B_X >= bod_A_X ) && (bod_A_Y >= bod_C_Y) && (bod_B_Y >= bod_A_Y ))){
            printf("Prostredni je bod A.\n");
            return 1;
        } else if (((bod_B_X >= bod_A_X) && (bod_B_X <= bod_C_X)  && (bod_B_Y >= bod_A_Y)&& (bod_B_Y <= bod_C_Y))|| ((bod_B_X >= bod_C_X) && (bod_B_X <= bod_A_X) && (bod_B_Y >= bod_C_Y) && (bod_B_Y <= bod_A_Y))) {
            printf("Prostredni je bod B.\n");
            return 1;
        } else {
            printf("Prostredni je bod C.\n");
            return 1;
        }

    }
    else if (math3 != check){
        printf("Body nelezi na jedne primce.\n");
    }

}