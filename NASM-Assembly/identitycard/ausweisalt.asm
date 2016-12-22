bits 32
global main
extern printf
extern scanf

segment .data;---------------------

n: dd 0,0,0,0,0,0,0,0,0                         ; Array für Berechnungen
f: dd  '1','2','3','4','5','6','7','8','9',0    ; Charcterarray zur Eingabe des Strings
a: dd 7,3,1,7,3,1,7,3,1                         ; Array zur Multiplikation

request: db "Geben Sie bitte Ihre Ausweisnummber ein:",10,0
sinput: db "%c%c%c%c%c%c%c%c%c",0                           ; Eingabe des 9-Stelligen Strings (etwas umständlich)
msgar: db  "Arraywert: %d %d %d %d %d %d %d %d %d:",10,0    ; Ausgabe aller Arraywerte von n
msg: db "Die Sicherheitsnummer ist %d",10,0
ascii0: dd 48                                   ; Vermeidung von Magicnumbers bei Berechnungen
ascii9: dd 57                                   ; ""
AsciiAto10: dd 55                               ; ""

segment .text;--------------------

main:

push request        ; Eingabeaufforderung
call printf
add  esp,4

push f+32
push f+28
push f+24
push f+20           ; } f+x --> Alle Character werden eingelesen (etwas umständlich) 
push f+16
push f+12
push f+8
push f+4
push f
push sinput         ; Speichert alle Character im String
call scanf          ; Speichert in sinput
add  esp,40

mov ecx,0

casting:            ; Wandelt Character aus f in Ascii-Integer in n um
mov eax, [f+ecx]
mov [n+ecx], eax    ; Speichert alles im Array n
mov eax,0
add ecx,4
cmp ecx,36          ; 9x läuft die Schleife (40-4 = 36 = 9*4)
jne casting

mov ecx,0           ; Counter ecx zurücksetzten

jmp ascii0to0       ; Nach Casting springt zur Umrechnung der Ascii-Zahlen, Z. 104

forward:

mov ecx,0

securitycalc:            ; Schleife Multipliziert Arraystellen [n+x]*
mov eax,[n+ecx]
mov ebx,[a+ecx]     ; *mit [a+x] 
mul ebx             ; --> eax*ebx = [n+ecx]*[a+ecx] = Wert x*7,y*3,z*1 ... 
mov [n+ecx],eax
add ecx,4
cmp ecx,36
jne securitycalc         ; Springt wenn ecx != 40

mov ecx,0

push DWORD [n+32]
push DWORD [n+28]
push DWORD [n+24]
push DWORD [n+20]   ;} Gibt alle Arraywerte in n aus (Ueberprüfung für mich) 
push DWORD [n+16]
push DWORD [n+12]
push DWORD [n+8]
push DWORD [n+4]
push DWORD [n]
push msgar
call printf
add  esp,40

mov ecx,0

addition:

add eax, [n+ecx]    ; Schleife Addiert alle Einträge im n Array zusammen
add ecx,4
cmp ecx,36          ; Schleife läuft auch 9x (s.o.)
jne addition

mov edx,0
mov ecx,10
div ecx
mov ebx,edx

push ebx
push msg
call printf
add  esp,8

ret

ascii0to0:          ; Schleife konvertiert Asciizahlen (z.b '0' = 48) in Dezimalzahlen ( 0 = 0, 1 = 1...)
mov eax,[n+ecx]
cmp eax,[ascii9]    ; Wenn Wert an Stelle [n+ecx] größer ist als Ascii 9 (57) springt er nach toA zur umkonvertierung
ja  toA
sub eax,[ascii0]    ; Subtrahiert Zahl zu 0-9
mov [n+ecx],eax
add ecx,4
cmp ecx,36
jne ascii0to0
jmp forward         ; Wenn Konvertierung beendet ist springt das Programm ins Hauptprogramm zurück

toA:                ; Zweite Schleife konvertiert Asciizahlen der Buchstaben (z.B. A=65) zu Dezimalzahlen ab A=10, B=11...
mov eax,[n+ecx]
sub eax,[AsciiAto10] ; Subtrahiert Zahl zu 10-35
mov [n+ecx],eax
add ecx,4
cmp ecx,36
jne ascii0to0       ; Springt für nächste Zahl im Array wieder zum Anfang der Konvertierung
jmp forward
