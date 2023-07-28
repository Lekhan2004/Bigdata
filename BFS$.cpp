#include <stdio.h>
#include <stdlib.h>

int a[10][10], cs[10], f = 0, r = -1, v, e;
char arr[10], *names; 
void insert(char key) {
    arr[++r] = key;
}
char del() {
    return arr[f++];
}
void bfs(int a[][10], int n) {
    char ver;
    int k, l;
    for (int i = 0; i < v; i++) cs[i] = 1;
    cs[0] = 2;
    insert(names[0]);
    while (f <= r && f < n) {
        ver = del();
        printf("%c ", ver); 
        for (k = 0; k < n; k++) { //For getting index of deleted vertex to update the status
            if (ver == names[k]) {
                cs[k] = 3;
                break;
            }
        }
        for (l = 0; l < n; l++) {
            if (a[k][l] == 1 && cs[l] == 1) { 
                insert(names[l]);
                cs[l] = 2;
            }
        }
    }
}

int main() {
    int k;
    printf("Enter the number vertices and edges\n");
    scanf("%d%d", &v, &e);
    getchar();
    names = (char *)malloc(v * sizeof(char));
		printf("Enter the names of vertices\n");
    for (k = 0; k < v; k++)
        scanf(" %c", &names[k]); 
    printf("Enter the adjacency matrix of the graph\n");
	for(int i=0;i<v;i++)
	   for(int j=0;j<v;j++)
	   	scanf("%d",&a[i][j]);
    bfs(a, v);
    free(names);
    return 0;
}

