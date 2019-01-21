TITLE Program Assignment 1     (assignment1.asm)

; Author: Serena Tay
; Last Modified: October 06 2018
; OSU email address: tays@oregonstate.edu
; Course number/section: CS271 S400
; Project Number: Program 1     Due Date: Week 2, Oct 7 Sunday 11:59 PM Pacific USA time zone
; Description: Program takes two numbers and output the sum, difference, division and multiplication of the two numbers

INCLUDE Irvine32.inc

; (insert constant definitions here)

; (insert variable definitions here)
	.data
	intro_1		BYTE	"Hello my name is Serena!" , 0
	intro_2		BYTE	"Welcome to the Elementary Arithmetic Show (aka Assignment 1)" , 0
	intro_3		BYTE	"**EC1: Prompt user to choose to replay by entering any number but zero or quit by entering zero." , 0
	intro_4		BYTE	"**EC2: Program verifies second number less than first." , 0
	prompt_1	BYTE	"Please give me 2 numbers, and I will show you the sum, difference, product, quotient, and remainder for these two numbers! " ,	0
	prompt_2	BYTE	"The first number must be larger than the second! Please try again :) " ,	0
	prompt_3	BYTE	"Enter any number but 0 if you like to play again! Enter 0 to quit (We will miss u!) " ,	0
	prompt_4	BYTE	"Please enter the first number." ,	0
	prompt_5	BYTE	"Please enter the second number." ,	0
	number1		DWORD	?
	number2		DWORD	?
	userChoice	DWORD	?
	addResult	DWORD	?
	minResult	DWORD	?
	mulResult	DWORD	?
	divResult	DWORD	?
	remResult	DWORD	?
	zero		DWORD	0
	result_1	BYTE	"First number: ",	0
	result_2	BYTE	"Second number: ",	0
	plusSign	BYTE	" + ",	0
	minSign		BYTE	" - ",	0
	mulSign		BYTE	" x ",	0
	divSign		BYTE	" / ",	0
	quotient	BYTE	" remainder ",	0
	float		REAL4	?
	thousand	DWORD	1000
	equal		BYTE	" = ",	0
	goodbye		BYTE	"Thanks for playing, adios! ",	0



.code
main PROC

; program introduction
	mov		edx, OFFSET	intro_1					; move hello message into register
	call	WriteString							; print hello message
	call	CrLF								; carriage return line feed
	mov		edx, OFFSET	intro_2					; move welcome message into register
	call	WriteString							; print message
	call	CrLF								; carriage return line feed

; get the data from user
tryAgain:	
		mov		edx,	OFFSET	prompt_1
		call	WriteString
		call	CrLF							; carriage return line feed
		mov		edx,	OFFSET	prompt_4		;prompt for first number
		call	WriteString
		call	CrLF							; carriage return line feed
		call	ReadInt
		mov		number1,	eax
		mov		edx,	OFFSET	prompt_5		;prompt for second number
		call	WriteString
		call	CrLF							; carriage return line feed
		call	ReadInt
		mov		number2,	eax
		mov		eax,		number1
		cmp		eax,		number2				; jump if number1 is less than number2
		jl		errorMessage
		jmp		validInput

errorMessage:
		mov		edx,	OFFSET	prompt_2
		call	WriteString
		call	CrLF							; carriage return line feed
		mov		edx,	OFFSET	intro_4			; move EC message into register
		call	WriteString						; print message
		call	CrLF							; carriage return line feed
		jmp		tryAgain
	
		

; calculate the required values
validInput:
	mov		eax,	number1
	add		eax,	number2						; perform addition
	mov		addResult,	eax						

	mov		eax,	number1
	sub		eax,	number2						; perform subtraction
	mov		minResult,	eax

	mov		eax,	number1
	mov		ebx,	number2	
	mul		ebx									; perform multiplication
	mov		mulResult,	eax

	mov		eax,	number1
	mov		ebx,	number2
	mov		edx,	0
	div		ebx									; perform division
	mov		divResult,	eax
	mov		remResult,	edx						; obtain remainder from edx



; dsplay the user inputs
	mov		edx,	OFFSET	result_1
	call	WriteString
	mov		eax,			number1				; dsplay number 1
	call	WriteDec
	call	CrLF
	mov		edx,	OFFSET	result_2
	call	WriteString
	mov		eax,			number2				; dsplay number 2
	call	WriteDec
	call	CrLF


; dsplay the add results
	mov		eax,			number1				; dsplay number 1
	call	WriteDec
	mov		edx,	OFFSET	plusSign
	call	WriteString
	mov		eax,			number2				; dsplay number 2
	call	WriteDec
	mov		edx,	OFFSET	equal
	call	WriteString
	mov		eax,			addResult			; dsplay add result
	call	WriteDec
	call	CrLF

; dsplay the minus results
	mov		eax,			number1				; dsplay number 1
	call	WriteDec
	mov		edx,	OFFSET	minSign
	call	WriteString
	mov		eax,			number2				; dsplay number 2
	call	WriteDec
	mov		edx,	OFFSET	equal
	call	WriteString
	mov		eax,			minResult			; dsplay minus result
	call	WriteDec
	call	CrLF

; dsplay the multiple results
	mov		eax,			number1				; dsplay number 1
	call	WriteDec
	mov		edx,	OFFSET	mulSign
	call	WriteString
	mov		eax,			number2				; dsplay number 2
	call	WriteDec
	mov		edx,	OFFSET	equal
	call	WriteString
	mov		eax,			mulResult			; dsplay multiply result
	call	WriteDec
	call	CrLF

; dsplay the division results
	mov		eax,			number1				; dsplay number 1
	call	WriteDec
	mov		edx,	OFFSET	divSign
	call	WriteString
	mov		eax,			number2				; dsplay number 2
	call	WriteDec
	mov		edx,	OFFSET	equal
	call	WriteString
	mov		eax,			divResult			; dsplay division result
	call	WriteDec
	mov		edx,	OFFSET	quotient
	call	WriteString
	mov		eax,			remResult			; dsplay remainder result
	call	WriteDec
	call	CrLF


; attempt to convert remainder to floating point
	FINIT
	FILD	number1
	FILD	number2
	FDIV	ST(1), ST(0)						; divide Num1 by Num2
	FRNDINT
	FSTP	float								; store the result as a REAL4
	mov		eax,			float				; dsplay remainder result in floating point
	call	WriteFloat
	call	CrLF


;source https://stackoverflow.com/questions/23358537/assembly-round-floating-point-number-to-001-precision-toward-%E2%88%9E 
;source https://stackoverflow.com/questions/15934315/how-to-round-a-floating-point-to-the-nearest-001

; prompt user to choose to quit or not

	mov		edx,	OFFSET prompt_3
	call	WriteString
	call	CrLF								; carriage return line feed
	mov		edx, OFFSET	intro_3					; move EC message into register
	call	WriteString							; print message
	call	CrLF								; carriage return line feed
	call	ReadInt
	cmp		eax, zero
	jne		tryAgain

; say goodbye
	mov		edx, OFFSET	goodbye
	call	WriteString
	call	CrLF


	exit										; exit to operating system
	main ENDP


; (insert additional procedures here)

	END main
