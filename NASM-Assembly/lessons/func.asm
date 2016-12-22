bits 32
global main
extern printf

segment .data ;------------

myvar: dd 12,4,16,22
msg: db "Zahl: %d",10,10,0

segment .bss  ;------------

myErg:	resd 1

segment .text ;-------------

main:
  push DWORD [myvar]
  push DWORD [myvar+4]
  call mittelw

  add  esp,8
  push eax
  push msg
  call printf
  add  esp,8
  ret

;---------------------------

  push DWORD [myvar+8]
  push DWORD [myvar+12]
  call mittelw
 
  add  esp,8
  push eax
  push msg
  call printf
  add  esp,8
  ret



mittelw:

  mov eax, DWORD [esp+4]
  add eax, DWORD [esp+8]
  mov edx, 0
  mov ecx, 2
  div ecx
  ret
