; When the computer boots, the BIOS doesn't known how to load the OS
; so it delegates that task to the boot sector. This, the boot sector must be placed
; in a known, standard location. That location is the first of the disk
; (cyclinder 0, head 0, sector 0) and it takes 512 bytes.
; And the BIOS will check that bytes 511 and 512 of the alleged boot sector ares bytes
; 0xAA55
; a binary will by like below
; e9 fd ff 00 00 00 00 00 00 00 00 00 00 00 00 00 
; 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 (x 30)
; 00 00 00 00 00 00 00 00 00 00 00 00 00 00 55 aa

; Infitinte loop (e9 fd ff)
loop:
    jmp loop

; Fill with 510 zeros minus the size of previous code
times 510-($-$$) db 0

; Magic number
dw 0xaa55


