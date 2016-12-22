global pwd
extern printf

section .data

key: db 0xFF              ; i lost they key .. sad story tho
strd: db "%d,",0
nl: db 10,0

section .text

pwd:   
  mov edx, [esp+4]        ; edx auf 1 über Stackpointer 
  mov ecx, [esp+8]        ; esp auf 2 über Stackpointer

schleife:
  mov eax, 0              ; eax = 0
  mov al, byte [edx]      ; Schiebe byte von edx auf al
  xor al, [key]           ; al und key werden verglichen, wo ungleich werden Bits gesetzt, CF und OF werden gelöscht 
  mov byte [edx], al      ; Schiebe al auf byte von edx

  push edx
  push ecx
  push eax
  push strd
  call printf             ; edx, ecx, eax und strd auf Stack+printf
  add esp,4
  pop eax
  pop ecx
  pop edx
  

  INC edx                 ; edx++
  DEC ecx                 ; ecx--
  
  TEST ecx,ecx            ; Operanden werden verglichen, CF und OF werden gelöscht
  JNZ schleife            ; Wenn ecx <-> ecx ungleich sind, springe

  push nl
  call printf
  add esp,4
  ret

          

