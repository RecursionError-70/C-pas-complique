#include <stdio.h> 
#include <stdlib.h>

    char plan[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},      
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'} 
    };

    void plateau(){
        for(int i=0; i <8;i++){
            for(int j=0; j <8;j++){
                printf("%c", plan[i][j]);         
            }
            printf("\n");
        }
    }

    void jeu(){                                       

        char coup[9];
        while(1){
            printf("....\n");
            scanf("%6s", coup);

            char piece = coup[0];

            int x_dep = coup[1] - 'a';
            int y_dep = '8' - coup[2];                  
                                                        
            int x_arr = coup[4] - 'a';
            int y_arr = '8' - coup[5];

            if(x_dep < 0 || x_dep> 7 || y_dep < 0 || y_dep > 7 || x_arr < 0 || x_arr> 7 || y_arr < 0 || y_arr > 7){
                printf("coup invalide.\n");
                continue;
            }

            if(plan[y_dep][x_dep] != piece){
                printf("piece non trouve.\n");
                continue;
            }
            else{

                if (piece == 'p'){
                    char promotion;

                    if(y_arr == 0){
                        printf("promotion :\n");
                        scanf("%c",&promotion);
                        piece = promotion;
                    }

                    else if (x_arr == x_dep && (y_arr == y_dep + 1 || y_dep == 1 && y_arr == 3)){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }

                    else{
                        printf("deplacement invalide\n");
                        continue;
                    }
                }

                else if (piece == 'P'){
                    char promotion;

                    if(y_arr == 7){
                        printf("promotion :\n");
                        scanf("%c",&promotion);
                        piece = promotion;
                    }

                    else if (x_arr == x_dep && (y_arr == y_dep - 1 || y_dep == 6 && y_arr == 4)){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }

                    else{
                        printf("Coup invalide\n");
                        continue;
                    }
                }

                else if (piece == 'r'){
                    if ((x_arr == x_dep || y_arr == y_dep) && !(x_arr == x_dep && y_arr == y_dep)){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'R'){
                    if ((x_arr == x_dep || y_arr == y_dep) && !(x_arr == x_dep && y_arr == y_dep)){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'n'){
                    if ( ( (x_arr == x_dep + 2 || x_arr == x_dep - 2) && (y_arr == y_dep + 1 || y_arr == y_dep - 1)) || ((x_arr == x_dep + 1 || x_arr == x_dep - 1) && (y_arr == y_dep + 2 || y_arr == y_dep - 2)) ){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'N'){
                    if ( ( (x_arr == x_dep + 2 || x_arr == x_dep - 2) && (y_arr == y_dep + 1 || y_arr == y_dep - 1)) || ((x_arr == x_dep + 1 || x_arr == x_dep - 1) && (y_arr == y_dep + 2 || y_arr == y_dep - 2)) ){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'b'){
                    if (abs(x_dep - x_arr) == abs(y_dep - y_arr)){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'B'){
                    if (abs(x_dep - x_arr) == abs(y_dep - y_arr)){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'q'){
                    if (((x_arr == x_dep || y_arr == y_dep) && !(x_arr == x_dep && y_arr == y_dep)) || (abs(x_dep - x_arr) == abs(y_dep - y_arr))){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'Q'){
                    if (((x_arr == x_dep || y_arr == y_dep) && !(x_arr == x_dep && y_arr == y_dep)) || (abs(x_dep - x_arr) == abs(y_dep - y_arr))){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'k'){
                    if ( ((x_arr == x_dep + 1 || x_arr == x_dep - 1) && y_arr == y_dep) || (x_arr == x_dep && (y_arr == y_dep + 1 || y_arr == y_dep - 1)) || ((x_arr == x_dep + 1 || x_arr == x_dep - 1) && (y_arr == y_dep + 1 || y_arr == y_dep - 1)) ){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }

                else if (piece == 'K'){
                    if ( ((x_arr == x_dep + 1 || x_arr == x_dep - 1) && y_arr == y_dep) || (x_arr == x_dep && (y_arr == y_dep + 1 || y_arr == y_dep - 1)) || ((x_arr == x_dep + 1 || x_arr == x_dep - 1) && (y_arr == y_dep + 1 || y_arr == y_dep - 1)) ){
                        plan[y_arr][x_arr] = piece;
                        plan[y_dep][x_dep] = '.';
                    }
                    else{
                        printf("deplacement invalide\n");
                    }
                }
            }

            plateau();
        }
    }

    int main(){
        jeu();
        return 0;
    }

