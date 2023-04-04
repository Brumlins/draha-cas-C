#include <stdio.h>

#define FILENAME "cisla.txt"
#define OUTPUTFILE "prevody.txt"


char *vypsani(){
    int d, c;
    float r;
    int pocetkol=0;
    int celkem;
    float prumer;
    char *vystup;
    FILE * fr = fopen(FILENAME, "r");
    if (fr==NULL){
        printf("File %s could not be successfully opened.\n", FILENAME);
    }else{
        printf("poradi         draha          cas   rychlost\n"
               "--------------------------------------------\n");
        while(fscanf(fr,"%d%d",&d,&c)==2){
            pocetkol++;
            celkem=celkem+d;
            r=(float)d/(float)c;
            printf("%6d.  %5d metru  %4d sekund  %5.2f m/s\n",pocetkol, d, c,r);
        }
        if (fclose(fr)==EOF){
            printf("File %s did not close properly.\n",FILENAME);
        }
        prumer=(float)celkem/(float)pocetkol;
        printf("\nPrumerna delka drahy je %.2f metru.\n", prumer);
        printf("\nZe souboru %s bylo precteno %d dvojic cisel.\n",FILENAME, pocetkol);
        printf("\nPress [Enter] to close the terminal ...\n");
    }
    return vystup;
}

char *vystup(){
    int pocetkol=0;
    int d, c;
    float r;
    int km;
    int minut;
    FILE * fr = fopen(FILENAME, "r");
    FILE * fw = fopen(OUTPUTFILE, "w");
    if (fr==NULL){
        printf("File %s could not be successfully opened.\n", FILENAME);
    }else{
        fprintf(fw,"poradi               draha                   cas   rychlost\n"
               "---------------------------------------------------------------\n");
        while(fscanf(fr,"%d%d",&d,&c)==2){
            r=(float)d/(float)c;
            if (r>10){
                pocetkol++;
                km=0;
                minut=0;
                while (d>1000){
                    km=km+1;
                    d=d-1000;
                }
                while (c>60){
                    minut=minut+1;
                    c=c-60;
                }
                r=r*3.6;
                fprintf(fw,"%6d.  %2d km %5d metru  %2d minut %4d sekund  %6.2f km/h\n",pocetkol,km, d,minut, c,r);
            }
        }
        if (fclose(fr)==EOF){
            printf("File %s did not close properly.\n",FILENAME);
        }
        fprintf(fw,"\nDo souboru %s bylo zapsano %d dvojic cisel.", OUTPUTFILE, pocetkol);
    }
    return vystup;
}



int main() {
    vypsani();
    vystup();
    while (getchar()!='\n'){
    }
    return 0;
}
