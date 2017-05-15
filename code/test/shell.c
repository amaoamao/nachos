#include "syscall.h"

int main() {
    SpaceId newProc;
    OpenFileId input = ConsoleInput;
    OpenFileId output = ConsoleOutput;
    char prompt[2], ch, buffer[600];
    int i=0;
    Write("Maomao Shell ver 1.0\n\n\n\n", 25, output);


    prompt[0] = '>';
    prompt[1] = '>';
    for(i=0;i<60;++i){
        buffer[i]='*';

    }
       

    while (1) {
        Write(prompt, 2, output);
        i = 0;
        do {
            Read(&buffer[i], 1, input);
        } while (buffer[i++] != '\n');
        buffer[--i] = '\0';
        if ((i == 4) && (Strncmp(&buffer[0], "exit", 4) == 0)) {
            Halt();
        }
        if (i > 0) {
            newProc = Exec(buffer);
            Join(newProc);
        }
    }
}

/*
int main() {
    SpaceId newProc;
    OpenFileId input = ConsoleInput;
    OpenFileId output = ConsoleOutput;
    char prompt[2], ch, buffer[600];
    int i=0;
    Write("Maomao Shell ver 1.0\n", 22, output);


    prompt[0] = '>';
    prompt[1] = '>';
    for(i=0;i<60;++i){
        buffer[i]='*';

    }
       

    while (1) {
        Write(prompt, 2, output);
        i = 0;
        do {
            Read(&buffer[i], 1, input);
        } while (buffer[i++] != '\n');
        buffer[--i] = '\0';
        if ((i == 4) && (Strncmp(&buffer[0], "exit", 4) == 0)) {
            Halt();
        }
        if (i > 0) {
            newProc = Exec(buffer);
            Join(newProc);
        }
    }
}
*/
