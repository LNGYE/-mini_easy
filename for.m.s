label main
begin
array w[20]
var a
var b
var c
var d
var e
var f
a = 1
var t0
t0 = a + 1
b = t0
var t1
t1 = b + 1
c = t1
d = 'A'
e = 'C'
var t2
t2 = d + c
f = t2
a = 1
label L1
var t3
t3 = (a <= 10)
ifz t3 goto L2
var t5
t5 = f + 1
f = t5
var t6
t6 = e + d
e = t6
var t4
t4 = a + 1
a = t4
goto L1
label L2
end
	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# array w[20]
	offset:8

	# var a
	offset:88

	# var b
	offset:92

	# var c
	offset:96

	# var d
	offset:100

	# var e
	offset:104

	# var f
	offset:108

	# a = 1
	# find free reg1 rdesc[5]
	LOD R5,1

	# var t0
	offset:112

	# t0 = a + 1
	# find reg1 rdesc[5] whose var == a and m == -1
	STO (R2+88),R5
	# find free reg2 rdesc[6]
	LOD R6,1
	ADD R5,R6

	# b = t0
	# find reg1 rdesc[5] whose var == t0 and m == -1
	STO (R2+112),R5

	# var t1
	offset:116

	# t1 = b + 1
	# find reg1 rdesc[5] whose var == b and m == -1
	STO (R2+92),R5
	# find free reg2 rdesc[7]
	LOD R7,1
	ADD R5,R7

	# c = t1
	# find reg1 rdesc[5] whose var == t1 and m == -1
	STO (R2+116),R5

	# d = 'A'
	# find free reg1 rdesc[8]
	LOD R8,65

	# e = 'C'
	# find free reg1 rdesc[9]
	LOD R9,67

	# var t2
	offset:120

	# t2 = d + c
	# find reg1 rdesc[8] whose var == d and m == -1
	STO (R2+100),R8
	# find reg2 rdesc[5] whose var == c and m == -1
	ADD R8,R5

	# f = t2
	# find reg1 rdesc[8] whose var == t2 and m == -1
	STO (R2+120),R8

	# a = 1
	# find free reg1 rdesc[10]
	LOD R10,1

	# label L1
	STO (R2+96),R5
	STO (R2+108),R8
	STO (R2+104),R9
	STO (R2+88),R10
L1:

	# var t3
	offset:124

	# t3 = (a <= 10)
	LOD R5,(R2+88)
	LOD R6,10
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JGZ R3
	LOD R5,1
	LOD R3,R1+24
	JMP R3
	LOD R5,0

	# ifz t3 goto L2
	STO (R2+124),R5
	TST R5
	JEZ L2

	# var t5
	offset:128

	# t5 = f + 1
	# find free reg1 rdesc[7]
	LOD R7,(R2+108)
	# find free reg2 rdesc[8]
	LOD R8,1
	ADD R7,R8

	# f = t5
	# find reg1 rdesc[7] whose var == t5 and m == -1
	STO (R2+128),R7

	# var t6
	offset:132

	# t6 = e + d
	# find free reg1 rdesc[9]
	LOD R9,(R2+104)
	# find free reg2 rdesc[10]
	LOD R10,(R2+100)
	ADD R9,R10

	# e = t6
	# find reg1 rdesc[9] whose var == t6 and m == -1
	STO (R2+132),R9

	# var t4
	offset:136

	# t4 = a + 1
	# find free reg1 rdesc[11]
	LOD R11,(R2+88)
	# find free reg2 rdesc[12]
	LOD R12,1
	ADD R11,R12

	# a = t4
	# find reg1 rdesc[11] whose var == t4 and m == -1
	STO (R2+136),R11

	# goto L1
	STO (R2+108),R7
	STO (R2+104),R9
	STO (R2+88),R11
	JMP L1

	# label L2
L2:

	# end
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

PRINTN:
	LOD R7,(R2-4) # 789
	LOD R15,R7 # 789 
	DIV R7,10 # 78
	TST R7
	JEZ PRINTDIGIT
	LOD R8,R7 # 78
	MUL R8,10 # 780
	SUB R15,R8 # 9
	STO (R2+8),R15 # local 9 store

	# out 78
	STO (R2+12),R7 # actual 78 push

	# call PRINTN
	STO (R2+16),R2
	LOD R4,R1+32
	STO (R2+20),R4
	LOD R2,R2+16
	JMP PRINTN

	# out 9
	LOD R15,(R2+8) # local 9 

PRINTDIGIT:
	ADD  R15,48
	OUT

	# ret
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

PRINTS:
	LOD R7,(R2-4)

PRINTC:
	LOD R15,(R7)
	DIV R15,16777216
	TST R15
	JEZ PRINTSEND
	OUT
	ADD R7,1
	JMP PRINTC

PRINTSEND:
	# ret
	LOD R3,(R2+4)
	LOD R2,(R2)
	JMP R3

EXIT:
	END

STATIC:
	DBN 0,0
STACK:
