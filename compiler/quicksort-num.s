	.file	"quicksort-num.src.pp"
	.text
	.align	2
	.global	Partition__int_array_t__int_t__int_t
	.type	Partition__int_array_t__int_t__int_t, %function
Partition__int_array_t__int_t__int_t:
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #96
	@ SETTING ARGUMENTS
	str	r0, [fp, #-100]
	str	r1, [fp, #-104]
	str	r2, [fp, #-108]
	@ START BODY

	@ ASSIGNOP_INT_ANY_INT: _temp_var_8, r
	@ _temp_var_8 = r;
	ldr r0, [fp, #-108]
	str r0, [fp, #-16]

	@ RARRAYOP_IARR_INT_INT: _temp_var_9, A, _temp_var_8
	@ _temp_var_9 = A->data[_temp_var_8];
	add r0, fp, #-20
	ldr r1, [fp, #-100]
	ldr r2, [fp, #-16]
	bl get_element_int_array

	@ ASSIGNOP_INT_ANY_INT: x, _temp_var_9
	@ x = _temp_var_9;
	ldr r0, [fp, #-20]
	str r0, [fp, #-24]

	@ SUBOP_INT_CINT: _temp_var_10, p, 1
	@ _temp_var_10 = p - 1;
	ldr r0, [fp, #-104]
	mov r1, #1
	sub r0, r0, r1
	str r0, [fp, #-28]

	@ ASSIGNOP_INT_ANY_INT: i, _temp_var_10
	@ i = _temp_var_10;
	ldr r0, [fp, #-28]
	str r0, [fp, #-32]

	@ ASSIGNOP_INT_ANY_INT: j, p
	@ j = p;
	ldr r0, [fp, #-104]
	str r0, [fp, #-36]

	@ LABELOP_ANY_ANY_LABEL: L7
	@ L7: ;
	
.L7:

	@ LESSOP_INT_INT: _temp_var_11, j, r
	@ _temp_var_11 = j < r;
	ldr r0, [fp, #-36]
	ldr r1, [fp, #-108]
	cmp r0, r1
	movge r0, #0
	movlt r0, #1
	str r0, [fp, #-40]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_12, _temp_var_11
	@ _temp_var_12 = _temp_var_11;
	ldr r0, [fp, #-40]
	str r0, [fp, #-44]

	@ IFOP_ANY: L8, _temp_var_12
	@  if (_temp_var_12) goto L8;
	ldr r0, [fp, #-44]
	cmp r0, #0
	bne .L8

	@ GOTOOP_ANY_ANY_LABEL: L9
	@  goto L9;
	beq .L9
	bne .L9

	@ LABELOP_ANY_ANY_LABEL: L8
	@ L8: ;
	
.L8:

	@ ASSIGNOP_INT_ANY_INT: _temp_var_13, j
	@ _temp_var_13 = j;
	ldr r0, [fp, #-36]
	str r0, [fp, #-48]

	@ RARRAYOP_IARR_INT_INT: _temp_var_14, A, _temp_var_13
	@ _temp_var_14 = A->data[_temp_var_13];
	add r0, fp, #-52
	ldr r1, [fp, #-100]
	ldr r2, [fp, #-48]
	bl get_element_int_array

	@ LEQOP_INT_INT: _temp_var_15, _temp_var_14, x
	@ _temp_var_15 = _temp_var_14 <= x;
	ldr r0, [fp, #-52]
	ldr r1, [fp, #-24]
	cmp r0, r1
	movgt r0, #0
	movle r0, #1
	str r0, [fp, #-56]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_16, _temp_var_15
	@ _temp_var_16 = _temp_var_15;
	ldr r0, [fp, #-56]
	str r0, [fp, #-60]

	@ IFOP_ANY: L10, _temp_var_16
	@  if (_temp_var_16) goto L10;
	ldr r0, [fp, #-60]
	cmp r0, #0
	bne .L10

	@ GOTOOP_ANY_ANY_LABEL: L11
	@  goto L11;
	beq .L11
	bne .L11

	@ LABELOP_ANY_ANY_LABEL: L10
	@ L10: ;
	
.L10:

	@ ADDOP_INT_CINT: _temp_var_17, i, 1
	@ _temp_var_17 = i + 1;
	ldr r0, [fp, #-32]
	mov r1, #1
	add r0, r1, r0
	str r0, [fp, #-64]

	@ ASSIGNOP_INT_ANY_INT: i, _temp_var_17
	@ i = _temp_var_17;
	ldr r0, [fp, #-64]
	str r0, [fp, #-32]

	@ PARAMOP_ANY: A
	@  param A
	ldr r0, [fp, #-100]

	@ PARAMOP_ANY: i
	@  param i
	ldr r1, [fp, #-32]

	@ PARAMOP_ANY: j
	@  param j
	ldr r2, [fp, #-36]

	@ FUNCTIONOP_ANY: _temp_var_18, exchange__int_array_t__int_t__int_t, 3
	@  call _temp_var_18 exchange__int_array_t__int_t__int_t 3
	bl exchange__int_array_t__int_t__int_t
	str r0, [fp, #-68]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_19, _temp_var_18
	@ _temp_var_19 = _temp_var_18;
	ldr r0, [fp, #-68]
	str r0, [fp, #-72]

	@ GOTOOP_ANY_ANY_LABEL: L14
	@  goto L14;
	beq .L14
	bne .L14

	@ LABELOP_ANY_ANY_LABEL: L11
	@ L11: ;
	
.L11:

	@ LABELOP_ANY_ANY_LABEL: L14
	@ L14: ;
	
.L14:

	@ ADDOP_INT_CINT: _temp_var_20, j, 1
	@ _temp_var_20 = j + 1;
	ldr r0, [fp, #-36]
	mov r1, #1
	add r0, r1, r0
	str r0, [fp, #-76]

	@ ASSIGNOP_INT_ANY_INT: j, _temp_var_20
	@ j = _temp_var_20;
	ldr r0, [fp, #-76]
	str r0, [fp, #-36]

	@ GOTOOP_ANY_ANY_LABEL: L7
	@  goto L7;
	beq .L7
	bne .L7

	@ LABELOP_ANY_ANY_LABEL: L9
	@ L9: ;
	
.L9:

	@ ADDOP_INT_CINT: _temp_var_21, i, 1
	@ _temp_var_21 = i + 1;
	ldr r0, [fp, #-32]
	mov r1, #1
	add r0, r1, r0
	str r0, [fp, #-80]

	@ PARAMOP_ANY: A
	@  param A
	ldr r0, [fp, #-100]

	@ PARAMOP_ANY: _temp_var_21
	@  param _temp_var_21
	ldr r1, [fp, #-80]

	@ PARAMOP_ANY: r
	@  param r
	ldr r2, [fp, #-108]

	@ FUNCTIONOP_ANY: _temp_var_22, exchange__int_array_t__int_t__int_t, 3
	@  call _temp_var_22 exchange__int_array_t__int_t__int_t 3
	bl exchange__int_array_t__int_t__int_t
	str r0, [fp, #-84]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_23, _temp_var_22
	@ _temp_var_23 = _temp_var_22;
	ldr r0, [fp, #-84]
	str r0, [fp, #-88]

	@ ADDOP_INT_CINT: _temp_var_24, i, 1
	@ _temp_var_24 = i + 1;
	ldr r0, [fp, #-32]
	mov r1, #1
	add r0, r1, r0
	str r0, [fp, #-92]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_25, _temp_var_24
	@ _temp_var_25 = _temp_var_24;
	ldr r0, [fp, #-92]
	str r0, [fp, #-96]

	@ RETURNOP_ANY: _temp_var_25
	@  return _temp_var_25;
	ldr r0, [fp, #-96]

	@ END BODY
	sub sp, fp, #12
	ldmfd sp, {fp, sp, pc}
	.size	Partition__int_array_t__int_t__int_t, .-Partition__int_array_t__int_t__int_t

	.text
	.align	2
	.global	Quicksort__int_array_t__int_t__int_t
	.type	Quicksort__int_array_t__int_t__int_t, %function
Quicksort__int_array_t__int_t__int_t:
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #52
	@ SETTING ARGUMENTS
	str	r0, [fp, #-56]
	str	r1, [fp, #-60]
	str	r2, [fp, #-64]
	@ START BODY

	@ LESSOP_INT_INT: _temp_var_26, p, r
	@ _temp_var_26 = p < r;
	ldr r0, [fp, #-60]
	ldr r1, [fp, #-64]
	cmp r0, r1
	movge r0, #0
	movlt r0, #1
	str r0, [fp, #-16]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_27, _temp_var_26
	@ _temp_var_27 = _temp_var_26;
	ldr r0, [fp, #-16]
	str r0, [fp, #-20]

	@ IFOP_ANY: L23, _temp_var_27
	@  if (_temp_var_27) goto L23;
	ldr r0, [fp, #-20]
	cmp r0, #0
	bne .L23

	@ GOTOOP_ANY_ANY_LABEL: L24
	@  goto L24;
	beq .L24
	bne .L24

	@ LABELOP_ANY_ANY_LABEL: L23
	@ L23: ;
	
.L23:

	@ PARAMOP_ANY: A
	@  param A
	ldr r0, [fp, #-56]

	@ PARAMOP_ANY: p
	@  param p
	ldr r1, [fp, #-60]

	@ PARAMOP_ANY: r
	@  param r
	ldr r2, [fp, #-64]

	@ FUNCTIONOP_ANY: _temp_var_28, Partition__int_array_t__int_t__int_t, 3
	@  call _temp_var_28 Partition__int_array_t__int_t__int_t 3
	bl Partition__int_array_t__int_t__int_t
	str r0, [fp, #-24]

	@ ASSIGNOP_INT_ANY_INT: q, _temp_var_28
	@ q = _temp_var_28;
	ldr r0, [fp, #-24]
	str r0, [fp, #-28]

	@ SUBOP_INT_CINT: _temp_var_29, q, 1
	@ _temp_var_29 = q - 1;
	ldr r0, [fp, #-28]
	mov r1, #1
	sub r0, r0, r1
	str r0, [fp, #-32]

	@ PARAMOP_ANY: A
	@  param A
	ldr r0, [fp, #-56]

	@ PARAMOP_ANY: p
	@  param p
	ldr r1, [fp, #-60]

	@ PARAMOP_ANY: _temp_var_29
	@  param _temp_var_29
	ldr r2, [fp, #-32]

	@ FUNCTIONOP_ANY: _temp_var_30, Quicksort__int_array_t__int_t__int_t, 3
	@  call _temp_var_30 Quicksort__int_array_t__int_t__int_t 3
	bl Quicksort__int_array_t__int_t__int_t
	str r0, [fp, #-36]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_31, _temp_var_30
	@ _temp_var_31 = _temp_var_30;
	ldr r0, [fp, #-36]
	str r0, [fp, #-40]

	@ ADDOP_INT_CINT: _temp_var_32, q, 1
	@ _temp_var_32 = q + 1;
	ldr r0, [fp, #-28]
	mov r1, #1
	add r0, r1, r0
	str r0, [fp, #-44]

	@ PARAMOP_ANY: A
	@  param A
	ldr r0, [fp, #-56]

	@ PARAMOP_ANY: _temp_var_32
	@  param _temp_var_32
	ldr r1, [fp, #-44]

	@ PARAMOP_ANY: r
	@  param r
	ldr r2, [fp, #-64]

	@ FUNCTIONOP_ANY: _temp_var_33, Quicksort__int_array_t__int_t__int_t, 3
	@  call _temp_var_33 Quicksort__int_array_t__int_t__int_t 3
	bl Quicksort__int_array_t__int_t__int_t
	str r0, [fp, #-48]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_34, _temp_var_33
	@ _temp_var_34 = _temp_var_33;
	ldr r0, [fp, #-48]
	str r0, [fp, #-52]

	@ GOTOOP_ANY_ANY_LABEL: L30
	@  goto L30;
	beq .L30
	bne .L30

	@ LABELOP_ANY_ANY_LABEL: L24
	@ L24: ;
	
.L24:

	@ LABELOP_ANY_ANY_LABEL: L30
	@ L30: ;
	
.L30:

	@ RETURNOP_ANY: _temp_var_34
	@  return _temp_var_34;
	ldr r0, [fp, #-52]

	@ END BODY
	sub sp, fp, #12
	ldmfd sp, {fp, sp, pc}
	.size	Quicksort__int_array_t__int_t__int_t, .-Quicksort__int_array_t__int_t__int_t

	.text
	.align	2
	.global	exchange__int_array_t__int_t__int_t
	.type	exchange__int_array_t__int_t__int_t, %function
exchange__int_array_t__int_t__int_t:
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #48
	@ SETTING ARGUMENTS
	str	r0, [fp, #-52]
	str	r1, [fp, #-56]
	str	r2, [fp, #-60]
	@ START BODY

	@ ASSIGNOP_INT_ANY_INT: _temp_var_0, i
	@ _temp_var_0 = i;
	ldr r0, [fp, #-56]
	str r0, [fp, #-16]

	@ RARRAYOP_IARR_INT_INT: _temp_var_1, A, _temp_var_0
	@ _temp_var_1 = A->data[_temp_var_0];
	add r0, fp, #-20
	ldr r1, [fp, #-52]
	ldr r2, [fp, #-16]
	bl get_element_int_array

	@ ASSIGNOP_INT_ANY_INT: tmp, _temp_var_1
	@ tmp = _temp_var_1;
	ldr r0, [fp, #-20]
	str r0, [fp, #-24]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_2, i
	@ _temp_var_2 = i;
	ldr r0, [fp, #-56]
	str r0, [fp, #-28]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_3, j
	@ _temp_var_3 = j;
	ldr r0, [fp, #-60]
	str r0, [fp, #-32]

	@ RARRAYOP_IARR_INT_INT: _temp_var_4, A, _temp_var_3
	@ _temp_var_4 = A->data[_temp_var_3];
	add r0, fp, #-36
	ldr r1, [fp, #-52]
	ldr r2, [fp, #-32]
	bl get_element_int_array

	@ LARRAYOP_INT_INT_IARR: A, _temp_var_2, _temp_var_4
	@  int_array_set(A, _temp_var_2, _temp_var_4);
	add r0, fp, #-52
	ldr r1, [fp, #-28]
	ldr r2, [fp, #-36]
	bl set_element_int_array

	@ ASSIGNOP_INT_ANY_INT: _temp_var_5, j
	@ _temp_var_5 = j;
	ldr r0, [fp, #-60]
	str r0, [fp, #-40]

	@ LARRAYOP_INT_INT_IARR: A, _temp_var_5, tmp
	@  int_array_set(A, _temp_var_5, tmp);
	add r0, fp, #-52
	ldr r1, [fp, #-40]
	ldr r2, [fp, #-24]
	bl set_element_int_array

	@ ADDOP_INT_CINT: _temp_var_6, i, 1
	@ _temp_var_6 = i + 1;
	ldr r0, [fp, #-56]
	mov r1, #1
	add r0, r1, r0
	str r0, [fp, #-44]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_7, _temp_var_6
	@ _temp_var_7 = _temp_var_6;
	ldr r0, [fp, #-44]
	str r0, [fp, #-48]

	@ RETURNOP_ANY: _temp_var_7
	@  return _temp_var_7;
	ldr r0, [fp, #-48]

	@ END BODY
	sub sp, fp, #12
	ldmfd sp, {fp, sp, pc}
	.size	exchange__int_array_t__int_t__int_t, .-exchange__int_array_t__int_t__int_t

	.text
	.align	2
	.global	main
	.type	main, %function
main:
	mov	ip, sp
	stmfd	sp!, {fp, ip, lr, pc}
	sub	fp, ip, #4
	sub	sp, sp, #36
	@ SETTING ARGUMENTS
	@ START BODY

	@ LARRAYOP_CINT_CINT_IARR: _temp_var_35, 0, 3
	@  int_array_set(_temp_var_35, 0, 3);
	add r0, fp, #-16
	mov r1, #0
	mov r2, #3
	bl set_element_int_array

	@ LARRAYOP_CINT_CINT_IARR: _temp_var_35, 1, 6
	@  int_array_set(_temp_var_35, 1, 6);
	add r0, fp, #-16
	mov r1, #1
	mov r2, #6
	bl set_element_int_array

	@ LARRAYOP_CINT_CINT_IARR: _temp_var_35, 2, 4
	@  int_array_set(_temp_var_35, 2, 4);
	add r0, fp, #-16
	mov r1, #2
	mov r2, #4
	bl set_element_int_array

	@ LARRAYOP_CINT_CINT_IARR: _temp_var_35, 3, 1
	@  int_array_set(_temp_var_35, 3, 1);
	add r0, fp, #-16
	mov r1, #3
	mov r2, #1
	bl set_element_int_array

	@ LARRAYOP_CINT_CINT_IARR: _temp_var_35, 4, 7
	@  int_array_set(_temp_var_35, 4, 7);
	add r0, fp, #-16
	mov r1, #4
	mov r2, #7
	bl set_element_int_array

	@ ASSIGNOP_IARR_ANY_IARR: A, _temp_var_35
	@  int_array_assign(A, _temp_var_35);
	add r0, fp, #-20
	ldr r1, [fp, #-16]
	bl assign_int_array

	@ ASSIGNOP_IARR_ANY_IARR: _temp_var_36, A
	@  int_array_assign(_temp_var_36, A);
	add r0, fp, #-24
	ldr r1, [fp, #-20]
	bl assign_int_array

	@ PRINTOP_ANY_ANY_IARR: _temp_var_36
	@  print_int_array(_temp_var_36);
	ldr r0, [fp, #-24]
	bl print_int_array

	@ ASSIGNOP_CINT_ANY_INT: _temp_var_37, 0
	@ _temp_var_37 = 0;
	mov r0, #0
	str r0, [fp, #-28]

	@ ASSIGNOP_CINT_ANY_INT: _temp_var_38, 4
	@ _temp_var_38 = 4;
	mov r0, #4
	str r0, [fp, #-32]

	@ PARAMOP_ANY: A
	@  param A
	ldr r0, [fp, #-20]

	@ PARAMOP_ANY: _temp_var_37
	@  param _temp_var_37
	ldr r1, [fp, #-28]

	@ PARAMOP_ANY: _temp_var_38
	@  param _temp_var_38
	ldr r2, [fp, #-32]

	@ FUNCTIONOP_ANY: _temp_var_39, Quicksort__int_array_t__int_t__int_t, 3
	@  call _temp_var_39 Quicksort__int_array_t__int_t__int_t 3
	bl Quicksort__int_array_t__int_t__int_t
	str r0, [fp, #-36]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_40, _temp_var_39
	@ _temp_var_40 = _temp_var_39;
	ldr r0, [fp, #-36]
	str r0, [fp, #-40]

	@ ASSIGNOP_IARR_ANY_IARR: _temp_var_41, A
	@  int_array_assign(_temp_var_41, A);
	add r0, fp, #-44
	ldr r1, [fp, #-20]
	bl assign_int_array

	@ PRINTOP_ANY_ANY_IARR: _temp_var_41
	@  print_int_array(_temp_var_41);
	ldr r0, [fp, #-44]
	bl print_int_array

	@ ASSIGNOP_CINT_ANY_INT: i, 0
	@ i = 0;
	mov r0, #0
	str r0, [fp, #-48]

	@ RETURNOP_ANY: i
	@  return i;
	ldr r0, [fp, #-48]

	@ END BODY
	sub sp, fp, #12
	ldmfd sp, {fp, sp, pc}
	.size	main, .-main


