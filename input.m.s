label main
begin
var a
var b
var c
a = 'a'
b = 'A'
a = 'E'
var t0
t0 = a + 2
b = t0
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

	# a = 'a'
	# find free reg1 rdesc[5]
	LOD R5,97

	# b = 'A'
	# find free reg1 rdesc[6]
	LOD R6,65

	# a = 'E'
	# find free reg1 rdesc[7]
	LOD R7,69

	# var t0
	offset:20

	# t0 = a + 2
	# find reg1 rdesc[7] whose var == a and m == -1
	STO (R2+8),R7
	# find free reg2 rdesc[5]
	LOD R5,2
	ADD R7,R5

	# b = t0
	# find reg1 rdesc[7] whose var == t0 and m == -1
	STO (R2+20),R7

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
