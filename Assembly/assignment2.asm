TITLE Program Assignment 2     (assignment2.asm)

; Author: Serena Tay
; Last Modified: October 14 2018
; OSU email address: tays@oregonstate.edu
; Course number/section: CS271 S400
; Project Number: Program 2     Due Date: Week 3, October 14 Sunday 11:59 PM Pacific USA time zone
; Description: A program that asks users for the range and display the sequence of Fibonacci in the requested range

INCLUDE Irvine32.inc

.386
.model	flat,stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

MIN = 1
MAX = 46
; (insert constant definitions here)

.data
	intro_1			BYTE	"Hello my name is Serena!",	0
	intro_2			BYTE	"Welcome to the Fibonacci Program (aka 271 Assignment Program 2)",	0
	intro_3			BYTE	"Nice to meet you, ",	0
	intro_4			BYTE	"--Program Intro--",	0
	intro_5			BYTE	"**EC1: Program display the numbers requested in aligned columns.",	0
	intro_6			BYTE	"**EC2: Program pauses output after each row and changes colour of the text and background when printing the sequence.",	0
	intro_7			BYTE	"Results certified by Serena Tay ",	0
	space			BYTE	" ",	0
	userName		BYTE	33	DUP(0)					; string to be entered by user
	userNumber		DWORD	?							; integer to be entered by user
	counter			DWORD	0
	firstNumber		DWORD	0
	secondNumber	DWORD	1
	prompt_1		BYTE	"What is your name fellow human?",	0
	prompt_2		BYTE	"Please enter a number between 1 to 46 and I will show you the Fibonacci numbers for that range.",	0
	error_1			BYTE	"Uh-oh, the number you inputted is less than 1. Please try again :) ",	0
	error_2			BYTE	"Yikes, the number you inputted is more than 46. Please try again :) ",	0
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

; Get user number

tryAgain:
	mov		edx,	OFFSET	prompt_2
	call	WriteString
	call	CrLF
	call	ReadInt
	mov		userNumber,	eax
	mov		eax,		userNumber
	cmp		eax,		MIN				; jump if number1 is less than number2
	jl		errorMessage1
	cmp		eax,		MAX
	jg		errorMessage2
	jmp		validInput

errorMessage1:
	mov		edx,	OFFSET	error_1	
	call	WriteString
	call	CrLF						; carriage return line feed
	jmp		tryAgain

errorMessage2:
	mov		edx,	OFFSET	error_2	
	call	WriteString
	call	CrLF						; carriage return line feed
	jmp		tryAgain


validInput:
	mov		ecx,	userNumber			; initialize loop counter
	mov		edx,	0

fibLoop:
	mov		eax,colour2
	call	SetTextColor
	mov		eax,			secondNumber
	mov		ebx,			firstNumber
	call	WriteInt
	mov		edx,			0
	mov		edx,			eax
	mov		firstNumber,	eax
	add		edx,			ebx
	mov		secondNumber,	edx
	mov		eax,			secondNumber
	
compareCounter:
	mov		eax,			counter
	inc		eax
	mov		counter,		eax
	mov		ebx,			5
	mov		edx,			0
	div		ebx							; perform division
	cmp		edx,			0			; obtain remainder from edx
	je		newLine
	mov     al,				9			; ASCII CHAR 9 =  TAB
    call    WriteChar					; writes tab to align text
	mov		eax,			counter
	cmp		eax,			31
	jge		ignore
	mov     al,				9			; ASCII CHAR 9 =  TAB
    call    WriteChar					; writes tab to align text
	jmp		ignore

newLine:
	mov		eax,			1000		; 1 second
	call Delay
	call	CrLF						; carriage return line feed

ignore:
	loop	fibLoop


; Say "Goodbye"

sayGoodbye:
	call	CrLF						; carriage return line feed
	mov		edx,	OFFSET	intro_7
	call	WriteString
	call	CrLF
	mov		edx,			OFFSET	goodbye
	call	WriteString
	mov		edx,			OFFSET	userName
	call	WriteString
	call	CrLF



	exit	; exit to operating system
main ENDP

; (insert additional procedures here)

END main

source: https://stackoverflow.com/questions/9607217/non-recursive-fibonacci-sequence-in-assembly
source: https://stackoverflow.com/questions/36582948/add-new-line-every-5-loops-masm
source: https://stackoverflow.com/questions/38279114/display-integers-in-aligned-columns-in-masm-assembly