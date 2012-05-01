	.file	"fibonacci.src.pp"
	.text
	.align	2
	.global	Fibonacci__int_t
	.type	Fibonacci__int_t, %function
Fibonacci__int_t:
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #40
	@ SETTING ARGUMENTS
	str	r0, [fp, #-52]
	@ START BODY

	@ LEQOP_INT_CINT: _temp_var_0, i, 2
	@ _temp_var_0 = i <= 2;
	ldr r0, [fp, #-52]
	mov r1, #2
	cmp r0, r1
	movgt r0, #0
	movle r0, #1
	str r0, [fp, #-16]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_1, _temp_var_0
	@ _temp_var_1 = _temp_var_0;
	ldr r0, [fp, #-16]
	str r0, [fp, #-20]

	@ IFOP_ANY: L2, _temp_var_1
	@  if (_temp_var_1) goto L2;
	ldr r0, [fp, #-20]
	cmp r0, #0
	bne .L2

	@ GOTOOP_ANY_ANY_LABEL: L3
	@  goto L3;
	beq .L3
	bne .L3

	@ LABELOP_ANY_ANY_LABEL: L2
	@ L2: ;
	
.L2:

	@ ASSIGNOP_INT_ANY_INT: r, i
	@ r = i;
	ldr r0, [fp, #-52]
	str r0, [fp, #-24]

	@ GOTOOP_ANY_ANY_LABEL: L4
	@  goto L4;
	beq .L4
	bne .L4

	@ LABELOP_ANY_ANY_LABEL: L3
	@ L3: ;
	
.L3:

	@ SUBOP_INT_CINT: _temp_var_2, i, 1
	@ _temp_var_2 = i - 1;
	ldr r0, [fp, #-52]
	mov r1, #1
	sub r0, r0, r1
	str r0, [fp, #-28]

	@ PARAMOP_ANY: _temp_var_2
	@  param _temp_var_2
	ldr r0, [fp, #-28]

	@ FUNCTIONOP_ANY: _temp_var_3, Fibonacci__int_t, 1
	@  call _temp_var_3 Fibonacci__int_t 1
	bl Fibonacci__int_t
	str r0, [fp, #-32]

	@ SUBOP_INT_CINT: _temp_var_4, i, 2
	@ _temp_var_4 = i - 2;
	ldr r0, [fp, #-52]
	mov r1, #2
	sub r0, r0, r1
	str r0, [fp, #-36]

	@ PARAMOP_ANY: _temp_var_4
	@  param _temp_var_4
	ldr r0, [fp, #-36]

	@ FUNCTIONOP_ANY: _temp_var_5, Fibonacci__int_t, 1
	@  call _temp_var_5 Fibonacci__int_t 1
	bl Fibonacci__int_t
	str r0, [fp, #-40]

	@ ADDOP_INT_INT: _temp_var_6, _temp_var_3, _temp_var_5
	@ _temp_var_6 = _temp_var_3 + _temp_var_5;
	ldr r0, [fp, #-32]
	ldr r1, [fp, #-40]
	add r0, r1, r0
	str r0, [fp, #-44]

	@ ASSIGNOP_INT_ANY_INT: r, _temp_var_6
	@ r = _temp_var_6;
	ldr r0, [fp, #-44]
	str r0, [fp, #-24]

	@ LABELOP_ANY_ANY_LABEL: L4
	@ L4: ;
	
.L4:

	@ ASSIGNOP_INT_ANY_INT: _temp_var_7, r
	@ _temp_var_7 = r;
	ldr r0, [fp, #-24]
	str r0, [fp, #-48]

	@ RETURNOP_ANY: _temp_var_7
	@  return _temp_var_7;
	ldr r0, [fp, #-48]

	@ END BODY
	sub sp, fp, #12
	ldmfd sp, {fp, sp, pc}
	.size	Fibonacci__int_t, .-Fibonacci__int_t

	.text
	.align	2
	.global	main
	.type	main, %function
main:
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #12
	@ SETTING ARGUMENTS
	@ START BODY

	@ ASSIGNOP_CINT_ANY_INT: _temp_var_8, 10
	@ _temp_var_8 = 10;
	mov r0, #10
	str r0, [fp, #-16]

	@ PARAMOP_ANY: _temp_var_8
	@  param _temp_var_8
	ldr r0, [fp, #-16]

	@ FUNCTIONOP_ANY: _temp_var_9, Fibonacci__int_t, 1
	@  call _temp_var_9 Fibonacci__int_t 1
	bl Fibonacci__int_t
	str r0, [fp, #-20]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_10, _temp_var_9
	@ _temp_var_10 = _temp_var_9;
	ldr r0, [fp, #-20]
	str r0, [fp, #-24]

	@ PRINTOP_ANY_ANY_INT: _temp_var_10
	@  printf("%d\n", _temp_var_10);
	ldr r0, [fp, #-24]
	bl print_int

	@ RETURNOP_ANY: _temp_var_10
	@  return _temp_var_10;
	ldr r0, [fp, #-24]

	@ END BODY
	sub sp, fp, #12
	ldmfd sp, {fp, sp, pc}
	.size	main, .-main


