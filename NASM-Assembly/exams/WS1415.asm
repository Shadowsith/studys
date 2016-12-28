bits 32
global main
extern printf

section .data

test: dd 1,2,3
shift: dd 35
msg: db "%d",10,0

section .text

main:


;countodds:
  mov ebx, DWORD [test]
  mov ecx, DWORD [test+4]
  push ebx
  push ecx
  mov eax,0
  mov edx,[esp]
;next:
 push edx
 push msg
 call printf
 add esp,8
 pop ebx
 pop ecx

 mov eax,DWORD [shift]
 shr eax,2

 push eax
 push msg
 call printf
 add esp,8

;fin:
  
  ret
