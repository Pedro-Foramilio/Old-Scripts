
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int m[n][n];
    //leitura
    for (int i = 0; i < n; i++) {
        for (int j=0; j < n; j++) {
            scanf("%d", &m[i][j]);
        }
    }

    int parcial[n][n/2];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (n/2); j++) {
            parcial[i][j] = m[i][j] + m[i][n-j-1];
        }
    }

    int final[n/2][n/2];
    for (int j = 0; j < (n/2); j++) { 
        for (int i=0; i < (n/2); i++) {
            final[i][j] = parcial[i][j] + parcial[n-i-1][j];
        }
    }

    //print
    for (int i = 0; i < n/2; i++){
        for (int j = 0; j < n/2; j++) {
            printf("%d ",final[i][j]);
        }
        printf("\n");
    }

}
