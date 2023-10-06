#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int letter_amount = 5,know_letters[],life=5;
char row[6];

int main();
int atualizar();


int limpa(){
    int i = 0;
    system("cls");
    for ( i = 0; i < letter_amount; i++)
    {
        know_letters[i] = 0;
        row[i] = " ";
    }
    
}
int ai(){
    char char_word3[3][14] ={" ",
        "paz", "nao", "fel", "ceu", "ser", "vil", "sob", "mal", "mae", "ver", "ter", "ego", "bem", "mas"
         };
    char char_word5[5][14] ={" ",
        "sagaz", "amago", "negro", "exito", "termo", "mexer", "nobre", "nobre", "senso", "afeto", "algoz", "etica", "plena", "mutua"
    };
 
     int index = 0;
     srand(time(NULL));
     int select = rand()%14,i=0,choosed_value=0;
     printf("por favor escolha a dificuldade\n 1 - facil(3 letras por algum motivo quebrou)\n 2 - medio (5 letras)\n 3 - dificil(8 letras)\n");
     scanf("%d",&index);
     
     switch (index)
     {
     case 1:
         choosed_value = 3;
         //printf("%d",select);
         row[choosed_value];
         //printf("\n%s",char_word3[select]);
         for ( i = 0; i < choosed_value; i++)
         {
            row[i] = char_word3[select][i];
         }
         
     break;

     case 2:
         choosed_value = 5;
         //printf("%d",select);
         row[choosed_value];
         //printf("\n%s",char_word5[select]);
         for ( i = 0; i < choosed_value; i++)
         {
            row[i] = char_word5[select][i];
         }

         break;
     default:
        printf("como voce nao consegue seguir instruçoes simples encerraremos o jogo para voce");
        return 0 ;
        break;
     }
    letter_amount = choosed_value;
    //printf("%s",row);
    know_letters[choosed_value];



    ask();
}
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
        limpa();
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
            limpa();
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
    //system("clear");
    int x = 0,i=0,index = 0;
    
    //sistema de escolha de modo
    printf("________________game setup_______________\n");
    printf("por favor escolha o modo de jogo\n 1 - contra amigos (digite uma palavra)\n 2 - contra ia(ira gerar uma palavra aleatoria para pessoas solitarias)\n");
    scanf("%d",&index);
    life = 8;
    if(index==1){
        
        printf("por favor informe a quantidade de caracteres da sua palavra \n");
        scanf("%d",&x);
        letter_amount = x;
        know_letters[x];
        row[x];
        limpa();
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
    }else if (index == 2)
    {   
        limpa();
        ai();
    }
}

