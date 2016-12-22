
global main
extern scanf
extern printf
extern pwd


section .data

mempos_1: db 47,109,76,9,5,76,67,5,92,74,80,5,70,68,75,5,87,64,68,65,5,81
mempos_2: db 77,76,86,5,77,76,66,77,73,92,5,64,75,70                        ;}Codierter Text
mempos_3: db 87,92,85,81,64,65,5,81,64,93,81,5,81,77
mempos_4: db 64,75,5,92,74,80,2,87,64,5,67,76,75,76,86,77,64,65,31,5,105
mempos_5: db 68,86,81,5,107,80,72,71,64,87,31,5,20,22,22,18
mempos_6: db 10,0,0,0,0,0,0,0,0,0,0,0,0,0,0
mempos_7: db "%d",10,0

section .text


main:
  
  push mempos_1
  call printf         ; Vor Entschlüsselung
  add esp,4
 
  push 87             ;?? Denke mal für Entschlüsselung
  push mempos_1
  call pwd            ; Entschlüsselungsverfahren, aus Funktion pwd in otherfile.asm
  add esp,8

  push mempos_1
  call printf         ; Nach Entschlüsslung (wenn alles gefixed ist)
  add esp,4
  ret



