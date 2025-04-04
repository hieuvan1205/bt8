#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void runProgram(char *program) {
    char command[100];
    snprintf(command, sizeof(command), "start %s", program);
    system(command);
    printf("Da mo %s thanh cong!\n", program);
}

void closeProgram(char *program) {
    char command[100];
    snprintf(command, sizeof(command), "taskkill /IM %s.exe /F", program);
    system(command);
    printf("Da dong %s thanh cong!\n", program);
}

int main() {
    char choice;
    char program[50];
    
    while (1) {
        printf("Nhap lenh: 1 - Mo chuong trinh, 2 - Dong chuong trinh, 0 - Thoat\n");
        scanf(" %c", &choice);
        getchar();
        
        if (choice == '0')
            break;

        printf("Nhap ten chuong trinh (VD: notepad, calc, chrome,...): ");
        fgets(program, sizeof(program), stdin);
        program[strcspn(program, "\n")] = 0;

        if (choice == '1') {
            runProgram(program);
        } else if (choice == '2') {
            closeProgram(program);
        } else {
            printf("Lenh khong hop le!\n");
        }
    }
    
    return 0;
}