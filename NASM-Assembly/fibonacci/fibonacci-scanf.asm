;=== Programm zur Berechnung der n-ten Fibonacci Zahl===

bits 32         ;Mit 64bit System compiled :) 
global main
extern printf
extern scanf

section .data ;---------------------

request: db "Gebe die n-te Fibonaccizahl an, die du berechnen willst",10,0
message: db "n-te Fibonacci Zahl -> %d",10,0
n: dd 16  
formatin: db "%d",0

section .text ;----------------------
main:
    
     push request   ; Eingabeaufforderung auf Stack
     call printf
     add esp,4      ; Repariert Stack

     push n         ; n auf Stack
     push formatin  ; formatin besagt, dass n ein Integer sei
     call scanf     ; dazu von rechts nach links lesen! scanf("%d", &d);
     add esp,8

     mov ecx,[n]    ; Zähler auf n-te Zahl fixieren (die vorher deklariert wurde
     mov edx,0      ; Additionsregister
     mov eax,0      ; f0=0
     mov ebx,1      ; f1=1
     


schleife:   
     
     add edx,eax    ; edx = eax+edx
     add edx,ebx    ; edx = ebx+edx
     mov eax,ebx    ; von ebx --> eax
     mov ebx,edx    ; von edx --> ebx

     mov edx,0      ; edx auf 0 zurücksetzen

     dec ecx        ; ecx--
     jne  schleife  ; Schleife bis ecx bei 0 (Zeroflag)
    

print:

      push eax      ; eax auf Stack (%d) Paramenter
      push message  ; Nachricht auf Stack (printf)
      call printf   ; printf rückwärts abarbeiten
      add esp,8    ; Stack reparieren (2xpush = 2x4)
      ret           ; return
