;=== Programm zur Berechnung der n-ten Fibonacci Zahl===

bits 32         ;Mit 64bit System compiled :) 
global main
extern printf

section .data ;---------------------

message: db "N-te Fibonacci Zahl -> %d",10,0
n:   dd 16 

section .text ;----------------------
main:
     mov ecx,[n]    ; Zähler auf n-te Zahl fixieren
     mov edx,0      ; Additionsregister
     mov eax,0      ; f0=0
     mov ebx,1      ; f1=1
     
schleife:
     
            ; Edx auf Stack
      
     add edx,eax    ; edx = eax+edx
     add edx,ebx    ; edx = ebx+edx
     mov eax,ebx    ; von ebx --> eax
     mov ebx,edx    ; von edx --> ebx

     mov edx,0        ; edx von Stack

     dec ecx        ; ecx--
     jne  schleife  ; Schleife bis ecx bei 0 (Zeroflag)
    

print:
      push eax      ; eax auf Stack (%d) Paramenter
      push message  ; Nachricht auf Stack (printf)
      call printf   ; printf rückwärts abarbeiten
      add esp,8     ; Stack reparieren (2xpush = 2x4)
      ret           ; return
