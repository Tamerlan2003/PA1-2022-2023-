#include "stdio.h"

int main(){
    int length;
    int width;
    printf("Zadejte pocet poli:\n");
    if(scanf(" %d", &length)!=1 || (length < 1)){
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Zadejte velikost pole:\n");
    if(scanf(" %d", &width)!=1 || (width < 1)){
        printf("Nespravny vstup.\n");
        return 1;
    }

    // Печать верхней строки
    int i;
    i = length * width;
    printf("+");
    for(int j = 0; j < i; ++j)
    {
        printf("-");
    }
    printf("+\n");


    for (int i = 0; i< length; ++i){
        if(i%2==0){
            for(int k =0; k < width; ++k)
            {
                printf("|");
                for( int m = 1; m<=length; ++m)
                {
                    if(m%2 == 1){
                        for(int l=0; l< width; ++l)
                        {
                            printf(" ");
                        }
                    } else if(m%2 == 0){
                        for(int r = 0; r<width; ++r){
                            printf("X");
                        }
                    }
                    ;
                }
                printf("|");
                printf("\n");
            }
        } else if(i%2==1){
            for(int k = 0; k< width; ++k){
                printf("|");
                for(int m = 1; m <=length; ++m)
                {
                    if(m%2==1){
                        for(int l=0; l<width; ++l)
                        {
                            printf("X");
                        }
                    } else if (m%2==0){
                        for(int r =0; r <width; ++r){
                            printf(" ");
                        }
                    }

                }
                printf("|");
                printf("\n");
            }
        }
    }
    printf("+");
    for(int j = 0; j < i; ++j)
    {
        printf("-");
    }
    printf("+\n");
}
