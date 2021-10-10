#include <stdio.h>


int main( )
{
char expr[100];
    int bf = 0;
    int i;
    
    printf("enter expression: ");
    scanf("%s", &expr);
    
    //scan
    i=0;
    while(expr[i] != '\0')
    {
        if(expr[i]=='(' )
        bf++;
        else if(expr[i] == ')' ){
            bf--;
        if(bf<0)
        break;}
        i++;
    }
    
    //output
    if(bf == 0)
    printf("Balanced Parenthesis. \n");
    
    else {
    printf("Unbalanced.\n");}
    
    
    
    return 0;
}
