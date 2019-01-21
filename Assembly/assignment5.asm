TITLE Program Assignment 4     (assignment4.asm)

; Author: Serena Tay
; Last Modified: November 14 2018
; OSU email address: tays@oregonstate.edu
; Course number/section: CS271 S400
; Project Number: Program 5     Due Date: Week 8, November 18 Sunday 11:59 PM Pacific USA time zone
; Description: A program that asks users the number of random integers and sort it from largest to smallest and display the results and median for the integers

INCLUDE Irvine32.inc

.386
.model	flat,stdcall
.stack 4096
ExitProcess proto, dwExitCode:dword

MIN = 10
MAX = 200
LO = 100
HI = 999
FOUR = 4

; (insert constant definitions here)

.data
	intro_1			BYTE	"Hello my name is Serena!",	0
	intro_2			BYTE	"Welcome to the Randomizer (aka 271 Assignment Program 5)",	0
	intro_3			BYTE	"Nice to meet you, ",	0
	intro_4			BYTE	"--Program Intro--",	0
	intro_5			BYTE	"**EC1: Align all output columns.",	0
	intro_6			BYTE	"**EC5: Others??? ",	0
	intro_7			BYTE	"Results certified by Serena Tay ",	0
	oddMessage		BYTE	"Array count is an oddball, median is: ",	0
	evenMessage		BYTE	"Array count is even steven, median is: ",	0
	space			BYTE	" ",	0
	userName		BYTE	33	DUP(0)					; string to be entered by user
	userCount		DWORD	?							; count to be entered by user, number of composite numbers wanted
	counter			DWORD	?						
	arrayLength		DWORD	?
	intArray		DWORD	MAX dup (?)					; to store integers in
	tempNum			DWORD	?
	prompt_1		BYTE	"What is your name fellow human?",	0
	prompt_2		BYTE	"Please enter a number between 10 and 200",	0
	error_1			BYTE	"Uh-oh, the number you inputted is less than 10. Please try again :) ",	0
	error_2			BYTE	"Yikes, the number you inputted is more than 200. Please try again :) ",	0
	unsortedList	BYTE	"The unsorted list is as follow: ", 0
	sortedList		BYTE	"After the sorting hat did its work, the SORTED list is as follow: ", 0
	goodbye			BYTE	"Farewell my friend, ",	0
	colour1 = lightBlue + ( black * 16)
	colour2 = lightGreen + (black * 16)
	
; (insert variable definitions here)
.code
main PROC

; (insert executable instructions here)

	call	introduction
	call	getUserData
	call	Randomize	
	push	userCount					; pass userCount by value
	push	OFFSET	intArray			; pass intArray by reference
	call	fillArray

	push	OFFSET	intArray			; pass intArray by reference
	push	userCount					; pass userCount by value
	push	OFFSET	unsortedList
	call	displayList

	push	OFFSET	intArray			; pass intArray by reference
	push	userCount					; pass userCount by value
	call	sortList

	push	OFFSET	intArray			; pass intArray by reference
	push	userCount					; pass userCount by value
	call	displayMedian

	push	OFFSET	intArray			; pass intArray by reference
	push	userCount					; pass userCount by value
	push	OFFSET	sortedList
	call	displayList

	call	farewell

	exit								; exit to operating system
main ENDP

; (insert additional procedures here)

; Procedure to introduce the program.
; receives: none
; returns: none
; preconditions:  none
; registers changed: edx, ecx

introduction		PROC

	mov		eax,colour1
	call	SetTextColor
	mov		edx,	OFFSET	intro_4		; move welcome message into register
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

; Procedure to get number of random integers from the user.
; Implementation note: This procedure accesses its parameter by setting up a
;	"stack frame" and referencing parameter relative to the top of the 
;	system stack.  
; receives: addresses of parameter on the system stack
; returns: user input value for variable userCount
; preconditions:  none
; registers changed: eax, ebx, edx

getUserData			PROC

; Get user's input
	mov		eax,colour2
	call	SetTextColor
	mov		eax,			1000		; 1 second
	call	Delay
	call	CrLF						; carriage return line feed
	push	OFFSET			userCount	; pass userCount by reference
	call	validate
	ret

getUserData			ENDP

validate			PROC

validateInput:
	mov		edx,	OFFSET	prompt_2
	call	WriteString
	call	CrLF
	call	ReadInt
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
	pop		eax
	jmp		validateInput

validInput:
	push	ebp
	mov		ebp,			esp
	mov		ebx,			[ebp+8]		;address of count in ebx to initiate loop
	mov		[ebx],			eax			;store in global variable
	pop		ebp
	ret		4

validate			ENDP

; Procedure to fill array with random numbers. 
; receives: userCount, intArray
; returns: none
; preconditions:  userCount has been initialized with user input
; registers changed: eax, edx

fillArray			PROC

	push	ebp
	mov		ebp,			esp
	mov		ecx,			[ebp + 12]	; initialize loop counter
	mov		esi,			[ebp + 8]	; move array into esi
	mov		ebx,			0

randomLoop:
	mov		eax,			HI			; 999
	sub		eax,			LO			; 999 - 100 = 899
	inc		eax							; 900
	call	RandomRange					; eax in [0..899]
	add		eax,            LO			; eax in [100..999]
	mov		[esi + ebx*4],	eax
	inc		ebx
	loop	randomLoop

	pop		ebp
	ret		8

fillArray			ENDP

; Procedure to sort numbers from largest to smallest by calling subprocedure exchangeNumber
; receives: userCount, intArray
; returns: none
; preconditions:  userCount has been initialized with user input
; registers changed: eax, ecx, ebx, edx

sortList			PROC
	push	ebp
	mov		ebp,			esp
	mov		ecx,			[ebp + 8]	; initialize loop counter
	mov		esi,			[ebp + 12]	; move array into esi


L1: 
	push	ecx							; save outer loop count
	mov		ebx,			0
	mov		esi,			[ebp + 12]	; move array into esi

L2:
	mov		eax,			[esi+ebx*4]	; get array value
	cmp		[esi+ebx*4+4],	eax			; compare a pair of values
	JL		L3							; jump if [ESI] is greater than [ESI+4], no exchange as it is high to low
	push	ebx
	push	eax
	push	ecx
	mov		eax,			4
	mul		ebx	
	mov		ebx,			eax
	add		ebx,			esi
	push	ebx
	add		ebx,			4
	push	ebx
	call	exchangeNumber
	pop		ecx
	pop		eax
	pop		ebx

L3: 
	inc		ebx
	loop	L2							; inner loop
	pop		ecx							; retrieve outer loop count
	loop	L1							; else repeat outer loop

	pop		ebp
	ret		8

sortList			ENDP


; Sub-procedure to sort numbers from largest to smallest. 
; receives: number1 and number2 to swap
; returns: none
; preconditions:  userCount has been initialized with user input
; registers changed: eax, ecx, ebx

exchangeNumber		PROC
	push	ebp
	mov		ebp,			esp
	mov		ecx,			[ebp + 8]	; first number
	mov		eax,			[ebp + 12]	; move array into esi
	mov		ebx,			[ecx]
	xchg	[eax],			ebx; exchange the pair if it's lower than the next number
	mov		[ecx],			ebx
	pop		ebp
	ret		8
exchangeNumber		ENDP

; Procedure to calculate media
; receives: userCount, intArray
; returns: none
; preconditions:  userCount has been initialized with user input and intArray sorted
; registers changed: eax, ecx, ebx, edx

displayMedian		PROC
	push	ebp
	mov		ebp,			esp
	mov		ecx,			[ebp + 8]	; initialize loop counter
	mov		esi,			[ebp + 12]	; move array into esi

; check even or odd
	push	ecx
	mov		eax,			ecx
	mov		edx,			0
	mov		ebx,			2
	div		ebx
	cmp		edx,			0
	jne		odd

; even number
	mov		edx,	OFFSET	evenMessage
	call	WriteString
	push	eax
	mov		ebx,			eax
	mov		eax,			[esi+ebx*4]	; get array value
	mov		tempNum,		eax	
	pop		eax
	dec		eax
	mov		ebx,			eax
	mov		eax,			[esi+ebx*4]	; get array value
	add		eax,			tempNum
	mov		ebx,			2
	mov		edx,			0
	div		ebx			
	call	writeInt
	call	CrLF
	jmp		endDisplay

odd:
	mov		edx,	OFFSET	oddMessage
	call	WriteString
	mov		ebx,			eax
	mov		eax,			[esi+ebx*4]	; get array value
	call	writeInt
	call	CrLF
	
endDisplay:
	pop		ecx
	pop		ebp
	ret		8

displayMedian			ENDP

;Procedure to display the result. 
;receives: intArray, array count, result
;returns: none
;preconditions:  result has been calculated
;registers changed: eax, ebx, ecx, edx



displayList			PROC
	push	ebp
	mov		ebp,			esp
	mov		edx,			[ebp + 8]
	call	WriteString
	call	CrLF						; carriage return line feed
	mov		ecx,			[ebp + 12]	; initialize loop counter
	mov		esi,			[ebp + 16]	; move array into esi
	mov		ebx,			0
	
compareCounter:
	mov		eax,			[esi + ebx*4]
	inc		ebx
	push	ebx
	call    WriteInt					; writes tab to align text
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
	pop		ebx
	loop	compareCounter
	call	CrLF						; carriage return line feed
	push	eax
	mov		eax,			0
	mov		counter,		eax
	pop		eax
	pop		ebp
	ret		8

displayList			ENDP


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

source: OSU CS271 Lecture 20
source: OSU CS271 Demo 5
source:	Kip Irvine Assembly Language for x86 proccesors 9.5.1 Bubble Sort
source: https://stackoverflow.com/questions/38279114/display-integers-in-aligned-columns-in-masm-assembly
source: https://stackoverflow.com/questions/43834912/masm-rounding-integers
