#1) Print text
# Variables for main
	.data
request: .asciiz "Please insert an input of integer: \n"

# Main body
.text
main:
	li $v0, 4
	la $a0, request
	syscall
	
#2) Get integer
	li $v0, 5 # Get integer mode,
	# $v0 contains integer read
	syscall
	add $a0, $0, $v0 # Move integer from $v0 to register $a0
#3) Increase the value
	addi $a0, $a0, 1
#4) Print the integer
	li $v0, 1 # Print integer a0	
	# $v0 contains integer read
	syscall
	add $a0, $0, $v0 # Move integer from $v0 to register $a0

