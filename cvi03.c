#include <stdio.h>

int main() {
    int HourOne = 0, HourTwo = 0, MinuteOne = 0, MinuteTwo = 0;
    int SekundOne =0, SekundTwo =0, mSekOne =0, mSekTwo =0;

    printf("Zadejte cas t1:\n");
    if (scanf(" %d : %d : %d , %d", &HourOne, &MinuteOne, &SekundOne, &mSekOne) != 4 || (HourOne >= 24) ||
        (MinuteOne >= 60) || (SekundOne >= 60) || (mSekOne >= 1000)) {
        printf("Nespravny vstup.\n");
        return 1;
    }
    printf("Zadejte cas t2:\n");
    if (scanf(" %d : %d : %d , %d", &HourTwo, &MinuteTwo, &SekundTwo, &mSekTwo) != 4 || (HourTwo >= 24) ||
        (MinuteTwo >= 60) || (SekundTwo >= 60) || (mSekTwo >= 1000)) {
        printf("Nespravny vstup.\n");
        return 1;
    }

    if (HourTwo == HourOne) {
        if (MinuteTwo == MinuteOne) {
            if (SekundOne == SekundTwo) {
                if (mSekOne > mSekTwo) {
                    printf("Nespravny vstup.\n");
                    return 1;
                }
            } else if (SekundOne > SekundTwo){
                printf("Nespravny vstup.\n");
                return 1;
            }

        } else if (MinuteTwo < MinuteOne) {
            printf("Nespravny vstup.\n");
            return 1;
        }
        else if(HourTwo < HourOne){
            printf("Nespravny vstup.\n");
            return 1;
        }
    }

    int firstconvertedtime ,secondconvertedtime;
    firstconvertedtime = (HourOne * 3600000) + (MinuteOne * 60000) + (SekundOne * 1000) + mSekOne;
    secondconvertedtime = (HourTwo * 3600000) + (MinuteTwo * 60000) + (SekundTwo * 1000) + mSekTwo;

    int delTime = 0;
    delTime = secondconvertedtime - firstconvertedtime;

    int hour = 0;
    int minute = 0;
    int Sekunda =0;
    int mSek = 0;
    while (delTime>= 3600000)
    {
        hour = delTime/3600000;
        delTime = delTime - (hour*3600000);
    }
    while (delTime >= 60000)
    {
        minute = delTime/60000;
        delTime = delTime - (minute*60000);
    }
    while (delTime >= 1000){
        Sekunda = delTime/1000;
        delTime = delTime - (Sekunda*1000);
    }
    if(delTime < 1000){
        mSek = delTime;
    }

    printf("Doba:%2d:%02d:%02d,%03d", hour,minute,Sekunda,mSek);
    return 0;
}
