TITLE Program Assignment 4     (assignment4.asm)

; Author: Serena Tay
; Last Modified: November 4 2018
; OSU email address: tays@oregonstate.edu
; Course number/section: CS271 S400
; Project Number: Program 4     Due Date: Week 6, November 4 Sunday 11:59 PM Pacific USA time zone
; Description: A program that asks users the number of composite numbers they want to display and the program display that number of composite numbers on screen

INCLUDE Irvine32.inc

.386
.model	flat,stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

MIN = 1
MAX = 400

; (insert constant definitions here)

.data
	intro_1			BYTE	"Hello my name is Serena!",	0
	intro_2			BYTE	"Welcome to the Composite Creator (aka 271 Assignment Program 4)",	0
	intro_3			BYTE	"Nice to meet you, ",	0
	intro_4			BYTE	"--Program Intro--",	0
	intro_5			BYTE	"**EC1: Align all output columns.",	0
	intro_6			BYTE	"**EC3: Check against only prime divisors.",	0
	intro_7			BYTE	"Results certified by Serena Tay ",	0
	space			BYTE	" ",	0
	userName		BYTE	33	DUP(0)					; string to be entered by user
	userCount		DWORD	?							; count to be entered by user, number of composite numbers wanted
	divcounter		DWORD	2							; two integers to divide at first (2 and 3)
	counter			DWORD	0							; two integers to divide at first (2 and 3)
	integer			DWORD	2
	divider			DWORD	3
	arrayLength		DWORD	2
	primeArray		DWORD	400 dup (?)					; to store prime numbers
	prompt_1		BYTE	"What is your name fellow human?",	0
	prompt_2		BYTE	"Please enter a number between 1 and 400 and I will show you composite numbers in sequence of that frequency.",	0
	error_1			BYTE	"Uh-oh, the number you inputted is less than 1. Please try again :) ",	0
	error_2			BYTE	"Yikes, the number you inputted is more than 400. Please try again :) ",	0
	displayMessage	BYTE	"The rounded average of the numbers is ", 0
	goodbye			BYTE	"Farewell my friend, ",	0
	colour1 = lightBlue + ( black * 16)
	colour2 = lightGreen + (black * 16)
	
; (insert variable definitions here)
.code
main PROC

; (insert executable instructions here)

	call	introduction
	call	getUserData
	call	showComposite
	call	farewell

	exit								; exit to operating system
main ENDP

; (insert additional procedures here)

introduction		PROC

	mov		eax,colour1
	call	SetTextColor
	mov		edx,	OFFSET	intro_4		; move welcome message into register
	call	WriteString					; print message
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_5		; move welcome message into register
	call	WriteString					; print message
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_6		; move welcome message into register
	call	WriteString					; print message
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_1		; move hello message into register
	call	WriteString					; print hello message
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_2		; move welcome message into register
	call	WriteString					; print message
	call	CrLF						; carriage return line feed

	; get user name
	mov		edx,	OFFSET	prompt_1	; move into register
	call	WriteString
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	userName	; get user's name
	mov		ecx,	50					; to control length of string
	call	ReadString
	call	CrLF						; carriage return line feed


	; Greet User by name
	mov		edx,	OFFSET	intro_3
	call	WriteString
	mov		edx,	OFFSET	userName
	call	WriteString
	call	CrLF

	ret

introduction		ENDP

getUserData			PROC

; Get user's input
	mov		eax,colour2
	call	SetTextColor
	mov		eax,			1000		; 1 second
	call	Delay
	call	CrLF						; carriage return line feed
	call	validate
	ret

getUserData			ENDP

validate			PROC

validateInput:
	mov		edx,	OFFSET	prompt_2
	call	WriteString
	call	CrLF
	call	ReadInt
	mov		userCount,		eax
	mov		eax,			userCount
	cmp		eax,			MIN			; jump if number1 is less than number2
	jl		errorMessage1
	cmp		eax,			MAX
	jg		errorMessage2
	jmp		validInput

errorMessage1:
	mov		edx,	OFFSET	error_1	
	call	WriteString
	call	CrLF						; carriage return line feed
	jmp		validateInput

errorMessage2:
	mov		edx,	OFFSET	error_2	
	call	WriteString
	call	CrLF						; carriage return line feed
	jmp		validateInput

validInput:
	mov		ecx,			divCounter	; initialize loop counter
	mov		edx,			0	

	ret

validate			ENDP

showComposite		PROC

	mov		esi,	OFFSET	primeArray
	mov		eax,			integer		; int = 2
	mov		[esi],			eax			; move number to primeArray
	inc		eax							; int = 3
	mov		[esi+4],		eax			; move number to primeArray
	inc		eax							; increment integer
	mov		integer,		eax			; save last int
	mov		ecx,			arrayLength

arrayLoop:
	mov		eax,			integer
	cmp		ecx,			arrayLength
	jl		dontPush
	push	eax							; push integer into stack only the first time
	push	ecx

dontPush:
	mov		ebx,			[esi+ecx*4-4]
	mov		edx,			0
	div		ebx
	cmp		edx,			0
	je		notPrime
	loop	arrayLoop

; it is a prime
	pop		ecx
	pop		eax
	mov		ecx,			arrayLength
	mov		[esi+ecx*4],	eax			
	inc		ecx
	mov		arrayLength,	ecx			; update arrayLength as a new prime is found	
	inc		eax							; increment integer
	mov		integer,		eax
	jmp		arrayLoop

notPrime:
	pop		ecx
	pop		eax
	mov		integer,		eax
	call	isComposite
	mov		eax,			integer
	inc		eax	
	mov		integer,		eax
	mov		ecx,			userCount
	dec		ecx							; decrease count as one composite is found
	cmp		ecx,			0
	jne		normalLoop
	ret
	
normalLoop:
	mov		userCount,		ecx			; decrease count by 1
	mov		ecx,			arrayLength
	inc		ecx
	loop	arrayLoop

	ret
showComposite		ENDP



; sub procedure to display composite numbers
isComposite			PROC

	mov		eax,			integer
	call    WriteInt					; writes tab to align text
	
compareCounter:
	mov		eax,			counter
	inc		eax
	mov		counter,		eax
	mov		ebx,			10
	mov		edx,			0
	div		ebx							; perform division
	cmp		edx,			0			; obtain remainder from edx
	je		newLine
	mov     al,				9			; ASCII CHAR 9 =  TAB
    call    WriteChar					; writes tab to align text
	jmp		ignore

newLine:
	call	CrLF						; carriage return line feed

ignore:
	ret
isComposite			ENDP

; Say "Goodbye"
farewell			PROC

	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_7
	call	WriteString
	call	CrLF
	mov		edx,	OFFSET	goodbye
	call	WriteString
	mov		edx,	OFFSET	userName
	call	WriteString
	call	CrLF	

	ret

farewell			ENDP

END main

source: https://stackoverflow.com/questions/9607217/non-recursive-fibonacci-sequence-in-assembly
source: https://stackoverflow.com/questions/36582948/add-new-line-every-5-loops-masm
source: https://stackoverflow.com/questions/38279114/display-integers-in-aligned-columns-in-masm-assembly
source: https://stackoverflow.com/questions/43834912/masm-rounding-integers