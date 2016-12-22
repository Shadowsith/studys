bits 32
global main
extern printf

segment .data ;............

myName: db "Michael Ernst",0
msg:	db 10, "Hello %s, how are you today?",10,10,0

segment .text ;............

main:
     push myName
     push msg
     call printf
     add esp,0
     ret
