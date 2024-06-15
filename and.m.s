label main
begin
var a
var b
var c
var d
array w[2]
w[0] = 1
w[1] = 2
b = 1
c = 2
a = 1
d = 0
var t0
t0 = (a == w[0])
var t1
t1 = (c == w[1])
var t2
t2 = (t0 && t1)
ifz t2 goto L1
a = 4
label L1
var t3
t3 = (b == w[0])
var t4
t4 = (a == w[1])
var t5
t5 = (t3 || t4)
ifz t5 goto L2
a = 5
label L2
var t6
t6 = ! d
ifz t6 goto L3
a = 6
label L3
end
	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a
	offset:8

	# var b
	offset:12

	# var c
	offset:16

	# var d
	offset:20

	# array w[2]
	offset:24

	# w[0] = 1
	# find free reg1 rdesc[5]
	LOD R5,1

	# w[1] = 2
	# find free reg1 rdesc[6]
	LOD R6,2

	# b = 1
	# find free reg1 rdesc[7]
	LOD R7,1

	# c = 2
	# find free reg1 rdesc[8]
	LOD R8,2

	# a = 1
	# find free reg1 rdesc[9]
	LOD R9,1

	# d = 0
	# find free reg1 rdesc[10]
	LOD R10,0

	# var t0
	offset:32

	# t0 = (a == w[0])
	STO (R2+8),R9
	SUB R9,R5
	TST R9
	LOD R3,R1+40
	JEZ R3
	LOD R9,0
	LOD R3,R1+24
	JMP R3
	LOD R9,1

	# var t1
	offset:36

	# t1 = (c == w[1])
	STO (R2+16),R8
	SUB R8,R5
	TST R8
	LOD R3,R1+40
	JEZ R3
	LOD R8,0
	LOD R3,R1+24
	JMP R3
	LOD R8,1

	# var t2
	offset:40

	# t2 = (t0 && t1)

	# ifz t2 goto L1
	STO (R2+24),R5
	STO (R2+28),R6
	STO (R2+12),R7
	STO (R2+36),R8
	STO (R2+32),R9
	STO (R2+20),R10
	LOD R11,(R2+40)
	TST R11
	JEZ L1

	# a = 4
	# find free reg1 rdesc[12]
	LOD R12,4

	# label L1
	STO (R2+8),R12
L1:

	# var t3
	offset:44

	# t3 = (b == w[0])
	LOD R5,(R2+12)
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JEZ R3
	LOD R5,0
	LOD R3,R1+24
	JMP R3
	LOD R5,1

	# var t4
	offset:48

	# t4 = (a == w[1])
	LOD R7,(R2+8)
	SUB R7,R6
	TST R7
	LOD R3,R1+40
	JEZ R3
	LOD R7,0
	LOD R3,R1+24
	JMP R3
	LOD R7,1

	# var t5
	offset:52

	# t5 = (t3 || t4)

	# ifz t5 goto L2
	STO (R2+44),R5
	STO (R2+48),R7
	LOD R8,(R2+52)
	TST R8
	JEZ L2

	# a = 5
	# find free reg1 rdesc[9]
	LOD R9,5

	# label L2
	STO (R2+8),R9
L2:

	# var t6
	offset:56

	# t6 = ! d

	# ifz t6 goto L3
	LOD R5,(R2+56)
	TST R5
	JEZ L3

	# a = 6
	# find free reg1 rdesc[6]
	LOD R6,6

	# label L3
	STO (R2+8),R6
L3:

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
