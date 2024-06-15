label main
begin
var a
var b
var c
var d
var e
var f
var g
var h
a = 'a'
b = 'B'
e = 1
f = 2
var t0
t0 = e + f
g = t0
var t1
t1 = f * g
h = t1
var t2
t2 = 'C' + e
c = t2
var t3
t3 = a - f
d = t3
var t4
t4 = c + d
var t5
t5 = g - h
var t6
t6 = t4 + t5
c = t6
var t7
t7 = (a > b)
e = t7
var t8
t8 = (e != f)
f = t8
var t9
t9 = (c == d)
g = t9
var t10
t10 = (a < b)
ifz t10 goto L2
actual a
call PRINTN
actual L1
call PRINTN
actual b
call PRINTN
label L2
var t11
t11 = (c != d)
ifz t11 goto L4
actual c
call PRINTN
actual L3
call PRINTN
actual d
call PRINTN
label L4
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

	# var e
	offset:24

	# var f
	offset:28

	# var g
	offset:32

	# var h
	offset:36

	# a = 'a'
	# find free reg1 rdesc[5]
	LOD R5,97

	# b = 'B'
	# find free reg1 rdesc[6]
	LOD R6,66

	# e = 1
	# find free reg1 rdesc[7]
	LOD R7,1

	# f = 2
	# find free reg1 rdesc[8]
	LOD R8,2

	# var t0
	offset:40

	# t0 = e + f
	# find reg1 rdesc[7] whose var == e and m == -1
	STO (R2+24),R7
	# find reg2 rdesc[8] whose var == f and m == -1
	ADD R7,R8

	# g = t0
	# find reg1 rdesc[7] whose var == t0 and m == -1
	STO (R2+40),R7

	# var t1
	offset:44

	# t1 = f * g
	# find reg1 rdesc[8] whose var == f and m == -1
	STO (R2+28),R8
	# find reg2 rdesc[7] whose var == g and m == -1
	MUL R8,R7

	# h = t1
	# find reg1 rdesc[8] whose var == t1 and m == -1
	STO (R2+44),R8

	# var t2
	offset:48

	# t2 = 'C' + e
	# find free reg1 rdesc[9]
	LOD R9,67
	# find free reg2 rdesc[10]
	LOD R10,(R2+24)
	ADD R9,R10

	# c = t2
	# find reg1 rdesc[9] whose var == t2 and m == -1
	STO (R2+48),R9

	# var t3
	offset:52

	# t3 = a - f
	# find reg1 rdesc[5] whose var == a and m == -1
	STO (R2+8),R5
	# find free reg2 rdesc[11]
	LOD R11,(R2+28)
	SUB R5,R11

	# d = t3
	# find reg1 rdesc[5] whose var == t3 and m == -1
	STO (R2+52),R5

	# var t4
	offset:56

	# t4 = c + d
	# find reg1 rdesc[9] whose var == c and m == -1
	STO (R2+16),R9
	# find reg2 rdesc[5] whose var == d and m == -1
	ADD R9,R5

	# var t5
	offset:60

	# t5 = g - h
	# find reg1 rdesc[7] whose var == g and m == -1
	STO (R2+32),R7
	# find reg2 rdesc[8] whose var == h and m == -1
	SUB R7,R8

	# var t6
	offset:64

	# t6 = t4 + t5
	# find reg1 rdesc[9] whose var == t4 and m == -1
	STO (R2+56),R9
	# find reg2 rdesc[7] whose var == t5 and m == -1
	ADD R9,R7

	# c = t6
	# find reg1 rdesc[9] whose var == t6 and m == -1
	STO (R2+64),R9

	# var t7
	offset:68

	# t7 = (a > b)
	LOD R12,(R2+8)
	SUB R12,R6
	TST R12
	LOD R3,R1+40
	JGZ R3
	LOD R12,0
	LOD R3,R1+24
	JMP R3
	LOD R12,1

	# e = t7
	# find free reg1 rdesc[13]
	LOD R13,(R2+68)

	# var t8
	offset:72

	# t8 = (e != f)
	STO (R2+24),R13
	SUB R13,R11
	TST R13
	LOD R3,R1+40
	JEZ R3
	LOD R13,1
	LOD R3,R1+24
	JMP R3
	LOD R13,0

	# f = t8
	# find reg1 rdesc[13] whose var == t8 and m == -1
	STO (R2+72),R13

	# var t9
	offset:76

	# t9 = (c == d)
	STO (R2+16),R9
	SUB R9,R5
	TST R9
	LOD R3,R1+40
	JEZ R3
	LOD R9,0
	LOD R3,R1+24
	JMP R3
	LOD R9,1

	# g = t9
	# find reg1 rdesc[9] whose var == t9 and m == -1
	STO (R2+76),R9

	# var t10
	offset:80

	# t10 = (a < b)
	LOD R10,(R2+8)
	SUB R10,R6
	TST R10
	LOD R3,R1+40
	JLZ R3
	LOD R10,0
	LOD R3,R1+24
	JMP R3
	LOD R10,1

	# ifz t10 goto L2
	STO (R2+20),R5
	STO (R2+12),R6
	STO (R2+60),R7
	STO (R2+36),R8
	STO (R2+32),R9
	STO (R2+80),R10
	STO (R2+68),R12
	STO (R2+28),R13
	TST R10
	JEZ L2

	# actual a
	LOD R11,(R2+8)
	STO (R2+84),R11

	# call PRINTN
	STO (R2+88),R2
	LOD R4,R1+32
	STO (R2+92),R4
	LOD R2,R2+88
	JMP PRINTN

	# actual L1
	LOD R5,L1
	STO (R2+84),R5

	# call PRINTN
	STO (R2+88),R2
	LOD R4,R1+32
	STO (R2+92),R4
	LOD R2,R2+88
	JMP PRINTN

	# actual b
	LOD R5,(R2+12)
	STO (R2+84),R5

	# call PRINTN
	STO (R2+88),R2
	LOD R4,R1+32
	STO (R2+92),R4
	LOD R2,R2+88
	JMP PRINTN

	# label L2
L2:

	# var t11
	offset:84

	# t11 = (c != d)
	LOD R5,(R2+16)
	LOD R6,(R2+20)
	SUB R5,R6
	TST R5
	LOD R3,R1+40
	JEZ R3
	LOD R5,1
	LOD R3,R1+24
	JMP R3
	LOD R5,0

	# ifz t11 goto L4
	STO (R2+84),R5
	TST R5
	JEZ L4

	# actual c
	LOD R7,(R2+16)
	STO (R2+88),R7

	# call PRINTN
	STO (R2+92),R2
	LOD R4,R1+32
	STO (R2+96),R4
	LOD R2,R2+92
	JMP PRINTN

	# actual L3
	LOD R5,L3
	STO (R2+88),R5

	# call PRINTN
	STO (R2+92),R2
	LOD R4,R1+32
	STO (R2+96),R4
	LOD R2,R2+92
	JMP PRINTN

	# actual d
	LOD R5,(R2+20)
	STO (R2+88),R5

	# call PRINTN
	STO (R2+92),R2
	LOD R4,R1+32
	STO (R2+96),R4
	LOD R2,R2+92
	JMP PRINTN

	# label L4
L4:

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

L3:
	DBS 33,61,0
L1:
	DBS 60,0
STATIC:
	DBN 0,0
STACK:
