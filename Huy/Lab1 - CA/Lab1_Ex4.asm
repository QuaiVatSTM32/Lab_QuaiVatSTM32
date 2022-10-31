#1) Print text
# Variables for main
.data
request: .asciiz "Please insert 5 input of integers: \n"

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
	
#5) Get integer 5
	li $v0, 5 # Get integer mode, $v0 contains integer read
	syscall
	add $s4, $0, $v0 # Move integer from $v0 to register $s3
			
#6) Print in the reversed order
	#4
	add $a0, $0, $s4
	li $v0, 1
	syscall
	#3
	add $a0, $0, $s3
	li $v0, 1
	syscall
	#2
	add $a0, $0, $s2
	li $v0, 1
	syscall
	#1
	add $a0, $0, $s1
	li $v0, 1
	syscall
	#0
	add $a0, $0, $s0
	li $v0, 1
	syscall


