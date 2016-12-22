bits 32
global main
extern printf

section .data ;---------------------

message: db "Hello World -> %d",10,0
myvar:   dd 16,31,17

section .text ;----------------------
main:
     mov ecx,0
     
schleife:
    
     push  ecx
     push DWORD[myvar]
     push  message
     call  printf 
     add   esp,8
     pop   ecx
     add   ecx,1    ;ecx++

     CMP   ecx,4 ;ecx - 4 ?
     JNE   schleife
     ret
