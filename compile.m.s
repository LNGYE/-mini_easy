label main
begin
var a
var b
var c
var d
array w[4]
ptr *p
ptr *q
p = &a
q = w
a = 1
b = a
w[0] = 1
w[1] = w[0]
c = w[0]
d = *p
w[2] = *q
w[3] = *(q + 1)
*p = 2
*p = b
*p = w[1]
*p = *q
*p = *(q + 1)
w[0] = 0
w[1] = 1
w[2] = 2
w[3] = 3
*(q + 1) = *q
*(q + 2) = *(q + 1)
*(q + 3) = *(q + 2)
var t0
t0 = b + c
a = t0
var t1
t1 = c + w[0]
b = t1
var t2
t2 = w[1] + w[2]
c = t2
var t3
t3 = *p + w[0]
d = t3
var t4
t4 = *p + *q
a = t4
var t5
t5 = *(q + 1) + w[2]
b = t5
var t6
t6 = *(q + 2) + *(q + 3)
c = t6
var t7
t7 = 1 + a
w[0] = t7
var t8
t8 = w[1] + w[2]
w[0] = t8
var t9
t9 = w[1] + b
w[0] = t9
var t10
t10 = *p + *q
w[1] = t10
var t11
t11 = *p + *(q + 2)
w[1] = t11
var t12
t12 = *(q + 2) + *(q + 3)
w[1] = t12
var t13
t13 = 1 + a
*p = t13
var t14
t14 = w[1] + w[2]
*p = t14
var t15
t15 = w[1] + b
*p = t15
var t16
t16 = *q + 1
*p = t16
var t17
t17 = *(q + 2) + *(q + 3)
*p = t17
var t18
t18 = 1 + a
*(q + 1) = t18
var t19
t19 = w[0] + w[2]
*(q + 1) = t19
var t20
t20 = w[0] + b
*(q + 1) = t20
var t21
t21 = *q + 1
*(q + 1) = t21
var t22
t22 = *(q + 2) + *(q + 3)
*(q + 1) = t22
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

	# array w[4]
	offset:24

	# ptr *p
	offset:40

	# ptr *q
	offset:44

	# p = &a

	# q = w

	# a = 1
	# find free reg1 rdesc[7]
	LOD R7,1

	# b = a
	# find reg1 rdesc[7] whose var == a and m == -1
	STO (R2+8),R7

	# w[0] = 1
	# find free reg1 rdesc[8]
	LOD R8,1

	# w[1] = w[0]
	# find reg1 rdesc[8] whose var == w and m == 0
	STO (R2+24),R8

	# c = w[0]
	# find free reg1 rdesc[9]
	LOD R9,(R2+24)

	# d = *p
	# find free reg1 rdesc[10]
	LOD R10,(R2+8)

	# w[2] = *q
	# find free reg1 rdesc[11]
	LOD R11,(R2+24)

	# w[3] = *(q + 1)
	# find reg1 rdesc[8] whose var == w and m == 1
	STO (R2+28),R8

	# *p = 2
	# find free reg1 rdesc[12]
	LOD R12,2

	# *p = b
	# find reg1 rdesc[7] whose var == b and m == -1
	STO (R2+12),R7

	# *p = w[1]
	# find free reg1 rdesc[12]
	LOD R12,(R2+28)

	# *p = *q
	# find free reg1 rdesc[7]
	LOD R7,(R2+24)

	# *p = *(q + 1)
	# find free reg1 rdesc[12]
	LOD R12,(R2+28)

	# w[0] = 0
	# find free reg1 rdesc[7]
	LOD R7,0

	# w[1] = 1
	# find free reg1 rdesc[13]
	LOD R13,1

	# w[2] = 2
	# find free reg1 rdesc[14]
	LOD R14,2

	# w[3] = 3
	# find free reg1 rdesc[11]
	LOD R11,3

	# *(q + 1) = *q
	# find reg1 rdesc[7] whose var == w and m == 0
	STO (R2+24),R7

	# *(q + 2) = *(q + 1)
	# find reg1 rdesc[7] whose var == w and m == 1
	STO (R2+28),R7

	# *(q + 3) = *(q + 2)
	# find reg1 rdesc[7] whose var == w and m == 2
	STO (R2+32),R7

	# var t0
	offset:48

	# t0 = b + c
	# find free reg1 rdesc[8]
	LOD R8,(R2+12)
	# find reg2 rdesc[9] whose var == c and m == -1
	ADD R8,R9

	# a = t0
	# find reg1 rdesc[8] whose var == t0 and m == -1
	STO (R2+48),R8

	# var t1
	offset:52

	# t1 = c + w[0]
	# find reg1 rdesc[9] whose var == c and m == -1
	STO (R2+16),R9
	# find free reg2 rdesc[11]
	LOD R11,(R2+24)
	ADD R9,R11

	# b = t1
	# find reg1 rdesc[9] whose var == t1 and m == -1
	STO (R2+52),R9

	# var t2
	offset:56

	# t2 = w[1] + w[2]
	# find free reg1 rdesc[12]
	LOD R12,(R2+28)
	# find free reg2 rdesc[13]
	LOD R13,(R2+32)
	ADD R12,R13

	# c = t2
	# find reg1 rdesc[12] whose var == t2 and m == -1
	STO (R2+56),R12

	# var t3
	offset:60

	# t3 = *p + w[0]
	# find reg1 rdesc[8] whose var == a and m == -1
	STO (R2+8),R8
	# find reg2 rdesc[11] whose var == w and m == 0
	ADD R8,R11

	# d = t3
	# find reg1 rdesc[8] whose var == t3 and m == -1
	STO (R2+60),R8

	# var t4
	offset:64

	# t4 = *p + *q
	# find free reg1 rdesc[10]
	LOD R10,(R2+8)
	# find reg2 rdesc[11] whose var == w and m == 0
	ADD R10,R11

	# a = t4
	# find reg1 rdesc[10] whose var == t4 and m == -1
	STO (R2+64),R10

	# var t5
	offset:68

	# t5 = *(q + 1) + w[2]
	# find free reg1 rdesc[14]
	LOD R14,(R2+28)
	# find reg2 rdesc[13] whose var == w and m == 2
	ADD R14,R13

	# b = t5
	# find reg1 rdesc[14] whose var == t5 and m == -1
	STO (R2+68),R14

	# var t6
	offset:72

	# t6 = *(q + 2) + *(q + 3)
	# find reg1 rdesc[13] whose var == w and m == 2
	# find reg2 rdesc[7] whose var == w and m == 3
	ADD R13,R7

	# c = t6
	# find reg1 rdesc[13] whose var == t6 and m == -1
	STO (R2+72),R13

	# var t7
	offset:76

	# t7 = 1 + a
	# find free reg1 rdesc[9]
	LOD R9,1
	# find reg2 rdesc[10] whose var == a and m == -1
	ADD R9,R10

	# w[0] = t7
	# find reg1 rdesc[9] whose var == t7 and m == -1
	STO (R2+76),R9

	# var t8
	offset:80

	# t8 = w[1] + w[2]
	# find free reg1 rdesc[11]
	LOD R11,(R2+28)
	# find free reg2 rdesc[12]
	LOD R12,(R2+32)
	ADD R11,R12

	# w[0] = t8
	# find reg1 rdesc[11] whose var == t8 and m == -1
	STO (R2+80),R11

	# var t9
	offset:84

	# t9 = w[1] + b
	# find free reg1 rdesc[9]
	LOD R9,(R2+28)
	# find reg2 rdesc[14] whose var == b and m == -1
	ADD R9,R14

	# w[0] = t9
	# find reg1 rdesc[9] whose var == t9 and m == -1
	STO (R2+84),R9

	# var t10
	offset:88

	# t10 = *p + *q
	# find reg1 rdesc[10] whose var == a and m == -1
	STO (R2+8),R10
	# find reg2 rdesc[9] whose var == w and m == 0
	ADD R10,R9

	# w[1] = t10
	# find reg1 rdesc[10] whose var == t10 and m == -1
	STO (R2+88),R10

	# var t11
	offset:92

	# t11 = *p + *(q + 2)
	# find free reg1 rdesc[11]
	LOD R11,(R2+8)
	# find reg2 rdesc[12] whose var == w and m == 2
	ADD R11,R12

	# w[1] = t11
	# find reg1 rdesc[11] whose var == t11 and m == -1
	STO (R2+92),R11

	# var t12
	offset:96

	# t12 = *(q + 2) + *(q + 3)
	# find reg1 rdesc[12] whose var == w and m == 2
	# find reg2 rdesc[7] whose var == w and m == 3
	ADD R12,R7

	# w[1] = t12
	# find reg1 rdesc[12] whose var == t12 and m == -1
	STO (R2+96),R12

	# var t13
	offset:100

	# t13 = 1 + a
	# find free reg1 rdesc[10]
	LOD R10,1
	# find free reg2 rdesc[11]
	LOD R11,(R2+8)
	ADD R10,R11

	# *p = t13
	# find reg1 rdesc[10] whose var == t13 and m == -1
	STO (R2+100),R10

	# var t14
	offset:104

	# t14 = w[1] + w[2]
	# find reg1 rdesc[12] whose var == w and m == 1
	STO (R2+28),R12
	# find free reg2 rdesc[11]
	LOD R11,(R2+32)
	ADD R12,R11

	# *p = t14
	# find reg1 rdesc[12] whose var == t14 and m == -1
	STO (R2+104),R12

	# var t15
	offset:108

	# t15 = w[1] + b
	# find free reg1 rdesc[10]
	LOD R10,(R2+28)
	# find reg2 rdesc[14] whose var == b and m == -1
	ADD R10,R14

	# *p = t15
	# find reg1 rdesc[10] whose var == t15 and m == -1
	STO (R2+108),R10

	# var t16
	offset:112

	# t16 = *q + 1
	# find reg1 rdesc[9] whose var == w and m == 0
	STO (R2+24),R9
	# find free reg2 rdesc[12]
	LOD R12,1
	ADD R9,R12

	# *p = t16
	# find reg1 rdesc[9] whose var == t16 and m == -1
	STO (R2+112),R9

	# var t17
	offset:116

	# t17 = *(q + 2) + *(q + 3)
	# find reg1 rdesc[11] whose var == w and m == 2
	# find reg2 rdesc[7] whose var == w and m == 3
	ADD R11,R7

	# *p = t17
	# find reg1 rdesc[11] whose var == t17 and m == -1
	STO (R2+116),R11

	# var t18
	offset:120

	# t18 = 1 + a
	# find free reg1 rdesc[9]
	LOD R9,1
	# find reg2 rdesc[11] whose var == a and m == -1
	ADD R9,R11

	# *(q + 1) = t18
	# find reg1 rdesc[9] whose var == t18 and m == -1
	STO (R2+120),R9

	# var t19
	offset:124

	# t19 = w[0] + w[2]
	# find free reg1 rdesc[10]
	LOD R10,(R2+24)
	# find free reg2 rdesc[15]
	LOD R15,(R2+32)
	ADD R10,R15

	# *(q + 1) = t19
	# find reg1 rdesc[10] whose var == t19 and m == -1
	STO (R2+124),R10

	# var t20
	offset:128

	# t20 = w[0] + b
	# find free reg1 rdesc[9]
	LOD R9,(R2+24)
	# find reg2 rdesc[14] whose var == b and m == -1
	ADD R9,R14

	# *(q + 1) = t20
	# find reg1 rdesc[9] whose var == t20 and m == -1
	STO (R2+128),R9

	# var t21
	offset:132

	# t21 = *q + 1
	# find free reg1 rdesc[10]
	LOD R10,(R2+24)
	LOD R12,1
	ADD R10,R12

	# *(q + 1) = t21
	# find reg1 rdesc[10] whose var == t21 and m == -1
	STO (R2+132),R10

	# var t22
	offset:136

	# t22 = *(q + 2) + *(q + 3)
	# find reg1 rdesc[15] whose var == w and m == 2
	# find reg2 rdesc[7] whose var == w and m == 3
	ADD R15,R7

	# *(q + 1) = t22
	# find reg1 rdesc[15] whose var == t22 and m == -1
	STO (R2+136),R15

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
