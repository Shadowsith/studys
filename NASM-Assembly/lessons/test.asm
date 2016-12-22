global main
extern printf

section .data ;---------------------

message: db "Hello World -> %d",10,0


section .text ;----------------------
main:
  push eax
  push message

  call printf
  add  esp,8
  ret



