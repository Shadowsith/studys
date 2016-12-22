global pwd
extern printf

section .data   ;----------------

key: db 0xFF              ; i lost they key .. sad story tho
strd: db "%d,",0
nl: db 10,0

section .text   ;----------------

pwd:   
  mov edx, [esp+4]      ; Schreibt Wert von eins über Stackpointer auf edx 
  mov ecx, [esp+8]      ; Schreibt Wert von zwei über Stackpointer auf ecx 

schleife:
  mov eax, 0            ; eax 0
  mov al, byte [edx]    ; kopiert 8bit von edx nach al  
  xor al, [key]         ; al und [key]  werden verglichen und Bits gesetzt, wo ungleich. CF und OF werden gelöscht.
  mov byte [edx], al    ; al in byte an der Stelle [edx]

  push edx 
  push ecx
  push eax
  push strd
  call printf
  add esp,4
  pop eax
  pop ecx
  pop edx
  

  INC edx               ; edx++
  DEC ecx               ; ecx--
  
  TEST ecx,ecx          ; Operanden werden verglichen (AND). CF und OF werden gelöscht.
  JNZ schleife          ; Jump not Zero

  push nl
  call printf
  add esp,4
  ret
