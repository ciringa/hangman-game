#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int letter_amount = 0,know_letters[],life=5;
char row[6];
int main();
int atualizar();
int ask(){
    printf("\ninforme uma letra\n");
    char out[1];
    int i = 0,the_char_is_true = 0;
    scanf("%s",out);
    for (i = 0; i <= letter_amount; i++)
    {
        if(out[0]==row[i]){
            //printf("a letra %c esta presente na palavra na posicao %d\n",out[0],i);
            know_letters[i]=1;
        }else{
            the_char_is_true++;
        }

    }
    //printf("%d",the_char_is_true);
    atualizar(the_char_is_true);
    return 0;

}
int atualizar(npm){
    system("cls");
    int i = 0,game_is_finish = 1;
    if (npm == letter_amount+1)
    {
        life--;
    }
    //basicamente a funçao step da rotina vai se repetir ate finalizar o jogo
    for ( i = 0; i < letter_amount; i++)
    {
         if(know_letters[i]==1){
            printf("%c",row[i]);
         }else{
            game_is_finish = 0;
            printf("_");
         }

    }

    printf("\n");

    //printf("word:%s, letter_amount: %d",row,letter_amount);
    for(i=0;i<life;i++){
        printf("<3 ");
    }
    printf("\n");
    //printf("vidas:%d",life);
    if(game_is_finish == 1 ){
        int menu  = 0;
        printf("voce ganhou  o jogo deseja jogar outra vez?\n 0 = nao \n 1 = sim \n");
        scanf("%d",&menu);
        switch (menu)
        {
            case 1:
                 main();
            break;
                
            default:
                return 0;
            break;
        }
    }else{
        if (life>0)
        {
            ask();
        }else{
            int menu  = 0;
            printf("voce perdeu deseja tentar outra vez?\n 0 = nao \n 1 = sim \n");
            scanf("%d",&menu);
            switch (menu)
            {
                case 1:
                    main();
                break;
                
                default:
                    return 0;
                break;
            }
        }
    }
        

}
int main(){
    int x = 0,i=0;
    //inicio de jogo
    printf("por favor informe a quantidade de caracteres da sua palavra \n");
    scanf("%d",&x);
    letter_amount = x;
    life = 5;
    know_letters[x];
    row[x];
    for ( i = 0; i < x; i++)
    {   //for feito pra zerar as letras conhecidas 
        know_letters[i]=0;
        row[i] = "=";
    }
    char text[x];
    printf("por favor digite sua palavra\n");
    scanf("%s",text);
    for ( i = 0; i <letter_amount ; i++)
    {   
        row[i]=text[i];
        //printf("%c",row[i]);
    }
    
    //jogar pra funcao rotina
    ask();
}