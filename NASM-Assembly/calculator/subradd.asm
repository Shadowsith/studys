global subradd
extern printf
extern scanf

section .data

msg: db "Enter two values which you want to sum up",10,0
a: dd 0
b: dd 0
res: dd 0
in: db "%f %f",0
out: db "Ergebnis: %.1f",10,0

section .text

subradd:
  
  push msg
  call printf
  add  esp,4

  push a
  push b
  push in
  call scanf
  add  esp,12

  fld  dword [a]
  fld  dword [b]
  fadd
  fstp dword [res]

  sub  esp,8
  mov  ebx,res
  fld dword [ebx]
  fstp qword [esp]
  push out
  call printf
  add  esp,12

  ret
