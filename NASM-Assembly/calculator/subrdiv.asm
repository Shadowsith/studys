global subrdiv
extern printf
extern scanf

section .data

a: dd 0
b: dd 0
res: dd 0

msg: db "Gib zwei Werte a,b ein um a/b zu rechnen",10,0
in:  db "%f %f",0
out: db "Ergebnis: %.1f",10,0

section .text

subrdiv:

  push msg
  call printf
  add  esp,4

  push b
  push a
  push in
  call scanf
  add  esp,12

  fld  dword [a]
  fld  dword [b]
  fdiv
  fstp dword [res]

  sub  esp,8
  mov  ebx,res
  fld dword [ebx]
  fstp qword [esp]
  push out
  call printf
  add  esp,12

  ret
