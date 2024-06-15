	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
main:

	# begin

	# var a

	# var b

	# var c

	# var d

	# var g

	# b = 1
	LOD R5,1

	# c = 2
	LOD R6,2

	# var t0

	# t0 = b + c
	STO (R2+12),R5
	ADD R5,R6

	# d = t0
	STO (R2+28),R5

	# var t1

	# actual d
	STO (R2+20),R5
	STO (R2+36),R5

	# actual c
	STO (R2+16),R6
	STO (R2+40),R6

	# t1 = call max
	STO (R2+44),R2
	LOD R4,R1+32
	STO (R2+48),R4
	LOD R2,R2+44
	JMP max

	# g = t1
	LOD R5,R4

	# var t2

	# t2 = - b
	LOD R6,0
	LOD R7,(R2+12)
	SUB R6,R7

	# var t3

	# t3 = t2 * c
	STO (R2+36),R6
	LOD R8,(R2+16)
	MUL R6,R8

	# var t4

	# t4 = t3 + d
	STO (R2+40),R6
	LOD R9,(R2+20)
	ADD R6,R9

	# a = t4
	STO (R2+44),R6

	# ifz a goto L1
	STO (R2+24),R5
	STO (R2+8),R6
	TST R6
	JEZ L1

	# var t5

	# t5 = - b
	LOD R10,0
	SUB R10,R7

	# var t6

	# t6 = t5 * c
	STO (R2+48),R10
	MUL R10,R8

	# a = t6
	STO (R2+52),R10

	# label L1
	STO (R2+8),R10
L1:

	# d = 999
	LOD R5,999

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
