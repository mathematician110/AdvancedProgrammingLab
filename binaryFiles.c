#include <stdio.h>
#include <stdlib.h>

struct customer {
    int id;
    char name[150];
    unsigned long int balance;
};

struct customer *readFromFile() {
    FILE *file = fopen("customer.dat", "rb");
    int size;
    fread(&size, sizeof(int), 1, file);
    struct customer *array = calloc(size, sizeof(struct customer));
    fread(array, sizeof(struct customer), size, file);
    fclose(file);
    return array;
}

void writeToFile(struct customer *array, unsigned int size) {
    FILE *file = fopen("customer.dat", "wb");
    fwrite(&size, sizeof(int), 1, file);
    fwrite(array, sizeof(struct customer), size, file);
    fclose(file);
}

int main() {
    struct customer arr[3] = {
            (struct customer){0, "John", 56}, // This is how you instantly initialize a struct!
            (struct customer){1, "Math", 43},
            (struct customer){2, "Seth", 964},
    };
    writeToFile(arr, 3);
    struct customer *read = readFromFile();
    if (read != NULL) {
        int i;
        for (i = 0; i < 3; i++) { // We should have somehow passed 3 in readFromFile() but just to simplify things out, we didn't ask for it
            printf("Customer #%d: %s [Balance: %d]\n", read[i].id, read[i].name, read[i].balance);
        }
    } else {
        printf("%s\n", "Unable to open the file.");
    }
    return 0;
}