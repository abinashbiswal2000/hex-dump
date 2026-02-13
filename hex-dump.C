#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



int main (int argc, char * argv[]) {
    
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
    
    unsigned char buffer[16];
    ssize_t bytesRead;
    
    while (1) {

        bytesRead = read(fileDescriptor, buffer, 16);
        
        if (bytesRead <= 0) {
            break;
        }

        for (int i = 0; i < 16; i++) {
            if (i < bytesRead) {
                printf("%02X ", buffer[i]);
            } else {
                printf("   ");
            }
        }

        printf(" | ");

        for (int i = 0; i < 16; i++) {
            if (i < bytesRead && 32 <= buffer[i] && buffer[i] <= 126) {
                printf("%c", buffer[i]);
            } else {
                printf(".");
            }
        }

        printf("\n");

    }
    
    close(fileDescriptor);

    return 0;
}