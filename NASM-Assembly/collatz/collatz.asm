bits 32
global main
extern printf
extern scanf
extern atoi

section .data ;--------------

request: db "Gebe einen Startwert für die Collartzfolge ein:",10,0
n: dd 19
formatin: db "%d",0
formatout:  db "Der Wert ist --> %d",10,0

eventext: db "Wert ist gerade",10,0
oddtext: db "Wert ist ungerade",10,0
endless: db "Endlosschleife mit 4,2,1... ist erreicht, Programm endet aus Performancegründen",10,0
not0:    db "Anfangswert darf nicht 0 sein, bitte erneut Wert eingeben",10,0


section .text ;--------------

main:

;Sagt was du machen sollst

       push request     ; Eingabeaufforderung für Benutzer an Stack
       call printf      
       add esp,4        ; Repariert Stack

;Gebe Startwert für n an

returnZero:             ; Sprung zu erneuter Eingabe wenn scanf=0

       push n           ; n auf Stack
       push formatin    ; n sei für scanf vom Typ Int
       call scanf       ; Eingabe eines Wertes für die Folge
       add esp,8

schleife:
        
      
       mov eax, DWORD [n]   ; Startwert n an eax 
       cmp eax,0            ; Vergleiche eax mit 0    
       jz  notZero          ; Wenn eax=0 --> Springe zu Nachricht, darf nicht null sein
       cmp eax,1            ; Wenn eax=1 --> Gehe zum Programmende wegen drohender Endlosschleife 
       jz forward           ; forwad = Programmende

       mov edx,0         ; edx als Moduloregister auf 0
       mov ecx,2         ; ecx als Divisor-Register
       div ecx           ; eax/ecx = nWert/2
       mov ebx,edx       ; edx --> ebx da sonst Modulowert verloren geht

       cmp ebx,0         ; Vergleiche ebx mit 0
       jz  even          ; Wenn Ergebnis gleich gerade (0)  --> Springe zu even
       cmp ebx,1         ; Vergleiche ebx mit 1
       jz  odd           ; Wenn Ergebnis gleich ungerade (1) --> Springe zu odd


forward:                 ;Programmende
      
       push endless     ; Wenn Wert 1 erreicht ist beende das Programm, weil sonst Endlosschleife
       call printf      ; endless erklärt auch wieso vorzeitig die Folge beendet
       add  esp,4

       ret

notZero:                ; Wenn Eingabe 0 war

       push not0        ; Nachricht, Wert muss !=0 sein
       call printf
       add  esp,4
       jmp  returnZero  ; Sprung zu Eingabe/scanf


even:
       ;push eventext         ; Sagt jedes mal ob gerade (für mich zum Prüfen)
       ;call printf
       ;add esp,4
       
       mov eax, DWORD [n]    ; n auf eax
       mov edx,0
       mov ecx,2             ; Divisor 2 auf ecx
       div ecx               ; = eax/ecx
       mov DWORD [n],eax     ; Speichert Zwischenwert   

       push eax              ; Aktuelle Zahl der Folge
       push formatout
       call printf
       add esp,8

       jmp schleife          ; Springt zum Anfang der Folge


odd:
       ;push oddtext       ; Sagt jedes mal ob ungerade, analog even
       ;call printf
       ;add  esp,4
       
       mov   eax, DWORD [n]     ; n auf eax
       mov   ecx,3              ; ecx = 3
       mul   ecx                ; eax*ecx = n*3
       add   eax,1              ; eax+1   = n+1
       mov   DWORD [n],eax      ; Speichert Zwischenwert
      

       push eax                 ; Sagt Zwischenwert der Folge
       push formatout
       call printf
       add  esp,8

       jmp  schleife            ; Sprung zu Folgenbeginn



