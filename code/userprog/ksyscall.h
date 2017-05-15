/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__
#define __USERPROG_KSYSCALL_H__

#include "kernel.h"

#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/file.h>
#include <stdarg.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sched.h>

#include <signal.h>
#include <sys/types.h>
#include <pthread.h>

#define SHELL "/bin/sh"


void SysHalt() {
    kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2) {
    return op1 + op2;
}

int SysWrite(char *buffer, int size, OpenFileId id) {
    return write(id, buffer, (size_t) size);
}

int SysRead(char *buffer, int size, OpenFileId id) {
    return read(id, buffer, (size_t) size);
}

SpaceId SysExec(char *exec_name) {
    pid_t child;
    child = vfork();
    if (child == 0) {
        execl(SHELL, SHELL, "-c", exec_name, NULL);
        _exit(EXIT_FAILURE);
    } else if (child < 0)
        return EPERM;
    return (SpaceId) child;
}

int SysJoin(SpaceId id) {
    return waitpid((pid_t) id, (int *) 0, 0);
}

int SysStrncmp(char *buffer, char *str, int length) {
    return strncmp(buffer, str, (size_t) length);
}

#endif /* ! __USERPROG_KSYSCALL_H__ */
