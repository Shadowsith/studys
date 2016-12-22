bits 32
global main
extern printf
extern scanf

segment .data

string: dd "A","B","C",0
stringscan: dd '0','0','0','0','0','0','0','0','0',0
n: dd 0

msg: db "Die Zahlen sind %d",10,0
msgsum: db "Die Gesamtsumme ist: %d",10,0
read: db "%c%c%c%c%c%c%c%c%c",0

segment .text

main:

push stringscan+32
push stringscan+28
push stringscan+24
push stringscan+20
push stringscan+16
push stringscan+12
push stringscan+8
push stringscan+4
push stringscan
push read
call scanf
add  esp,40

loop: 

mov   ecx,0
mov   ecx,ebx
mov   eax, [stringscan+ecx]
cmp   eax,65
jae   tillA
jna   till0

back:

push  eax
push  msg
call  printf
add   esp,8

mov   ebx,0
mov   ebx, DWORD [n]
add   ebx,4
mov   DWORD [n], ebx

mov   eax, DWORD[n]
cmp   eax,36
jne   loop

;jmp   sumup
;sumrdy:

;push  eax
;push  msgsum
;call  printf
;add   esp,8

ret


tillA: 

mov    eax, [stringscan+ecx]
sub    eax,55
mov    [stringscan+ecx],eax
mov    [n+ecx],eax
jmp    back

till0:

mov    eax, [stringscan+ecx]
sub    eax,48
mov    [stringscan+ecx],eax
mov    [n+ecx],eax
jmp    back

;sumup: 

;mov eax,0
;mov ecx,0
;sumloop:

;add eax, [n+ecx]
;add ecx,4
cmp ecx,36
;jne sumloop
;jmp sumrdy
