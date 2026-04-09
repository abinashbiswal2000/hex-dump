#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



int main (int argc, char *argv[]) {

    int numberOfBytes = 4096;
    
    if (argc != 2) {
        printf("Incorrect Number of Arguments.\n");
        return 1;
    }

    char *nameOfFile = argv[1];
    int fileDescriptor = open(nameOfFile, O_RDONLY);

    if (fileDescriptor < 0) {
        printf("File not found.\n");
        return 1;
    }
    
    unsigned char buffer[numberOfBytes];
    ssize_t bytesRead;
    
    while (1) {

        bytesRead = read(fileDescriptor, buffer, numberOfBytes);
        
        if (bytesRead <= 0) {
            break;
        }

        int incrementValue = 0;
        int difference = 0; // bytesRead - i

        for (int i = 0; i < bytesRead; i += incrementValue) {

            difference = bytesRead - i;
            incrementValue = difference < 16 ? difference : 16;

            for (int j = 0; j < incrementValue; j++) {
                printf("%02X ", buffer[i+j]);
            }

            if (incrementValue < 16) {
                int val = 16 - incrementValue;
                for (int j = 0; j < val; j++) {
                    printf("   ");
                }
            }
    
            printf(" | ");
            
            for (int j = 0; j < incrementValue; j++) {
                if (32 <= buffer[i+j] && buffer[i+j] <= 126) {
                    printf("%c", buffer[i+j]);
                } else {
                    printf(".");
                }
            }
            
            printf("\n");

        }

    }
    
    close(fileDescriptor);

    return 0;
}
