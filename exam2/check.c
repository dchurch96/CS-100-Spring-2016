#include <stdio.h>
#include <string.h>

int palin(char *a){
    int length;
    length = strlen(a);
    double comp = (length/2)+1;
    int i;
    for (i=0; i<comp;i++){
        if (a[i]==a[length-(i+1)]);
        else {
            return 0;
        }
    }
    return 1;
}

int count(char *a, char c){
    int length;
    length = strlen(a);
    int i, count = 0;
    for (i=0; i<length;i++){
        if (a[i]==c) count++;
    }
    return count;
}

int main(int argc, char *argv[]) {
    int i;

    if (argc<3) {
        fprintf(stderr, "Usage: %s char word_1 ... word_n\n", argv[0]);
        return 1;
    }

    printf("Checking palindrome:\n");
    for (i=2; i<argc; i++) { 
        printf("\t\"%s\" - %d\n", argv[i], palin(argv[i]));
    }

    printf("\nCounting occurences:\n");
    for (i=2; i<argc; i++) { 
        printf("\t\"%s\" contains '%c' %d times\n", argv[i], argv[1][0],
                    count(argv[i], argv[1][0]));
    }

    return 0;
}
