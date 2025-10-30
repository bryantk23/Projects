.equ INPUT, 0
.equ OUTPUT, 1
.equ LOW, 0
.equ HIGH, 1
.equ RED_LIGHT_PIN, 21
.equ YELLOW_LIGHT_PIN, 22
.equ GREEN_LIGHT_PIN, 23
.equ RED_CROSS_PIN, 28
.equ GREEN_CROSS_PIN, 27
.equ START_PIN, 7

.text
.global main
main:
	push {lr}
	bl wiringPiSetup
	mov r4, #0
	
	mov r0, #START_PIN
	mov r1, #INPUT
	bl pinMode
	
do_while_not_pressed:
	mov r0, #START_PIN
	bl digitalRead
	cmp r0, #HIGH
	bne do_while_pressed
	b do_while_not_pressed
	
do_while_pressed:
	
	mov r0, #RED_LIGHT_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Starts red traffic light
	mov r0, #RED_LIGHT_PIN
	mov r1, #HIGH
	bl digitalWrite
	
	mov r0, #GREEN_CROSS_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Starts green cross walk light
	mov r0, #GREEN_CROSS_PIN
	mov r1, #HIGH
	bl digitalWrite
	
	ldr r0, =#10000
	bl delay
	
	//Stops red traffic light
	mov r0, #RED_LIGHT_PIN
	mov r1, #LOW
	bl digitalWrite
	
	cmp r4, #5
	bne yellow_and_green_flashing
	
continue_do_while_pressed:
	mov r0, #GREEN_LIGHT_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Starts green cross walk light
	mov r0, #GREEN_LIGHT_PIN
	mov r1, #HIGH
	bl digitalWrite
	
	mov r0, #RED_CROSS_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Starts red cross walk light
	mov r0, #RED_CROSS_PIN
	mov r1, #HIGH
	bl digitalWrite
	
	ldr r0, =#5000
	bl delay
	
	mov r0, #GREEN_LIGHT_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Stops green traffic light
	mov r0, #GREEN_LIGHT_PIN
	mov r1, #LOW
	bl digitalWrite
	
	mov r0, #RED_CROSS_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Stops red cross walk light
	mov r0, #RED_CROSS_PIN
	mov r1, #LOW
	bl digitalWrite
	
	mov r0, #0
	pop {pc}
	
	
yellow_and_green_flashing:

	cmp r4, #5
	beq continue_do_while_pressed
	
	mov r0, #YELLOW_LIGHT_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Starts the yellow traffic light
	mov r0, #YELLOW_LIGHT_PIN
	mov r1, #HIGH
	bl digitalWrite
	
	mov r0, #GREEN_CROSS_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Starts the green cross walk light
	mov r0, #GREEN_CROSS_PIN
	mov r1, #HIGH
	bl digitalWrite
	
	ldr r0, =#1000
	bl delay
	
	mov r0, #YELLOW_LIGHT_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Stops the yellow traffic light
	mov r0, #YELLOW_LIGHT_PIN
	mov r1, #LOW
	bl digitalWrite
	
	mov r0, #GREEN_CROSS_PIN
	mov r1, #OUTPUT
	bl pinMode
	
	//Stops the green cross walk light
	mov r0, #GREEN_CROSS_PIN
	mov r1, #LOW
	bl digitalWrite
	
	ldr r0, =#1000
	bl delay
	
	adds r4, r4, #1
	
	b yellow_and_green_flashing
	
	
