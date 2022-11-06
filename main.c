#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#define MAX 64

int o=0;   //index to help in undo and redo the board
char ARR[10000][8][8];    //3D array to store the boards (arrays 2D) in it
char EATEN[10000][16],eaten[10000][16];  //2 arrays which are 2D to store the 2 arrays which are 1D of the pieces taken out from both players
int E=-1,e=-1;  //2 indeces to help in undo and redo the taken out pieces
//function to display the chess board
char board(char arr[8][8]){
    int i,j;
    char s;
    printf("\n\t\t[chess in C]\n");
    printf("   ");
    for(s='A';s<'I';s++){
        printf("%c   ",s);    //from A to H above
    }
    printf("\n-----------------------------------\n");
//print the components of chess with '-' for white squares & '.' for black squares
int h = 8;
int f = 8;
    for(i=0;i<8;i++){
        printf("%d  ",h--);    //from 1 to 8 right
        for(j=0;j<8;j++){
                if(i%2==0){
                        if(j%2==0){
                            printf("%c-| ",ARR[o][i][j]);
                        }
                        else{
                            printf("%c.| ",ARR[o][i][j]);
                        }
                }
                else{
                    if(j%2==0){
                        printf("%c.| ",ARR[o][i][j]);
                    }
                    else{
                        printf("%c-| ",ARR[o][i][j]);
                    }
                }
        }
        printf("%d  ",f--);   //from 1 to 8 left
        printf("\n-----------------------------------\n");
    }
    printf("   ");
    for(s='A';s<'I';s++){
        printf("%c   ",s);    //from A to H below
    }
    printf("     ");
}
//function to convert the char index scanned to an integer index of the current array
int convert_char(char x1){
    int X1;
    if(x1=='A'){
        X1=0;
    }
    else if(x1=='B'){
        X1=1;
    }
    else if(x1=='C'){
        X1=2;
    }
    else if(x1=='D'){
        X1=3;
    }
    else if(x1=='E'){
        X1=4;
    }
    else if(x1=='F'){
        X1=5;
    }
    else if(x1=='G'){
        X1=6;
    }
    else if(x1=='H'){
        X1=7;
    }
return X1;
}
//function to convert the integer index scanned to an integer index of the current array
int convert_int(int y1){
    int Y1;
    if(y1==8){
        Y1=0;
    }
    else if(y1==7){
        Y1=1;
    }
    else if(y1==6){
        Y1=2;
    }
    else if(y1==5){
        Y1=3;
    }
    else if(y1==4){
        Y1=4;
    }
    else if(y1==3){
        Y1=5;
    }
    else if(y1==2){
        Y1=6;
    }
    else if(y1==1){
        Y1=7;
    }
return Y1;
}
//function to convert the first integer index of the current array to the integer index displayed
int convert_ArrayInt(int Y1){
    int y1;
    if(Y1==0){
        y1=8;
    }
    else if(Y1==1){
        y1=7;
    }
    else if(Y1==2){
        y1=6;
    }
    else if(Y1==3){
        y1=5;
    }
    else if(Y1==4){
        y1=4;
    }
    else if(Y1==5){
        y1=3;
    }
    else if(Y1==6){
        y1=2;
    }
    else if(Y1==7){
        y1=1;
    }
    return y1;
}
//function to convert the second integer index of the current array to the char index displayed
char convert_ArrayChar(int X1){
    char x1;
    if(X1==0){
        x1='A';
    }
    else if(X1==1){
        x1='B';
    }
    else if(X1==2){
        x1='C';
    }
    else if(X1==3){
        x1='D';
    }
    else if(X1==4){
        x1='E';
    }
    else if(X1==5){
        x1='F';
    }
    else if(X1==6){
        x1='G';
    }
    else if(X1==7){
        x1='H';
    }
    return x1;
}
//function to execute the movement
int TAKEN=0,taken=0;
char T[16],t[16];
void move(int Y1,int X1,int Y2,int X2,char arr[8][8]){
    int temp;
    if(arr[Y2][X2]==' '){
    arr[Y2][X2]=arr[Y1][X1];
    arr[Y1][X1]=' ';
    o++;
    e++;
    E++;
//store the 2D array in the 3D one
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        ARR[o][i][j]=arr[i][j];
    }
}
    board(arr);
    }
    else if(islower(arr[Y2][X2])){
        t[taken]=arr[Y2][X2];
        arr[Y2][X2]=arr[Y1][X1];
        arr[Y1][X1]=' ';
        o++;
        e++;
        E++;
//store the 2D array in the 3D one
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        ARR[o][i][j]=arr[i][j];
    }
}
        board(arr);
        taken++;
    }
    else if(isupper(arr[Y2][X2])){
        T[TAKEN]=arr[Y2][X2];
        arr[Y2][X2]=arr[Y1][X1];
        arr[Y1][X1]=' ';
        o++;
        e++;
        E++;
//store the 2D array in the 3D one
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        ARR[o][i][j]=arr[i][j];
    }
}
        board(arr);
        TAKEN++;
    }
//store the 1D arrays in the 2D ones
for(int i=0;i<taken;i++){
        eaten[e][i]=t[i];
}
for(int j=0;j<TAKEN;j++){
    EATEN[E][j]=T[j];
}

    printf("the pieces taken out from WHITE player: ");
    for(int i=0;i<taken;i++){
        printf("%c ",eaten[e][i]);}
    printf("\n");
    printf("\t\t\t\t\tthe pieces taken out from BLACK player: ");
    for(int j=0;j<TAKEN;j++){
        printf("%c ",EATEN[E][j]);}
    printf("\n");
}
char temp;
void Do_move(char arr[8][8],int Y1,int X1,int Y2,int X2){
    temp = arr[Y2][X2];
    arr[Y2][X2] = arr[Y1][X1];
    arr[Y1][X1] = ' ';
}
void DO_not_move(char arr[8][8],int Y1,int X1,int Y2,int X2){
    arr[Y1][X1] = arr[Y2][X2];
    arr[Y2][X2] = temp;
}
//function to check if the indices are inside the current array
int inBoard(int i,int j){
        if(i>=0&&i<8 && j>=0&&j<8){return 1;}
        else{return 0;}
    }
//function to check if the king is checked by the other king
int lookFor_k(char arr[8][8],char c, int i,int j){
  int x[] = {-1, -1, -1, 0,0, 1, 1, 1};
  int y[] = {-1, 0, 1, -1,1, -1, 0, 1};
  for (int k = 0; k < 8; k++){
    int m = i + x[k];
    int n = j + y[k];
    if (inBoard(m,n)&&arr[m][n] == c){return 1;}
  }
  return 0;
}
//function to check if the king is checked by a bishop
int lookFor_b(char arr[8][8],char c, int i,int j){
  int k = 1;
 while (inBoard(i + k, j + k)){   //if there is a bishop in the lower right
    if (arr[i + k][j + k] == c){return 1;}
    if (arr[i + k][j + k] != ' '){break;}
       k++;
 }
  k = 1;
  while (inBoard(i + k, j - k)){   //if there is a bishop in the lower left
    if (arr[i + k][j - k] == c){return 1;}
    if (arr[i + k][j - k] != ' '){break;}
       k++;
 }
  k = 1;
  while (inBoard(i - k, j + k)){   //if there is a bishop in the upper right
    if (arr[i - k][j + k] == c){return 1;}
    if (arr[i - k][j + k] != ' '){break;}
       k++;
  }
  k = 1;
  while (inBoard(i - k, j - k)){   //if there is a bishop in the upper left
    if (arr[i - k][j - k] == c){return 1;}
    if (arr[i - k][j - k] != ' '){break;}
       k++;
  }
  return 0;
}
//function to check if the king is checked by a rook
int lookFor_r(char arr[8][8],char c, int i,int j){
  int k = 1;
  while (inBoard(i + k, j)){   //if there is a rook down
    if (arr[i + k][j] == c){return 1;}
    if (arr[i + k][j] != ' '){break;}
       k++;
  }
  k = 1;
  while (inBoard(i - k, j)){   //if there is a rook up
    if (arr[i - k][j] == c){return 1;}
    if (arr[i - k][j] != ' '){break;}
       k++;
  }
  k = 1;
  while (inBoard(i, j + k)){   //if there is a rook right
    if (arr[i][j + k] == c){return 1;}
    if (arr[i][j + k] != ' '){break;}
       k++;
  }
  k = 1;
  while (inBoard(i, j - k)){   //if there is a rook left
    if (arr[i][j - k] == c){return 1;}
    if (arr[i][j - k] != ' '){break;}
       k++;
  }
  return 0;
}
//function to check if the king is checked by a queen
int lookFor_q(char arr[8][8],char c, int i,int j){
  if (lookFor_b(arr, c, i, j)||lookFor_r(arr, c, i, j)){return 1;}
  return 0;
}
//function to check if the king is checked by a night
int lookFor_n(char arr[8][8],char c, int i,int j){
  int x[] = {2, 2, -2, -2,1, 1, -1, -1};
  int y[] = {1, -1, 1, -1,2, -2, 2, -2};
  for (int k = 0; k < 8; k++){
    int m = i + x[k];
    int n = j + y[k];
    if (inBoard(m, n) && arr[m][n] == c){return 1;}
  }
  return 0;
}
//function to check if the king is checked by a pawn
int lookFor_p(char arr[8][8],char c, int i,int j){
  char lookFor;
  if(isupper(c)){
    lookFor = 'P';
    if(inBoard(i - 1, j - 1) && arr[i - 1][j - 1] == lookFor){return 1;}  //upper left
    if(inBoard(i - 1, j + 1) && arr[i - 1][j + 1] == lookFor){return 1;}  //upper right
  }
  else{
    lookFor = 'p';
    if (inBoard(i + 1, j - 1) &&arr[i + 1][j - 1] == lookFor){return 1;}  //lower left
    if (inBoard(i + 1, j + 1) &&arr[i + 1][j + 1] == lookFor){return 1;}  //lower right
  }
  return 0;
}
//function to check if the white king is checked in its current position by entering its indices
int checkBoard_forWhiteKing(char arr[8][8],int i,int j){
                if (lookFor_n(arr,'N', i, j)){return 1;}
                if (lookFor_p(arr,'P', i, j)){return 1;}
                if (lookFor_r(arr,'R', i, j)){return 1;}
                if (lookFor_b(arr,'B', i, j)){return 1;}
                if (lookFor_q(arr,'Q', i, j)){return 1;}
                if (lookFor_k(arr,'K', i, j)){return 1;}
  return 0;
}
//function to check if the black king is checked in its current position by entering its indices
int checkBoard_forBlackKing(char arr[8][8],int i,int j){
                if (lookFor_n(arr,'n', i, j)){return 1;}
                if (lookFor_p(arr,'p', i, j)){return 1;}
                if (lookFor_r(arr,'r', i, j)){return 1;}
                if (lookFor_b(arr,'b', i, j)){return 1;}
                if (lookFor_q(arr,'q', i, j)){return 1;}
                if (lookFor_k(arr,'k', i, j)){return 1;}
  return 0;
}
//function to check if the black king is in check position without entering its indices
int CHECK(char arr[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='K'){
                if(checkBoard_forBlackKing(arr,i,j)){return 1;}}}}
        return 0;}
//function to check if the white king is in check position without entering its indices
int check(char arr[8][8]){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='k'){
                if(checkBoard_forWhiteKing(arr,i,j)){return 1;}}}}
        return 0;}
//function for dead position
int Dead_position(char arr[8][8]){
    int K=0,k=0,b=0,n=0,B=0,N=0,m=0,wt=0,bk=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='K'){K++;}
            else if(arr[i][j]=='k'){k++;}
            else if(arr[i][j]=='b'){
                b++;
                if(i%2==0){
                        if(j%2==0){
                            wt++;}
                        else{
                            bk++;}}
                else{
                    if(j%2==0){
                        bk++;}
                    else{
                        wt++;}}
            }
            else if(arr[i][j]=='n'){n++;}
            else if(arr[i][j]=='B'){
                B++;
                if(i%2==0){
                        if(j%2==0){
                            wt++;}
                        else{
                            bk++;}}
                else{
                    if(j%2==0){
                        bk++;}
                    else{
                        wt++;}}
            }
            else if(arr[i][j]=='N'){N++;}
            else if(arr[i][j]=='P'||arr[i][j]=='p'||arr[i][j]=='Q'||arr[i][j]=='q'||arr[i][j]=='R'||arr[i][j]=='r'){m++;}
        }
    }
    if(m==0){
    if(K==1&&k==1&&b==0&&n==0&&B==0&&N==0){return 1;}
    else if(K==1&&k==1&&((B==1&&b==0&&N==0&&n==0) || (B==0&&b==1&&N==0&&n==0))){return 1;}
    else if(K==1&&k==1&&((N==1&&n==0&&B==0&&b==0) || (N==0&&n==1&&B==0&&b==0))){return 1;}
    else if(K==1&&k==1&&((N==2&&n==0&&B==0&&b==0) || (N==0&&n==2&&B==0&&b==0))){return 1;}
    else if(K==1&&k==1&&N==0&&n==0&&B==1&&b==1 && (wt==2||bk==2)){return 1;}
    }
return 0;
}
//functions to check if the pieces can move any more or not
int ROOK_cannot_move(char arr[8][8],char c){
    int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]==c){
                for(int a=1;i-a>-1;a++){   //ROOK can move up
                    if(!isupper(arr[i-a][j])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i-a;
                        int X2=j;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i-a][j]!=' '){break;}
                }
                for(int a=1;i+a<8;a++){   //ROOK can move down
                    if(!isupper(arr[i+a][j])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i+a;
                        int X2=j;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i+a][j]!=' '){break;}
                }
                for(int a=1;j+a<8;a++){   //ROOK can move right
                    if(!isupper(arr[i][j+a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i;
                        int X2=j+a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i][j+a]!=' '){break;}
                }
                for(int a=1;j-a>-1;a++){   //ROOK can move left
                    if(!isupper(arr[i][j-a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i;
                        int X2=j-a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i][j-a]!=' '){break;}
                }
            }
        }
    }
    if(s==h){return 1;} //all the valid movements for ROOK lead to check for the black king
return 0;
}
int rook_cannot_move(char arr[8][8],char c){
    int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]==c){
                for(int a=1;i-a>-1;a++){   //rook can move up
                    if(!islower(arr[i-a][j])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i-a;
                        int X2=j;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i-a][j]!=' '){break;}
                }
                for(int a=1;i+a<8;a++){   //rook can move down
                    if(!islower(arr[i+a][j])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i+a;
                        int X2=j;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i+a][j]!=' '){break;}
                }
                for(int a=1;j+a<8;a++){   //rook can move right
                    if(!islower(arr[i][j+a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i;
                        int X2=j+a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i][j+a]!=' '){break;}
                }
                for(int a=1;j-a>-1;a++){   //rook can move left
                    if(!islower(arr[i][j-a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i;
                        int X2=j-a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i][j-a]!=' '){break;}
                }
            }
        }
    }
    if(s==h){return 1;} //if all the valid movements for rook lead to check for the white king
return 0;
}
int NIGHT_cannot_move(char arr[8][8]){
int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='N'){
                int y[]={2,2,-2,-2,1,1,-1,-1};
                int x[]={1,-1,1,-1,2,-2,2,-2};
                for(int a=0;a<8;a++){
                    int Y2=i+y[a];
                    int X2=j+x[a];
                    if(inBoard(Y2,X2)&&!isupper(arr[Y2][X2])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                }
            }
        }
    }
    if(s==h){return 1;}
return 0;
}
int night_cannot_move(char arr[8][8]){
int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='n'){
                int y[]={2,2,-2,-2,1,1,-1,-1};
                int x[]={1,-1,1,-1,2,-2,2,-2};
                for(int a=0;a<8;a++){
                    int Y2=i+y[a];
                    int X2=j+x[a];
                    if(inBoard(Y2,X2)&&!islower(arr[Y2][X2])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                }
            }
        }
    }
    if(s==h){return 1;}
return 0;
}
int BISHOP_cannot_move(char arr[8][8],char c){
int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]==c){
                for(int a=1;i-a>-1&&j+a<8;a++){   //BISHOP can move upper right
                    if(!isupper(arr[i-a][j+a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i-a;
                        int X2=j+a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i-a][j+a]!=' '){break;}
                }
                for(int a=1;i-a>-1&&j-a>-1;a++){   //BISHOP can move upper left
                    if(!isupper(arr[i-a][j-a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i-a;
                        int X2=j-a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i-a][j-a]!=' '){break;}
                }
                for(int a=1;i+a<8&&j+a<8;a++){   //BISHOP can move lower right
                    if(!isupper(arr[i+a][j+a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i+a;
                        int X2=j+a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i+a][j+a]!=' '){break;}
                }
                for(int a=1;i+a<8&&j-a>-1;a++){   //BISHOP can move lower left
                    if(!isupper(arr[i+a][j-a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i+a;
                        int X2=j-a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i+a][j-a]!=' '){break;}
                }
            }
        }
    }
    if(s==h){return 1;} //if all the valid movements for BISHOP lead to check for the black king
return 0;
}
int bishop_cannot_move(char arr[8][8],char c){
int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]==c){
                for(int a=1;i-a>-1&&j+a<8;a++){   //bishop can move upper right
                    if(!islower(arr[i-a][j+a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i-a;
                        int X2=j+a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i-a][j+a]!=' '){break;}
                }
                for(int a=1;i-a>-1&&j-a>-1;a++){   //BISHOP can move upper left
                    if(!islower(arr[i-a][j-a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i-a;
                        int X2=j-a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i-a][j-a]!=' '){break;}
                }
                for(int a=1;i+a<8&&j+a<8;a++){   //BISHOP can move lower right
                    if(!islower(arr[i+a][j+a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i+a;
                        int X2=j+a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i+a][j+a]!=' '){break;}
                }
                for(int a=1;i+a<8&&j-a>-1;a++){   //BISHOP can move lower left
                    if(!islower(arr[i+a][j-a])){
                        s++;
                        int Y1=i;
                        int X1=j;
                        int Y2=i+a;
                        int X2=j-a;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            DO_not_move(arr,Y1,X1,Y2,X2);
                            h++;
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                    if(arr[i+a][j-a]!=' '){break;}
                }
            }
        }
    }
    if(s==h){return 1;} //if all the valid movements for bishop lead to check for the white king
return 0;
}
int QUEEN_cannot_move(char arr[8][8]){
    if(ROOK_cannot_move(arr,'Q')&&BISHOP_cannot_move(arr,'Q')){return 1;}
    return 0;
}
int queen_cannot_move(char arr[8][8]){
    if(rook_cannot_move(arr,'q')&&bishop_cannot_move(arr,'q')){return 1;}
    return 0;
}
int KING_cannot_move(char arr[8][8]){
    int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='K'){
                int y[]={-1,1,0,0};
                int x[]={0,0,1,-1};
                for(int a=0;a<4;a++){
                    int Y1=i;
                    int X1=j;
                    int Y2=i+y[a];
                    int X2=j+x[a];
                    if(inBoard(Y2,X2)&&!isupper(arr[Y2][X2])){
                        s++;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(CHECK(arr)){
                            h++;
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                }
            }
        }
    }
    if(s==h){return 1;}
return 0;
}
int king_cannot_move(char arr[8][8]){
    int s=0,h=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]=='k'){
               int y[]={-1,1,0,0};
               int x[]={0,0,1,-1};
                for(int a=0;a<4;a++){
                    int Y1=i;
                    int X1=j;
                    int Y2=i+y[a];
                    int X2=j+x[a];
                    if(inBoard(Y2,X2)&&!islower(arr[Y2][X2])){
                        s++;
                        Do_move(arr,Y1,X1,Y2,X2);
                        if(check(arr)){
                            h++;
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                        else{
                            DO_not_move(arr,Y1,X1,Y2,X2);
                        }
                    }
                }
            }
        }
    }
    if(s==h){return 1;}
return 0;
}
int PAWN_cannot_move(char arr[8][8]){
int s=0,h=0;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(arr[i][j]=='P'){
            if(inBoard(i+1,j)&&arr[i+1][j]==' '){
                s++;
                Do_move(arr,i,j,i+1,j);
                if(CHECK(arr)){
                    h++;
                    DO_not_move(arr,i,j,i+1,j);
                }
                else{
                    DO_not_move(arr,i,j,i+1,j);
                }
            }
            if(inBoard(i+1,j+1)&&islower(arr[i+1][j+1])){
                s++;
                Do_move(arr,i,j,i+1,j+1);
                if(CHECK(arr)){
                    h++;
                    DO_not_move(arr,i,j,i+1,j+1);
                }
                else{
                    DO_not_move(arr,i,j,i+1,j+1);
                }
            }
            if(inBoard(i+1,j-1)&&islower(arr[i+1][j-1])){
                s++;
                Do_move(arr,i,j,i+1,j-1);
                if(CHECK(arr)){
                    h++;
                    DO_not_move(arr,i,j,i+1,j-1);
                }
                else{
                    DO_not_move(arr,i,j,i+1,j-1);
                }
            }
        }
    }
}
if(s==h){return 1;}
return 0;
}
int pawn_cannot_move(char arr[8][8]){
int s=0,h=0;
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(arr[i][j]=='p'){
            if(inBoard(i-1,j)&&arr[i-1][j]==' '){
                s++;
                Do_move(arr,i,j,i-1,j);
                if(check(arr)){
                    h++;
                    DO_not_move(arr,i,j,i-1,j);
                }
                else{
                    DO_not_move(arr,i,j,i-1,j);
                }
            }
            if(inBoard(i-1,j+1)&&isupper(arr[i+1][j+1])){
                s++;
                Do_move(arr,i,j,i-1,j+1);
                if(check(arr)){
                    h++;
                    DO_not_move(arr,i,j,i-1,j+1);
                }
                else{
                    DO_not_move(arr,i,j,i-1,j+1);
                }
            }
            if(inBoard(i-1,j-1)&&isupper(arr[i-1][j-1])){
                s++;
                Do_move(arr,i,j,i-1,j-1);
                if(check(arr)){
                    h++;
                    DO_not_move(arr,i,j,i-1,j-1);
                }
                else{
                    DO_not_move(arr,i,j,i-1,j-1);
                }
            }
        }
    }
}
if(s==h){return 1;}
return 0;
}
//functions for checkmate
int CHECK_MATE(char arr[8][8]){
    if(CHECK(arr)){
        if(ROOK_cannot_move(arr,'R')&&BISHOP_cannot_move(arr,'B')&&NIGHT_cannot_move(arr)&&QUEEN_cannot_move(arr)&&KING_cannot_move(arr)){
            return 1;
        }
    }
    return 0;
}
int check_mate(char arr[8][8]){
    if(check(arr)){
        if(rook_cannot_move(arr,'r')&&bishop_cannot_move(arr,'b')&&night_cannot_move(arr)&&queen_cannot_move(arr)&&king_cannot_move(arr)){
            return 1;
        }
    }
    return 0;
}
//functions for stalemate
int STALE_MATE(char arr[8][8]){
    if(CHECK(arr)!=1){
        if(ROOK_cannot_move(arr,'R')&&BISHOP_cannot_move(arr,'B')&&NIGHT_cannot_move(arr)&&QUEEN_cannot_move(arr)&&KING_cannot_move(arr)){
            return 1;
        }
    }
    return 0;
}
int stale_mate(char arr[8][8]){
    if(check(arr)!=1){
        if(rook_cannot_move(arr,'r')&&bishop_cannot_move(arr,'b')&&night_cannot_move(arr)&&queen_cannot_move(arr)&&king_cannot_move(arr)){
            return 1;
        }
    }
    return 0;
}

//function for ROOK
void ROOK(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct ROOK{
    char x1;
    int y1;
    };
    struct ROOK arr_R[MAX];
    char x1;
    int y1,j=0;
    for(int i=1;i<X1+1;i++){  //the rook can move to the left any number of squares
        if(!isupper(arr[Y1][X1-i])){
            x1=convert_ArrayChar(X1-i);
            y1=convert_ArrayInt(Y1);
            arr_R[j].x1=x1;
            arr_R[j].y1=y1;
            j++;
        }
        if(islower(arr[Y1][X1-i])){break;}
    }
    for(int i=1;i<8-X1;i++){  //the rook can move to the right any number of squares
        if(!isupper(arr[Y1][X1+i])){
            x1=convert_ArrayChar(X1+i);
            y1=convert_ArrayInt(Y1);
            arr_R[j].x1=x1;
            arr_R[j].y1=y1;
            j++;
        }
        if(islower(arr[Y1][X1+i])){break;}
    }
    for(int i=1;i<Y1+1;i++){
        if(!isupper(arr[Y1-i][X1])){    //the rook can move up any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1-i);
            arr_R[j].x1=x1;
            arr_R[j].y1=y1;
            j++;
        }
        if(islower(arr[Y1-i][X1])){break;}
    }
    for(int i=1;i<8-Y1;i++){
        if(!isupper(arr[Y1+i][X1])){    //the rook can move down any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1+i);
            arr_R[j].x1=x1;
            arr_R[j].y1=y1;
            j++;
        }
        if(islower(arr[Y1+i][X1])){break;}
   }
int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_R[s].x1 && y2==arr_R[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(CHECK(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    Black(arr);
}
}
//function for rook
void rook(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct rook{
    char x1;
    int y1;
    };
    struct rook arr_r[MAX];
    char x1;
    int y1,j=0;
    for(int i=1;i<X1+1;i++){  //the rook can move to the left any number of squares
        if(!islower(arr[Y1][X1-i])){
            x1=convert_ArrayChar(X1-i);
            y1=convert_ArrayInt(Y1);
            arr_r[j].x1=x1;
            arr_r[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1][X1-i])){break;}
    }
    for(int i=1;i<8-X1;i++){  //the rook can move to the right any number of squares
        if(!islower(arr[Y1][X1+i])){
            x1=convert_ArrayChar(X1+i);
            y1=convert_ArrayInt(Y1);
            arr_r[j].x1=x1;
            arr_r[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1][X1+i])){break;}
    }
    for(int i=1;i<Y1+1;i++){
        if(!islower(arr[Y1-i][X1])){    //the rook can move up any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1-i);
            arr_r[j].x1=x1;
            arr_r[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1-i][X1])){break;}
    }
    for(int i=1;i<8-Y1;i++){
        if(!islower(arr[Y1+i][X1])){    //the rook can move down any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1+i);
            arr_r[j].x1=x1;
            arr_r[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1+i][X1])){break;}
   }
int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_r[s].x1 && y2==arr_r[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(check(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    white(arr);
}
}
//function for NIGHT
void NIGHT(int Y1,int X1,char arr[8][8],char x2,int y2){    //the night moves in L shape
    struct NIGHT{
    char x1;
    int y1;
    };
    struct NIGHT arr_N[MAX];
    char x1;
    int y1,j=0;
    if((-1<Y1+1)&&(Y1+1<8) && (-1<X1-2)&&(X1-2<8)){
    if(!isupper(arr[Y1+1][X1-2])){
        x1=convert_ArrayChar(X1-2);
        y1=convert_ArrayInt(Y1+1);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1+1)&&(Y1+1<8) && (-1<X1+2)&&(X1+2<8)){
    if(!isupper(arr[Y1+1][X1+2])){
        x1=convert_ArrayChar(X1+2);
        y1=convert_ArrayInt(Y1+1);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1+2)&&(Y1+2<8) && (-1<X1-1)&&(X1-1<8)){
    if(!isupper(arr[Y1+2][X1-1])){
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1+2);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1+2)&&(Y1+2<8) && (-1<X1+1)&&(X1+1<8)){
    if(!isupper(arr[Y1+2][X1+1])){
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1+2);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1-1)&&(Y1-1<8) && (-1<X1-2)&&(X1-2<8)){
    if(!isupper(arr[Y1-1][X1-2])){
        x1=convert_ArrayChar(X1-2);
        y1=convert_ArrayInt(Y1-1);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1-1)&&(Y1-1<8) && (-1<X1+2)&&(X1+2<8)){
    if(!isupper(arr[Y1-1][X1+2])){
        x1=convert_ArrayChar(X1+2);
        y1=convert_ArrayInt(Y1-1);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1-2)&&(Y1-2<8) && (-1<X1-1)&&(X1-1<8)){
    if(!isupper(arr[Y1-2][X1-1])){
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1-2);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    if((-1<Y1-2)&&(Y1-2<8) && (-1<X1+1)&&(X1+1<8)){
    if(!isupper(arr[Y1-2][X1+1])){
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1-2);
        arr_N[j].x1=x1;
        arr_N[j].y1=y1;
        j++;
    }}
    int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_N[s].x1 && y2==arr_N[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(CHECK(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    Black(arr);
}
}
//function for night
void night(int Y1,int X1,char arr[8][8],char x2,int y2){    //the night moves in L shape
    struct night{
    char x1;
    int y1;
    };
    struct night arr_n[MAX];
    char x1;
    int y1,j=0;
    if((-1<Y1+1)&&(Y1+1<8) && (-1<X1-2)&&(X1-2<8)){
    if(!islower(arr[Y1+1][X1-2])){
        x1=convert_ArrayChar(X1-2);
        y1=convert_ArrayInt(Y1+1);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1+1)&&(Y1+1<8) && (-1<X1+2)&&(X1+2<8)){
    if(!islower(arr[Y1+1][X1+2])){
        x1=convert_ArrayChar(X1+2);
        y1=convert_ArrayInt(Y1+1);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1+2)&&(Y1+2<8) && (-1<X1-1)&&(X1-1<8)){
    if(!islower(arr[Y1+2][X1-1])){
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1+2);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1+2)&&(Y1+2<8) && (-1<X1+1)&&(X1+1<8)){
    if(!islower(arr[Y1+2][X1+1])){
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1+2);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1-1)&&(Y1-1<8) && (-1<X1-2)&&(X1-2<8)){
    if(!islower(arr[Y1-1][X1-2])){
        x1=convert_ArrayChar(X1-2);
        y1=convert_ArrayInt(Y1-1);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1-1)&&(Y1-1<8) && (-1<X1+2)&&(X1+2<8)){
    if(!islower(arr[Y1-1][X1+2])){
        x1=convert_ArrayChar(X1+2);
        y1=convert_ArrayInt(Y1-1);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1-2)&&(Y1-2<8) && (-1<X1-1)&&(X1-1<8)){
    if(!islower(arr[Y1-2][X1-1])||arr[Y1-2][X1-1]==' '){
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1-2);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    if((-1<Y1-2)&&(Y1-2<8) && (-1<X1+1)&&(X1+1<8)){
    if(!islower(arr[Y1-2][X1+1])){
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1-2);
        arr_n[j].x1=x1;
        arr_n[j].y1=y1;
        j++;
    }}
    int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_n[s].x1 && y2==arr_n[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(check(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    white(arr);
}
}
//function for BISHOP
void BISHOP(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct BISHOP{
        char x1;
        int y1;
    };
    struct BISHOP arr_B[MAX];
    char x1;
    int y1,i=1,j=0;
    while(Y1-i>-1 && X1+i<8){     //bishop can move to the upper right corner any number of squares
        if(!isupper(arr[Y1-i][X1+i]) || arr[Y1-i][X1+i]==' '){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1-i);
        arr_B[j].x1=x1;
        arr_B[j].y1=y1;
        j++;
        }
        if(arr[Y1-i][X1+i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1-i>-1){      //bishop can move to the down left corner any number of squares
        if(!isupper(arr[Y1+i][X1-i]) || arr[Y1+i][X1-i]==' '){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1+i);
        arr_B[j].x1=x1;
        arr_B[j].y1=y1;
        j++;
        }
        if(arr[Y1+i][X1-i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1-i>-1 && X1-i>-1){    //bishop can move to upper left corner ant number of squares
        if(!isupper(arr[Y1-i][X1-i]) || arr[Y1-i][X1-i]==' '){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1-i);
        arr_B[j].x1=x1;
        arr_B[j].y1=y1;
        j++;
        }
        if(arr[Y1-i][X1-i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1+i<8){    //bishop can move to the down right corner ant number of squares
        if(!isupper(arr[Y1+i][X1+i]) || arr[Y1+i][X1+i]==' '){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1+i);
        arr_B[j].x1=x1;
        arr_B[j].y1=y1;
        j++;
        }
        if(arr[Y1+i][X1+i]!=' '){break;}
        i++;
}
    int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_B[s].x1 && y2==arr_B[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(CHECK(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    Black(arr);
}
}
//function for bishop
void bishop(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct bishop{
        char x1;
        int y1;
    };
    struct bishop arr_b[MAX];
    char x1;
    int y1,i=1,j=0;
    while(Y1-i>-1 && X1+i<8){     //bishop can move to the upper right corner any number of squares
        if(!islower(arr[Y1-i][X1+i]) || arr[Y1-i][X1+i]==' '){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1-i);
        arr_b[j].x1=x1;
        arr_b[j].y1=y1;
        j++;
        }
        if(arr[Y1-i][X1+i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1-i>-1){      //bishop can move to the down left corner any number of squares
        if(!islower(arr[Y1+i][X1-i]) || arr[Y1+i][X1-i]==' '){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1+i);
        arr_b[j].x1=x1;
        arr_b[j].y1=y1;
        j++;
        }
        if(arr[Y1+i][X1-i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1-i>-1 && X1-i>-1){    //bishop can move to upper left corner ant number of squares
        if(!islower(arr[Y1-i][X1-i]) || arr[Y1-i][X1-i]==' '){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1-i);
        arr_b[j].x1=x1;
        arr_b[j].y1=y1;
        j++;
        }
        if(arr[Y1-i][X1-i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1+i<8){    //bishop can move to the down right corner ant number of squares
        if(!islower(arr[Y1+i][X1+i]) || arr[Y1+i][X1+i]==' '){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1+i);
        arr_b[j].x1=x1;
        arr_b[j].y1=y1;
        j++;
        }
        if(arr[Y1+i][X1+i]!=' '){break;}
        i++;
}
    int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_b[s].x1 && y2==arr_b[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(check(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    white(arr);
}
}
//function for QUEENN
void QUEEN(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct QUEEN{
        char x1;
        int y1;
    };
    struct QUEEN arr_Q[MAX];
    char x1;
    int y1,j=0;
    for(int i=1;i<8-X1;i++){      //the queen can move to the right any number of squares
        if(!isupper(arr[Y1][X1+i])||arr[Y1][X1+i]==' '){
            x1=convert_ArrayChar(X1+i);
            y1=convert_ArrayInt(Y1);
            arr_Q[j].x1=x1;
            arr_Q[j].y1=y1;
            j++;
        }
        if(arr[Y1][X1+i]!=' '){break;}
    }
    for(int i=1;i<X1+1;i++){   //the queen can move to the left any number of squares
        if(!isupper(arr[Y1][X1-i])||arr[Y1][X1-i]==' '){
            x1=convert_ArrayChar(X1-i);
            y1=convert_ArrayInt(Y1);
            arr_Q[j].x1=x1;
            arr_Q[j].y1=y1;
            j++;
        }
        if(arr[Y1][X1-i]!=' '){break;}
    }
    for(int i=1;i<Y1+1;i++){
        if(!isupper(arr[Y1-i][X1])||arr[Y1-i][X1]==' '){    //the queen can move up any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1-i);
            arr_Q[j].x1=x1;
            arr_Q[j].y1=y1;
            j++;
        }
        if(arr[Y1-i][X1]!=' '){break;}
    }
    for(int i=1;i<8-Y1;i++){
        if(!isupper(arr[Y1+i][X1])||arr[Y1+i][X1]==' '){    //the queen can move down any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1+i);
            arr_Q[j].x1=x1;
            arr_Q[j].y1=y1;
            j++;
        }
        if(arr[Y1+i][X1]!=' '){break;}
   }
    int i=1;
    while(Y1-i>-1 && X1+i<8){     //queen can move to the upper right corner any number of squares
        if(!isupper(arr[Y1-i][X1+i]) || arr[Y1-i][X1+i]==' '){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1-i);
        arr_Q[j].x1=x1;
        arr_Q[j].y1=y1;
        j++;
        }
        if(arr[Y1-i][X1+i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1-i>-1){      //queen can move to the down left corner any number of squares
        if(!isupper(arr[Y1+i][X1-i]) || arr[Y1+i][X1-i]==' '){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1+i);
        arr_Q[j].x1=x1;
        arr_Q[j].y1=y1;
        j++;
        }
        if(arr[Y1+i][X1-i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1-i>-1 && X1-i>-1){    //queen can move to upper left corner any number of squares
        if(!isupper(arr[Y1-i][X1-i]) || arr[Y1-i][X1-i]==' '){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1-i);
        arr_Q[j].x1=x1;
        arr_Q[j].y1=y1;
        j++;
        }
        if(arr[Y1-i][X1-i]!=' '){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1+i<8){    //queen can move to the down right corner any number of squares
        if(!isupper(arr[Y1+i][X1+i]) || arr[Y1+i][X1+i]==' '){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1+i);
        arr_Q[j].x1=x1;
        arr_Q[j].y1=y1;
        j++;
        }
        if(arr[Y1+i][X1+i]!=' '){break;}
        i++;
}
    int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_Q[s].x1 && y2==arr_Q[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(CHECK(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
   printf("please,Enter a valid movement\n");
   Black(arr);
}
}
//function for queen
void queen(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct queen{
        char x1;
        int y1;
    };
    struct queen arr_q[MAX];
    char x1;
    int y1,j=0;
    for(int i=1;i<8-X1;i++){      //the queen can move to the right any number of squares
        if(!islower(arr[Y1][X1+i])){
            x1=convert_ArrayChar(X1+i);
            y1=convert_ArrayInt(Y1);
            arr_q[j].x1=x1;
            arr_q[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1][X1+i])){break;}
    }
    for(int i=1;i<X1+1;i++){   //the queen can move to the left any number of squares
        if(!islower(arr[Y1][X1-i])){
            x1=convert_ArrayChar(X1-i);
            y1=convert_ArrayInt(Y1);
            arr_q[j].x1=x1;
            arr_q[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1][X1-i])){break;}
    }
    for(int i=1;i<Y1+1;i++){
        if(!islower(arr[Y1-i][X1])){    //the queen can move up any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1-i);
            arr_q[j].x1=x1;
            arr_q[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1-i][X1])){break;}
    }
    for(int i=1;i<8-Y1;i++){
        if(!islower(arr[Y1+i][X1])){    //the queen can move down any number of squares
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1+i);
            arr_q[j].x1=x1;
            arr_q[j].y1=y1;
            j++;
        }
        if(isupper(arr[Y1+i][X1])){break;}
   }
    int i=1;
    while(Y1-i>-1 && X1+i<8){     //queen can move to the upper right corner any number of squares
        if(!islower(arr[Y1-i][X1+i])){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1-i);
        arr_q[j].x1=x1;
        arr_q[j].y1=y1;
        j++;
        }
        if(isupper(arr[Y1-i][X1+i])){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1-i>-1){      //queen can move to the down left corner any number of squares
        if(!islower(arr[Y1+i][X1-i])){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1+i);
        arr_q[j].x1=x1;
        arr_q[j].y1=y1;
        j++;
        }
        if(isupper(arr[Y1+i][X1-i])){break;}
        i++;
    }
    i=1;
    while(Y1-i>-1 && X1-i>-1){    //queen can move to upper left corner any number of squares
        if(!islower(arr[Y1-i][X1-i])){
        x1=convert_ArrayChar(X1-i);
        y1=convert_ArrayInt(Y1-i);
        arr_q[j].x1=x1;
        arr_q[j].y1=y1;
        j++;
        }
        if(isupper(arr[Y1-i][X1-i])){break;}
        i++;
    }
    i=1;
    while(Y1+i<8 && X1+i<8){    //queen can move to the down right corner any number of squares
        if(!islower(arr[Y1+i][X1+i])){
        x1=convert_ArrayChar(X1+i);
        y1=convert_ArrayInt(Y1+i);
        arr_q[j].x1=x1;
        arr_q[j].y1=y1;
        j++;
        }
        if(isupper(arr[Y1+i][X1+i])){break;}
        i++;
}
int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_q[s].x1 && y2==arr_q[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(check(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
   white(arr);
}
}
//function for KING
void KING(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct KING{
        char x1;
        int y1;
    };
    struct KING arr_K[MAX];
    char x1;
    int y1,j=0;
    if(0<=Y1&&Y1<=7 && 0<=X1+1&&X1+1<=7){
    if(!isupper(arr[Y1][X1+1]) || arr[Y1][X1+1]==' '){   //right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1&&Y1<=7 && 0<=X1-1&&X1-1<=7){
    if(!isupper(arr[Y1][X1-1]) || arr[Y1][X1-1]==' '){   //left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1-1&&Y1-1<=7 && 0<=X1&&X1<=7){
    if(!isupper(arr[Y1-1][X1]) || arr[Y1-1][X1]==' '){   //up
        x1=convert_ArrayChar(X1);
        y1=convert_ArrayInt(Y1-1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1+1&&Y1+1<=7 && 0<=X1&&X1<=7){
    if(!isupper(arr[Y1+1][X1]) || arr[Y1+1][X1]==' '){   //down
        x1=convert_ArrayChar(X1);
        y1=convert_ArrayInt(Y1+1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1-1&&Y1-1<=7 && 0<=X1+1&&X1+1<=7){
    if(!isupper(arr[Y1-1][X1+1]) || arr[Y1-1][X1+1]==' '){   //upper right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1-1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1-1&&Y1-1<=7 && 0<=X1-1&&X1-1<=7){
    if(!isupper(arr[Y1-1][X1-1]) || arr[Y1-1][X1-1]==' '){    //upper left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1-1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1+1&&Y1+1<=7 && 0<=X1+1&&X1+1<=7){
    if(!isupper(arr[Y1+1][X1+1]) || arr[Y1+1][X1+1]==' '){    //down right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1+1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
    if(0<=Y1+1&&Y1+1<=7 && 0<=X1-1&&X1-1<=7){
    if(!isupper(arr[Y1+1][X1-1]) || arr[Y1+1][X1-1]==' '){   //down left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1+1);
        arr_K[j].x1=x1;
        arr_K[j].y1=y1;
        j++;
    }}
int h=0;
for(int s=0;s<j;s++){
    if(x2==arr_K[s].x1 && y2==arr_K[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(CHECK(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    Black(arr);
}
}
//function for king
void king(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct king{
        char x1;
        int y1;
    };
    struct king arr_k[MAX];
    char x1;
    int y1,j=0;
    if(0<=Y1&&Y1<=7 && 0<=X1+1&&X1+1<=7){
    if(!islower(arr[Y1][X1+1])){   //right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1&&Y1<=7 && 0<=X1-1&&X1-1<=7){
    if(!islower(arr[Y1][X1-1])){   //left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1-1&&Y1-1<=7 && 0<=X1&&X1<=7){
    if(!islower(arr[Y1-1][X1])){   //up
        x1=convert_ArrayChar(X1);
        y1=convert_ArrayInt(Y1-1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1+1&&Y1+1<=7 && 0<=X1&&X1<=7){
    if(!islower(arr[Y1+1][X1])){   //down
        x1=convert_ArrayChar(X1);
        y1=convert_ArrayInt(Y1+1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1-1&&Y1-1<=7 && 0<=X1+1&&X1+1<=7){
    if(!islower(arr[Y1-1][X1+1])){   //up right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1-1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1-1&&Y1-1<=7 && 0<=X1-1&&X1-1<=7){
    if(!islower(arr[Y1-1][X1-1])){    //up left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1-1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1+1&&Y1+1<=7 && 0<=X1+1&&X1+1<=7){
    if(!islower(arr[Y1+1][X1+1])){    //down right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1+1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
    if(0<=Y1+1&&Y1+1<=7 && 0<=X1-1&&X1-1<=7){
    if(!islower(arr[Y1+1][X1-1])){   //down left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1+1);
        arr_k[j].x1=x1;
        arr_k[j].y1=y1;
        j++;
    }}
int h=0,s;
for(s=0;s<j;s++){
    if(x2==arr_k[s].x1 && y2==arr_k[s].y1){
        int X2=convert_char(x2);
        int Y2=convert_int(y2);
        Do_move(arr,Y1,X1,Y2,X2);
        if(check(arr)!=1){
        DO_not_move(arr,Y1,X1,Y2,X2);
        move(Y1,X1,Y2,X2,arr);
        h++;
        }
        else{
            DO_not_move(arr,Y1,X1,Y2,X2);
        }
    }
}

if(h==0){
    printf("please,Enter a valid movement\n");
    white(arr);
}
}
//function for PAWN
void PAWN(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct PAWN{
        char x1;
        int y1;
    };
    struct PAWN arr_P[MAX];
    char x1;
    int y1,j=0;
    if(Y1==1&&(X1==0||X1==1||X1==2||X1==3||X1==4|| X1==5||X1==6||X1==7)){  //at the first move,black pawn can move down 2 steps
        for(int i=1;i<3;i++){
            if(arr[Y1+i][X1]==' '){
                x1=convert_ArrayChar(X1);
                y1=convert_ArrayInt(Y1+i);
                arr_P[j].x1=x1;
                arr_P[j].y1=y1;
                j++;
            }
            if(arr[Y1+i][X1]!=' '){break;}
        }
    }
    else if(Y1+1<8 && arr[Y1+1][X1]==' '){  //if it is not at the first row,it can move one square to the down
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1+1);
            arr_P[j].x1=x1;
            arr_P[j].y1=y1;
            j++;
    }
    if(!isupper(arr[Y1+1][X1-1])&&arr[Y1+1][X1-1]!=' '&&Y1+1<8&&X1-1>-1){   //the black pawn can attack to down left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1+1);
        arr_P[j].x1=x1;
        arr_P[j].y1=y1;
        j++;
    }
    if(!isupper(arr[Y1+1][X1+1])&&arr[Y1+1][X1+1]!=' '&&Y1+1<8&&X1+1<8){   //the black pawn can attack to down right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1+1);
        arr_P[j].x1=x1;
        arr_P[j].y1=y1;
        j++;
    }
int h=0,s;

for(s=0;s<j;s++){
        if(x2==arr_P[s].x1 && y2==arr_P[s].y1){
                int X2=convert_char(x2);
                int Y2=convert_int(y2);
        if(Y1==6 && (X1==0||X1==1||X1==2||X1==3||X1==4||X1==5||X1==6||X1==7)){   //if it is at the row before the last(promotion)
                char promotion;
                printf("Enter the symbol of the piece you wish to promote the pawn to: ");
                scanf("%c",&promotion);
                scanf("%c",&promotion);
                while(promotion!='R'&&promotion!='B'&&promotion!='Q'&&promotion!='N'){
                    printf("please,Enter a valid symbol from( R, B, Q, N): ");
                    scanf("%c",&promotion);
                    scanf("%c",&promotion);
                }
                if(promotion=='R'||promotion=='B'||promotion=='Q'||promotion=='N'){
                    arr[Y1][X1]=promotion;
                    int X2=convert_char(x2);
                    int Y2=convert_int(y2);
                    Do_move(arr,Y1,X1,Y2,X2);
                    if(CHECK(arr)!=1){
                    DO_not_move(arr,Y1,X1,Y2,X2);
                    move(Y1,X1,Y2,X2,arr);
                    h++;
                    }
                    else{
                      DO_not_move(arr,Y1,X1,Y2,X2);
                    }
                  }
          }
          else{
                int X2=convert_char(x2);
                int Y2=convert_int(y2);
                Do_move(arr,Y1,X1,Y2,X2);
                if(CHECK(arr)!=1){
                DO_not_move(arr,Y1,X1,Y2,X2);
                move(Y1,X1,Y2,X2,arr);
                h++;
                }
                else{
                    DO_not_move(arr,Y1,X1,Y2,X2);
                }
          }
        }
}
if(h==0){
    printf("please,Enter a valid movement\n");
    Black(arr);
}
}
//function for pawn
void pawn(int Y1,int X1,char arr[8][8],char x2,int y2){
    struct pawn{
        char x1;
        int y1;
    };
    struct pawn arr_p[MAX];
    char x1;
    int y1,j=0;
    if(Y1==6&&(X1==0||X1==1||X1==2||X1==3||X1==4|| X1==5||X1==6||X1==7)){  //at the first move,white pawn can move up 2 steps
        for(int i=1;i<3;i++){
            if(arr[Y1-i][X1]==' '){
                x1=convert_ArrayChar(X1);
                y1=convert_ArrayInt(Y1-i);
                arr_p[j].x1=x1;
                arr_p[j].y1=y1;
                j++;
            }
            if(arr[Y1-i][X1]!=' '){break;}
        }
    }
    else if(Y1-1>-1 && arr[Y1-1][X1]==' '){  //if it is not at the first row,it can move one square to the up
            x1=convert_ArrayChar(X1);
            y1=convert_ArrayInt(Y1-1);
            arr_p[j].x1=x1;
            arr_p[j].y1=y1;
            j++;
    }
    if(isupper(arr[Y1-1][X1-1])&&Y1-1>-1&&X1-1>-1){   //the black pawn can attack to upper left
        x1=convert_ArrayChar(X1-1);
        y1=convert_ArrayInt(Y1-1);
        arr_p[j].x1=x1;
        arr_p[j].y1=y1;
        j++;
    }
    if(isupper(arr[Y1-1][X1+1])&&Y1-1>-1&&X1+1<8){   //the black pawn can attack to upper right
        x1=convert_ArrayChar(X1+1);
        y1=convert_ArrayInt(Y1-1);
        arr_p[j].x1=x1;
        arr_p[j].y1=y1;
        j++;
    }

int h=0,s;
for(s=0;s<j;s++){
        if(x2==arr_p[s].x1 && y2==arr_p[s].y1){
                int X2=convert_char(x2);
                int Y2=convert_int(y2);
        if(Y1==1 && (X1==0||X1==1||X1==2||X1==3||X1==4||X1==5||X1==6||X1==7)){   //if it is at the row before the last(promotion)
                char promotion;
                printf("Enter the symbol of the piece you wish to promote the pawn to: ");
                scanf("%c",&promotion);
                scanf("%c",&promotion);
                while(promotion!='r'&&promotion!='b'&&promotion!='q'&&promotion!='n'){
                    printf("please,Enter a valid symbol from( r, b, q, n): ");
                    scanf("%c",&promotion);
                    scanf("%c",&promotion);
                }
                if(promotion=='r'||promotion=='b'||promotion=='q'||promotion=='n'){
                    arr[Y1][X1]=promotion;
                    int X2=convert_char(x2);
                    int Y2=convert_int(y2);
                    Do_move(arr,Y1,X1,Y2,X2);
                    if(check(arr)!=1){
                    DO_not_move(arr,Y1,X1,Y2,X2);
                    move(Y1,X1,Y2,X2,arr);
                    h++;
                    }
                    else{
                      DO_not_move(arr,Y1,X1,Y2,X2);
                    }
                  }
          }
          else{
                int X2=convert_char(x2);
                int Y2=convert_int(y2);
                Do_move(arr,Y1,X1,Y2,X2);
                if(check(arr)!=1){
                DO_not_move(arr,Y1,X1,Y2,X2);
                move(Y1,X1,Y2,X2,arr);
                h++;
                }
                else{
                    DO_not_move(arr,Y1,X1,Y2,X2);
                }
          }
        }
}
if(h==0){
    printf("please,Enter a valid movement\n");
    white(arr);
}
}
//function for UNDO
void undo(char arr[8][8]){
    int i,j;
    char s;
    printf("\n\t\t[chess in C]\n");
    printf("   ");
    for(s='A';s<'I';s++){
        printf("%c   ",s);    //from A to H above
    }
    printf("\n-----------------------------------\n");
//print the components of chess with '-' for white squares & '.' for black squares
int h = 8;
int f = 8;
    for(i=0;i<8;i++){
        printf("%d  ",h--);    //from 1 to 8 right
        for(j=0;j<8;j++){
                if(i%2==0){
                        if(j%2==0){
                            printf("%c-| ",ARR[o][i][j]);
                        }
                        else{
                            printf("%c.| ",ARR[o][i][j]);
                        }
                }
                else{
                    if(j%2==0){
                        printf("%c.| ",ARR[o][i][j]);
                    }
                    else{
                        printf("%c-| ",ARR[o][i][j]);
                    }
                }
        }
        printf("%d  ",f--);   //from 1 to 8 left
        printf("\n-----------------------------------\n");
    }
    printf("   ");
    for(s='A';s<'I';s++){
        printf("%c   ",s);    //from A to H below
    }
    printf("     ");

for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        arr[i][j]=ARR[o][i][j];
    }
}
printf("the pieces taken out from WHITE player: ");
    for(int i=0;i<taken;i++){
        printf("%c ",eaten[e][i]);}
    printf("\n");
    printf("\t\t\t\t\tthe pieces taken out from BLACK player: ");
    for(int j=0;j<TAKEN;j++){
        printf("%c ",EATEN[E][j]);}
    printf("\n");
for(int i=0;i<taken;i++){
    t[i]=eaten[e][i];
}
for(int j=0;j<TAKEN;j++){
    T[j]=EATEN[E][j];
}
}
//function for REDO
void redo(char arr[8][8]){
    int i,j;
    char s;
    printf("\n\t\t[chess in C]\n");
    printf("   ");
    for(s='A';s<'I';s++){
        printf("%c   ",s);    //from A to H above
    }
    printf("\n-----------------------------------\n");
//print the components of chess with '-' for white squares & '.' for black squares
int h = 8;
int f = 8;
    for(i=0;i<8;i++){
        printf("%d  ",h--);    //from 1 to 8 right
        for(j=0;j<8;j++){
                if(i%2==0){
                        if(j%2==0){
                            printf("%c-| ",ARR[o][i][j]);
                        }
                        else{
                            printf("%c.| ",ARR[o][i][j]);
                        }
                }
                else{
                    if(j%2==0){
                        printf("%c.| ",ARR[o][i][j]);
                    }
                    else{
                        printf("%c-| ",ARR[o][i][j]);
                    }
                }
        }
        printf("%d  ",f--);   //from 1 to 8 left
        printf("\n-----------------------------------\n");
    }
    printf("   ");
    for(s='A';s<'I';s++){
        printf("%c   ",s);    //from A to H below
    }
    printf("     ");

for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        arr[i][j]=ARR[o][i][j];
    }
}
printf("the pieces taken out from WHITE player: ");
    for(int i=0;i<taken;i++){
        printf("%c ",eaten[e][i]);}
    printf("\n");
    printf("\t\t\t\t\tthe pieces taken out from BLACK player: ");
    for(int j=0;j<TAKEN;j++){
        printf("%c ",EATEN[E][j]);}
    printf("\n");
for(int i=0;i<taken;i++){
    t[i]=eaten[e][i];
}
for(int j=0;j<TAKEN;j++){
    T[j]=EATEN[E][j];
}
}
int turn;
//function for save
void save(char arr[8][8],char t[16],char T[16],int turn){
    FILE*f;
    f=fopen("chess in c","w");
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            putc(arr[i][j],f);
        }
    }
    for(int i=0;i<16;i++){
        putc(t[i],f);
    }
    for(int j=0;j<16;j++){
        putc(T[j],f);
    }
    if(turn==1){putc('k',f);}
    else if(turn==0){putc('K',f);}
    fclose(f);
}
char TurN;
//function for load
int load(char arr[8][8],char t[16],char T[16],int turn){
    char name[MAX],x;
    FILE*f;
        f=fopen("chess in c","r");
char k,m,n;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            k = getc(f);
            arr[i][j]=k;
        }
    }
    for(int i=0;i<16;i++){
        m=getc(f);
        t[i]=m;
    }
    for(int j=0;j<16;j++){
        n=getc(f);
        T[j]=n;
    }
    x=getc(f);
    TurN=x;
    fclose(f);
}
int num=0;   //number of undone moves
int k;
//function for the black player
void Black(char arr[8][8]){
printf("\n[the BLACK player]\n");
//int turn = 0;
printf("To Undo,Enter 1 & To Redo,Enter 2 & To save,Enter 3 & To load,Enter 4 & To continue,Enter 0 : ");
scanf("%d",&k);
while((o==0&&k==1) || (num==0&&k==2) || (k!=1&&k!=2&&k!=3&&k!=4&&k!=0)){
    printf("NOT FOUND\n");
    printf("To Undo,Enter 1 & To Redo,Enter 2 & To save,Enter 3 & To load,Enter 4 & To continue,Enter 0 : ");
    scanf("%d",&k);
}

if(k==1){
    o--;    //print the previous array
    e--;
    E--;
    undo(arr);
    num++;  //the undone moves increase by one
}
else if(k==2){
    o++;    //print the next array
    e++;
    E++;
    redo(arr);
    num--;  //the undone moves decrease by one
}
else if(k==3){
    save(arr,t,T,turn);
}
else if(k==4){
    load(arr,t,T,turn);
//board
    for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        ARR[o][i][j]=arr[i][j];
    }
}
    board(arr);
//taken out
    for(int i=0;i<16;i++){
        eaten[e][i]=t[i];
}
for(int j=0;j<16;j++){
    EATEN[E][j]=T[j];
}

    printf("the pieces taken out from WHITE player: ");
    for(int i=0;i<16;i++){
        printf("%c ",eaten[e][i]);}
    printf("\n");
    printf("\t\t\t\t\tthe pieces taken out from BLACK player: ");
    for(int j=0;j<16;j++){
        printf("%c ",EATEN[E][j]);}
    printf("\n");
//turn
     if(TurN=='k'){white(arr);}
     else if(TurN=='K'){Black(arr);}
}
else if(k==0){
    char x1,x2;
    int y1,y2,X1,Y1,X2,Y2;
    printf("Enter your move: ");
    scanf(" %c%d %c%d",&x1,&y1,&x2,&y2);
    X1=convert_char(x1);
    Y1=convert_int(y1);
    while(arr[Y1][X1]==' '||islower(arr[Y1][X1])||(x1!='A'&&x1!='B'&&x1!='C'&&x1!='D'&&x1!='E'&&x1!='F'&&x1!='G'&&x1!='H') || (y1!=1&&y1!=2&&y1!=3&&y1!=4&&y1!=5&&y1!=6&&y1!=7&&y1!=8) ||
        (x2!='A'&&x2!='B'&&x2!='C'&&x2!='D'&&x2!='E'&&x2!='F'&&x2!='G'&&x2!='H') || (y2!=1&&y2!=2&&y2!=3&&y2!=4&&y2!=5&&y2!=6&&y2!=7&&y2!=8)){
        printf("please,Enter a valid index: ");
        scanf(" %c%d %c%d",&x1,&y1,&x2,&y2);
        X1=convert_char(x1);
        Y1=convert_int(y1);
    }

    if(arr[Y1][X1]=='R'){ROOK(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='N'){NIGHT(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='B'){BISHOP(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='Q'){QUEEN(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='K'){KING(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='P'){PAWN(Y1,X1,arr,x2,y2);}
}}
//function for the white player
void white(char arr[8][8]){
printf("\n[the white player]\n");
//turn = 1;
printf("To Undo,Enter 1 & To Redo,Enter 2 & To save,Enter 3 & To load,Enter 4 & To continue,Enter 0 : ");
scanf("%d",&k);
while((o==0&&k==1) || (num==0&&k==2) || (k!=1&&k!=2&&k!=3&&k!=4&&k!=0)){
    printf("NOT FOUND\n");
    printf("To Undo,Enter 1 & To Redo,Enter 2 & To save,Enter 3 & To load,Enter 4 & To continue,Enter 0 : ");
    scanf("%d",&k);
}

if(k==1){
    o--;   //print the previous array
    e--;
    E--;
    undo(arr);
    num++; //the undone moves increase by one
}
else if(k==2){
    o++;   //print the next array
    e++;
    E++;
    redo(arr);
    num--; //the undone moves decrease by one
}
else if(k==3){
    save(arr,t,T,turn);
}
else if(k==4){
    load(arr,t,T,turn);
//board
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        ARR[o][i][j]=arr[i][j];
    }
}
    board(arr);
//taken out
for(int i=0;i<16;i++){
        eaten[e][i]=t[i];
}
for(int j=0;j<16;j++){
    EATEN[E][j]=T[j];
}

    printf("the pieces taken out from WHITE player: ");
    for(int i=0;i<16;i++){
        printf("%c ",eaten[e][i]);}
    printf("\n");
    printf("\t\t\t\t\tthe pieces taken out from BLACK player: ");
    for(int j=0;j<16;j++){
        printf("%c ",EATEN[E][j]);}
    printf("\n");
//turn
    if(TurN=='k'){white(arr);}
     else if(TurN=='K'){Black(arr);}
}
else if(k==0){
    char x1,x2;
    int y1,y2,X1,Y1,X2,Y2;
    printf("Enter your move: ");
    scanf(" %c%d %c%d",&x1,&y1,&x2,&y2);
    X1=convert_char(x1);
    Y1=convert_int(y1);
    while(arr[Y1][X1]==' '||isupper(arr[Y1][X1])||(x1!='A'&&x1!='B'&&x1!='C'&&x1!='D'&&x1!='E'&&x1!='F'&&x1!='G'&&x1!='H') || (y1!=1&&y1!=2&&y1!=3&&y1!=4&&y1!=5&&y1!=6&&y1!=7&&y1!=8) ||
        (x2!='A'&&x2!='B'&&x2!='C'&&x2!='D'&&x2!='E'&&x2!='F'&&x2!='G'&&x2!='H') || (y2!=1&&y2!=2&&y2!=3&&y2!=4&&y2!=5&&y2!=6&&y2!=7&&y2!=8)){
        printf("please,Enter a valid index: ");
        scanf(" %c%d %c%d",&x1,&y1,&x2,&y2);
        X1=convert_char(x1);
        Y1=convert_int(y1);
    }

    if(arr[Y1][X1]=='r'){rook(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='n'){night(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='b'){bishop(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='q'){queen(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='k'){king(Y1,X1,arr,x2,y2);}
    else if(arr[Y1][X1]=='p'){pawn(Y1,X1,arr,x2,y2);}
}}
int main(){
char arr[8][8]={
{'R','N','B','Q','K','B','N','R'},
{'P','P','P','P','P','P','P','P'},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{' ',' ',' ',' ',' ',' ',' ',' '},
{'p','p','p','p','p','p','p','p'},
{'r','n','b','q','k','b','n','r'},
};
//store the first 2D array in the 3D one
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        ARR[0][i][j]=arr[i][j];
    }
}
board(arr);
while(Dead_position(arr)!=1&&CHECK_MATE(arr)!=1&&check_mate(arr)!=1&&STALE_MATE(arr)!=1&&stale_mate(arr)!=1){
if(k==3){break;}
turn = 1;
white(arr);
if(CHECK(arr)){
        printf("!!black king is in check position,Try to make it save!!");}
if(Dead_position(arr)||CHECK_MATE(arr)||STALE_MATE(arr)){
    if(CHECK_MATE(arr)){
       printf("\nbut there is no way to save it so,,,\nCHECK MATE\n");
       printf("WHITE player WINS!\nGAME OVER\n");}
    if(STALE_MATE(arr)){
        printf("STALE MATE\n");
        printf("TIE...Draw by stalemate...NO player wins\n");}
    if(Dead_position(arr)){
        printf("Dead position\n");
        printf("TIE...Draw by dead position...NO player wins\n");}
    break;}
if(k==3){break;}
turn = 0;
Black(arr);
if(check(arr)){
        printf("!!white king is in check position,Try to make it save!!");}
if(Dead_position(arr)||check_mate(arr)||stale_mate(arr)){
    if(check_mate(arr)){
        printf("\nbut there is no way to save it so,,,\nCHECK MATE\n");
        printf("BLACK player WINS!\nGAME OVER\n");}
    if(stale_mate(arr)){
        printf("STALE MATE\n");
        printf("TIE...Draw by stalemate...NO player wins\n");}
    if(Dead_position(arr)){
        printf("Dead position\n");
        printf("TIE...Draw by dead position...NO player wins\n");}
    break;}
if(k==3){break;}
}
}
