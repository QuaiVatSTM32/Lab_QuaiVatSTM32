#1) Print text
# Variables for main
	.data
request: .asciiz "Please insert 4 input of integers: \n"
f: .asciiz "f = (a + b) - (c - d - 2):\n"
g: .asciiz "\ng = (a + b)*3 - (c + d)*2:\n"
# Main body
.text
main:
	li $v0, 4
	la $a0, request
	syscall
	
#2) Get integer 1
	li $v0, 5 # Get integer mode, $v0 contains integer read
	syscall
	add $s0, $0, $v0 # Move integer from $v0 to register $s0
		
#3) Get integer 2
	li $v0, 5 # Get integer mode, $v0 contains integer read
	syscall
	add $s1, $0, $v0 # Move integer from $v0 to register $s1
	
#4) Get integer 3
	li $v0, 5 # Get integer mode, $v0 contains integer read
	syscall
	add $s2, $0, $v0 # Move integer from $v0 to register $s2
	
#5) Get integer 4
	li $v0, 5 # Get integer mode, $v0 contains integer read
	syscall
	add $s3, $0, $v0 # Move integer from $v0 to register $s3	

# a = s0, b = s1, c = s2, d = s3 

#6.1) f = (a + b) - (c - d - 2)
	li $v0, 4
	la $a0, f
	syscall
#6.2) calculate
	li $v0, 5 # Get integer mode, $v0 contains integer read
	add $t0, $s0, $s1
	sub $t1, $s2, $s3
	sub $t1, $t1, 2
	sub $a0, $t0, $t1
#7) Print f
	li $v0, 1
	syscall
	
#8.1) g = (a + b)*3 - (c + d)*2
	li $v0, 4
	la $a0, g
	syscall
#8.2) calculate g
	li $v0, 5 # Get integer mode, $v0 contains integer read
	add $t0, $s0, $s1	
	mulo $t0, $t0, 3
	add $t1, $s2, $s3
	mulo $t1, $t1, 2
	sub $a0, $t0, $t1
	
#9) Print g
	li $v0, 1
	syscall

