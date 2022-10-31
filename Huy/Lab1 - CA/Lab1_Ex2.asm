#1) Print text
# Variables for main
	.data
request: .asciiz "Please insert 2 input of integers: \n"

# Main body
.text
main:
	li $v0, 4
	la $a0, request
	syscall
	
#2) Get integer 1
	li $v0, 5 # Get integer mode,
	# $v0 contains integer read
	syscall
	add $a0, $0, $v0 # Move integer from $v0 to register $a0
	
#3) Get integer 2
	li $v0, 5 # Get integer mode,
	# $v0 contains integer read
	syscall
	
#4) Sum the integer 2 into 1 and rewrite the resister $a0
	add $a0, $a0, $v0 # Move integer from $v0 to register $a0
	
#5) Print the integer
	li $v0, 1
	syscall 
