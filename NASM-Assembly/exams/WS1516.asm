bits 32
global main
extern printf

section .data

msg: db "%d",10,0
int: dd 0

section .text

main:

  mov ecx,2
  mov eax,1
  mov ebx,1

loop:

  mul ecx
  inc ecx
  add DWORD [int],eax
  inc ebx
  mov eax,ebx
  
  cmp ebx,101
  jne loop

  push eax
  push msg
  call printf
  add  esp,8

  push DWORD [int]
  push msg
  call printf
  add  esp,8

  ret
