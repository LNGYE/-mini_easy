label main
begin
var a
var b
var c
var d
array w[4]
w[1] = 1
w[2] = 2
var t0
t0 = w[1] + w[2]
c = t0
end
	# head
	LOD R2,STACK
	STO (R2),0
	LOD R4,EXIT
	STO (R2+4),R4

	# label main
	rdesc[5].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[6].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[7].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[8].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[9].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[10].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[11].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[12].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[13].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[14].var:0  modified:0
	spill_one: UNMODIFIED
	rdesc[15].var:0  modified:0
	spill_one: UNMODIFIED
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

	# array w[4]
	offset:24

	# w[1] = 1
	m:1,w:0,pos1:-1,pos2:-1,pos3:0,pos4:0
	find free reg1 rdesc[5]
	LOD R5,1
	UNMODIFIED

	# w[2] = 2
	m:2,w:0,pos1:-1,pos2:-1,pos3:0,pos4:0
	find free reg1 rdesc[6]
	LOD R6,2
	UNMODIFIED

	# var t0
	offset:40

	# t0 = w[1] + w[2]
	m:-1,w:0,pos1:1,pos2:2,pos3:0,pos4:0
	find reg1 rdesc[5] whose var == w and m == 1
	rdesc[5].var:1  modified:1
	STO (R2+28),R5
	find reg2 rdesc[6] whose var == w and m == 2
	ADD R5,R6

	# c = t0
	m:-1,w:0,pos1:-1,pos2:-1,pos3:0,pos4:0
	find reg1 rdesc[5] whose var == t0 and m == -1
	rdesc[5].var:1  modified:1
	STO (R2+40),R5

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
