global main
extern printf, scanf
extern subradd, subrsub
extern subrmul, subrdiv


section .data

begin: db "Please write which simple calculation you want to do:",10,0 
add_o: db "1 for addition",10,0
sub_o: db "2 for subtraction",10,0
mul_o: db "3 for multiply",10,0
div_o: db "4 for division",10,0

msg: db "%s %s %s %s %s",10,0

x: dd 0
a: dd 0
b: dd 0

in: db "%d",0
out: db "%d",10,0


section .text

main:

 push div_o
 push mul_o
 push sub_o
 push add_o
 push begin
 push msg
 call printf
 add  esp,24

 push x
 push in
 call scanf
 add  esp,8
 
 mov eax,[x]
 cmp eax,1
 je  add_ch
 cmp eax,2
 je  sub_ch
 cmp eax,3
 je  mul_ch
 cmp eax,4
 je  div_ch
 
end:
 
 ret

add_ch:
 
 call subradd 

 jmp end

sub_ch:
 
 call subrsub

 jmp end

mul_ch:
 
 call subrmul

 jmp end

div_ch:

 call subrdiv

 jmp end

