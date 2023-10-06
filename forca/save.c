#include <stdlib.h>
#include <stdio.h>


int letter_amount = 0,know_letters[];
int main(){
    int x = 0,i=0;
    printf("por favor informe a quantidade de caracteres da sua palavra \n");
    scanf("%d",&x);
    letter_amount = x;
    for ( i = 0; i < x; i++)
    {
        know_letters[i]=0;
    }
    
    char text[x],out[1];
    printf("por favor digite sua palavra\n");
    scanf("%s",text);
    printf("informe uma letra(sua palavra possui %d letras) \n",x);
     
    scanf("%s",out);

    for (i = 0; i < letter_amount; i++)
    {
        if(out[0]==text[i]){
            printf("a letra %c esta presente na palavra na posicao %d\n",out[0],i);
            know_letters[i]=1;
        }

     
    }
    for ( i = 0; i < letter_amount; i++)
    {
         if(know_letters[i]==1){
            printf("%c",text[i]);
         }else{
            printf("_");
         }
    }
}