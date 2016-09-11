#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#define MIN3(x, y, z) ((x) < (y) ? ((x) < (z) ? (x) : (z)) : ((y) < (z) ? (y) : (z)))
int main()
{
    int i,j;
    char string1[100], string2[100];
    printf("Enter string1:");
    fgets(string1, 100, stdin);
    printf("Enter string2:");
    fgets(string2, 100, stdin);
    int n=strlen(string1);
    int m=strlen(string2);
    int matrix[n+1][m+1];
    if(n==0)return m;
    if(m==0)return n;
    matrix[0][0] = 0;
    for (i = 0; i <= n; i++)
        matrix[i][0] = i;
    for (j = 0; j <= m; j++)
        matrix[0][j] = j;
for (i = 1; i <=n ; i++)
{
     for (j = 1; j <=m; j++)
    {
    matrix[i][j] = MIN3(matrix[i-1][j] + 1, matrix[i][j-1] + 1, matrix[i-1][j-1] + (string1[i-1] == string2[j-1] ? 0 : 1));

    }

}
printf("The Levenshtein distance is %d\n",matrix[n][m]);
float distance=matrix[n][m];
float maxlength;
float score;
float n1=strlen(string1)-1;
float n2=strlen(string2)-1;
if(n1>n2)
    maxlength=n1;
else
    maxlength=n2;
    score= 100*(1-distance/maxlength);
    printf("The similarity score is %f on 100",score);
return 0;

}

