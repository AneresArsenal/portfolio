TITLE Program Assignment 3     (assignment3.asm)

; Author: Serena Tay
; Last Modified: October 18 2018
; OSU email address: tays@oregonstate.edu
; Course number/section: CS271 S400
; Project Number: Program 3     Due Date: Week 5, October 28 Sunday 11:59 PM Pacific USA time zone
; Description: A program that asks users for negative numbers as inputs and display the sum of the integers for that range and the average

INCLUDE Irvine32.inc

.386
.model	flat,stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

MIN = -100

; (insert constant definitions here)

.data
	intro_1			BYTE	"Hello my name is Serena!",	0
	intro_2			BYTE	"Welcome to the Integer Accumulator (aka 271 Assignment Program 3)",	0
	intro_3			BYTE	"Nice to meet you, ",	0
	intro_4			BYTE	"--Program Intro--",	0
	intro_5			BYTE	"**EC1: Program display the number for each user's input.",	0
	intro_6			BYTE	"**EC3: Program pauses output after user enter's their name and changes colour of the text and background.",	0
	intro_7			BYTE	"Results certified by Serena Tay ",	0
	space			BYTE	" ",	0
	userName		BYTE	33	DUP(0)					; string to be entered by user
	userNumber		DWORD	?							; signed integer to be entered by user
	counter			DWORD	1
	compare			DWORD	?
	storedNum		DWORD	0
	divResult		DWORD	?
	remResult		DWORD	?
	remainder		DWORD	?
	prompt_1		BYTE	"What is your name fellow human?",	0
	prompt_2		BYTE	"Please enter a number between -100 to -1. Enter a non-negative number when you are finished to see results.",	0
	prompt_3		BYTE	"Enter number ", 0
	prompt_4		BYTE	" in the sequence: ", 0
	error_1			BYTE	"Uh-oh, the number you inputted is less than -100. Please try again :) ",	0
	error_2			BYTE	"Unfortunately no valid numbers were entered. ",	0
	exitLoopMessage	BYTE	"The number of valid numbers you entered is ",	0
	sumMessage		BYTE	"The sum of the numbers is ", 0
	averageMessage	BYTE	"The rounded average of the numbers is ", 0
	goodbye			BYTE	"Farewell my friend, ",	0
	colour1 = lightBlue + ( black * 16)
	colour2 = lightGreen + (black * 16)
	
; (insert variable definitions here)
.code
main PROC

; (insert executable instructions here)

; introduction
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

; Get user's input
	mov		eax,colour2
	call	SetTextColor
	mov		eax,	1000				; 1 second
	call Delay
	call	CrLF						; carriage return line feed
	

inputAgain:
	mov		edx,	OFFSET	prompt_2
	call	WriteString
	call	CrLF
	mov		edx,	OFFSET	prompt_3
	call	WriteString
	mov		eax,	counter
	call	WriteDec
	mov		edx,	OFFSET	prompt_4
	call	WriteString
	call	ReadInt
	mov		userNumber,		eax
	call	CrLF
	mov		eax,	userNumber
	cmp		eax,	0
	jge		exitMessage
	cmp		eax,	MIN					; jump if number1 is less than number2
	jl		errorMessage1

; if input is valid, sum the numbers up and increment counter, then loop again
	mov		eax,			userNumber
	add		eax,			storedNum
	mov		storedNum,		eax
	mov		eax,			counter
	inc		eax
	mov		counter,		eax
	loop	inputAgain

errorMessage1:
	mov		edx,		OFFSET	error_1	
	call	WriteString
	call	CrLF						; carriage return line feed
	jmp		inputAgain

exitMessage:

; detect if there are any valid inputs and if not, display message and exit, if yes, move on to perform sum and average via normal process 
	mov		eax,		counter
	dec		eax
	mov		counter,	eax
	cmp		eax, 0
	jg		normalProcess
	mov		edx,		OFFSET	error_2
	call	WriteString
	call	CrLF						; carriage return line feed
	jmp		sayGoodbye

	

normalProcess:	
	mov		edx,		OFFSET	exitLoopMessage
	call	WriteString
	mov		eax,		counter
	call	WriteInt
	call	CrLF						; carriage return line feed

; display sum results
	mov		edx,		OFFSET	sumMessage	
	call	WriteString
	mov		eax,		storedNum	; dsplay number 2
	call	WriteInt
	call	CrLF						; carriage return line feed

; calculate average and display result
	mov		eax,		storedNum
	cdq
	mov		ebx,		counter
	idiv	ebx							; perform division
	mov		divResult,	eax
	mov		remResult,	edx				; obtain remainder from edx

	imul	eax,		counter,	-10	; EAX = EDX * 10
	cdq
	mov		ebx,		2
	idiv	ebx
	mov		compare,	eax
	imul	eax,		remResult,	10	; EAX = EDX * 10
	cdq									; EAX -> EDX:EAX
	cmp		eax,		 compare
	jge		printAverage
	dec		divResult					; Add -1

	


printAverage:
	mov		edx,	OFFSET	averageMessage	
	call	WriteString
	mov		eax,			divResult	; dsplay number 2
	call	WriteInt
	call	CrLF						; carriage return line feed



; Say "Goodbye"

sayGoodbye:
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_7
	call	WriteString
	call	CrLF
	mov		edx,	OFFSET	goodbye
	call	WriteString
	mov		edx,	OFFSET	userName
	call	WriteString
	call	CrLF



	exit								; exit to operating system
main ENDP

; (insert additional procedures here)

END main

source: https://stackoverflow.com/questions/9607217/non-recursive-fibonacci-sequence-in-assembly
source: https://stackoverflow.com/questions/36582948/add-new-line-every-5-loops-masm
source: https://stackoverflow.com/questions/38279114/display-integers-in-aligned-columns-in-masm-assembly
source: https://stackoverflow.com/questions/43834912/masm-rounding-integers