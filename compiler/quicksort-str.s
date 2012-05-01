	.file	"quicksort-str.src.pp"
	.text
	.align	2
	.global	Partition__str_array_t__int_t__int_t
	.type	Partition__str_array_t__int_t__int_t, %function
Partition__str_array_t__int_t__int_t:
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

	@ RARRAYOP_SARR_INT_STR: _temp_var_9, A, _temp_var_8
	@  strcpy(_temp_var_9, A->data[_temp_var_8]);
	add r0, fp, #-20
	ldr r1, [fp, #-100]
	ldr r2, [fp, #-16]
	bl get_element_str_array

	@ ASSIGNOP_STR_ANY_STR: x, _temp_var_9
	@  strcpy(x, _temp_var_9);
	add r0, fp, #-24
	ldr r1, [fp, #-20]
	bl assign_str

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

	@ RARRAYOP_SARR_INT_STR: _temp_var_14, A, _temp_var_13
	@  strcpy(_temp_var_14, A->data[_temp_var_13]);
	add r0, fp, #-52
	ldr r1, [fp, #-100]
	ldr r2, [fp, #-48]
	bl get_element_str_array

	@ LEQOP_STR_STR: _temp_var_15, _temp_var_14, x
	@ _temp_var_15 = strcmp(_temp_var_14, x) <= 0;
	ldr r0, [fp, #-52]
	ldr r1, [fp, #-24]
	bl compare_str
	cmp r0, #0
	movle r0, #1
	movgt r0, #0

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

	@ FUNCTIONOP_ANY: _temp_var_18, exchange__str_array_t__int_t__int_t, 3
	@  call _temp_var_18 exchange__str_array_t__int_t__int_t 3
	bl exchange__str_array_t__int_t__int_t
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

	@ FUNCTIONOP_ANY: _temp_var_22, exchange__str_array_t__int_t__int_t, 3
	@  call _temp_var_22 exchange__str_array_t__int_t__int_t 3
	bl exchange__str_array_t__int_t__int_t
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
	.size	Partition__str_array_t__int_t__int_t, .-Partition__str_array_t__int_t__int_t

	.text
	.align	2
	.global	Quicksort__str_array_t__int_t__int_t
	.type	Quicksort__str_array_t__int_t__int_t, %function
Quicksort__str_array_t__int_t__int_t:
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

	@ FUNCTIONOP_ANY: _temp_var_28, Partition__str_array_t__int_t__int_t, 3
	@  call _temp_var_28 Partition__str_array_t__int_t__int_t 3
	bl Partition__str_array_t__int_t__int_t
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

	@ FUNCTIONOP_ANY: _temp_var_30, Quicksort__str_array_t__int_t__int_t, 3
	@  call _temp_var_30 Quicksort__str_array_t__int_t__int_t 3
	bl Quicksort__str_array_t__int_t__int_t
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

	@ FUNCTIONOP_ANY: _temp_var_33, Quicksort__str_array_t__int_t__int_t, 3
	@  call _temp_var_33 Quicksort__str_array_t__int_t__int_t 3
	bl Quicksort__str_array_t__int_t__int_t
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
	.size	Quicksort__str_array_t__int_t__int_t, .-Quicksort__str_array_t__int_t__int_t

	.text
	.align	2
	.global	exchange__str_array_t__int_t__int_t
	.type	exchange__str_array_t__int_t__int_t, %function
exchange__str_array_t__int_t__int_t:
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

	@ RARRAYOP_SARR_INT_STR: _temp_var_1, A, _temp_var_0
	@  strcpy(_temp_var_1, A->data[_temp_var_0]);
	add r0, fp, #-20
	ldr r1, [fp, #-52]
	ldr r2, [fp, #-16]
	bl get_element_str_array

	@ ASSIGNOP_STR_ANY_STR: tmp, _temp_var_1
	@  strcpy(tmp, _temp_var_1);
	add r0, fp, #-24
	ldr r1, [fp, #-20]
	bl assign_str

	@ ASSIGNOP_INT_ANY_INT: _temp_var_2, i
	@ _temp_var_2 = i;
	ldr r0, [fp, #-56]
	str r0, [fp, #-28]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_3, j
	@ _temp_var_3 = j;
	ldr r0, [fp, #-60]
	str r0, [fp, #-32]

	@ RARRAYOP_SARR_INT_STR: _temp_var_4, A, _temp_var_3
	@  strcpy(_temp_var_4, A->data[_temp_var_3]);
	add r0, fp, #-36
	ldr r1, [fp, #-52]
	ldr r2, [fp, #-32]
	bl get_element_str_array

	@ LARRAYOP_INT_STR_SARR: A, _temp_var_2, _temp_var_4
	@  str_array_set(A, _temp_var_2, _temp_var_4);
	add r0, fp, #-52
	ldr r1, [fp, #-28]
	ldr r2, [fp, #-36]
	bl set_element_str_array

	@ ASSIGNOP_INT_ANY_INT: _temp_var_5, j
	@ _temp_var_5 = j;
	ldr r0, [fp, #-60]
	str r0, [fp, #-40]

	@ LARRAYOP_INT_STR_SARR: A, _temp_var_5, tmp
	@  str_array_set(A, _temp_var_5, tmp);
	add r0, fp, #-52
	ldr r1, [fp, #-40]
	ldr r2, [fp, #-24]
	bl set_element_str_array

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
	.size	exchange__str_array_t__int_t__int_t, .-exchange__str_array_t__int_t__int_t

	.section		.rodata
	.align	2
.L35:
	.ascii	"aaa\000"
	.align	2
.L36:
	.ascii	"bca\000"
	.align	2
.L37:
	.ascii	"abb\000"
	.align	2
.L38:
	.ascii	"aac\000"
	.align	2
.L39:
	.ascii	"bbb\000"
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

	@ LARRAYOP_CINT_CSTR_SARR: _temp_var_35, 0, "aaa"
	@  str_array_set(_temp_var_35, 0, "aaa");
	add r0, fp, #-16
	mov r1, #0
	ldr r2, .L34
	bl set_element_str_array_const

	@ LARRAYOP_CINT_CSTR_SARR: _temp_var_35, 1, "bca"
	@  str_array_set(_temp_var_35, 1, "bca");
	add r0, fp, #-16
	mov r1, #1
	ldr r2, .L34+4
	bl set_element_str_array_const

	@ LARRAYOP_CINT_CSTR_SARR: _temp_var_35, 2, "abb"
	@  str_array_set(_temp_var_35, 2, "abb");
	add r0, fp, #-16
	mov r1, #2
	ldr r2, .L34+8
	bl set_element_str_array_const

	@ LARRAYOP_CINT_CSTR_SARR: _temp_var_35, 3, "aac"
	@  str_array_set(_temp_var_35, 3, "aac");
	add r0, fp, #-16
	mov r1, #3
	ldr r2, .L34+12
	bl set_element_str_array_const

	@ LARRAYOP_CINT_CSTR_SARR: _temp_var_35, 4, "bbb"
	@  str_array_set(_temp_var_35, 4, "bbb");
	add r0, fp, #-16
	mov r1, #4
	ldr r2, .L34+16
	bl set_element_str_array_const

	@ ASSIGNOP_SARR_ANY_SARR: A, _temp_var_35
	@  str_array_assign(A, _temp_var_35);
	add r0, fp, #-20
	ldr r1, [fp, #-16]
	bl assign_str_array

	@ ASSIGNOP_SARR_ANY_SARR: _temp_var_36, A
	@  str_array_assign(_temp_var_36, A);
	add r0, fp, #-24
	ldr r1, [fp, #-20]
	bl assign_str_array

	@ PRINTOP_ANY_ANY_SARR: _temp_var_36
	@  print_str_array(_temp_var_36);
	ldr r0, [fp, #-24]
	bl print_str_array

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

	@ FUNCTIONOP_ANY: _temp_var_39, Quicksort__str_array_t__int_t__int_t, 3
	@  call _temp_var_39 Quicksort__str_array_t__int_t__int_t 3
	bl Quicksort__str_array_t__int_t__int_t
	str r0, [fp, #-36]

	@ ASSIGNOP_INT_ANY_INT: _temp_var_40, _temp_var_39
	@ _temp_var_40 = _temp_var_39;
	ldr r0, [fp, #-36]
	str r0, [fp, #-40]

	@ ASSIGNOP_SARR_ANY_SARR: _temp_var_41, A
	@  str_array_assign(_temp_var_41, A);
	add r0, fp, #-44
	ldr r1, [fp, #-20]
	bl assign_str_array

	@ PRINTOP_ANY_ANY_SARR: _temp_var_41
	@  print_str_array(_temp_var_41);
	ldr r0, [fp, #-44]
	bl print_str_array

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
.L34:
	.word	.L35
	.word	.L36
	.word	.L37
	.word	.L38
	.word	.L39
	.size	main, .-main


