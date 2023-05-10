.data
A:  .byte   0x34
B:  .byte  0x00

.code
lb  r1, A(r0)
daddi r1, r1, 16
sb  r1,B(r0)
ddiv    rd, rs, rt
halt