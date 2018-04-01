	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 11
	.globl	__Z5mergeP7SegTreePiiii
	.align	4, 0x90
__Z5mergeP7SegTreePiiii:                ## @_Z5mergeP7SegTreePiiii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp0:
	.cfi_def_cfa_offset 16
Ltmp1:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp2:
	.cfi_def_cfa_register %rbp
	movl	$2, %eax
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	%ecx, -24(%rbp)
	movl	%r8d, -28(%rbp)
	movl	-20(%rbp), %ecx
	addl	-24(%rbp), %ecx
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-44(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	%eax, -32(%rbp)
	movl	-32(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	movl	$0, -40(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-20(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jge	LBB0_3
## BB#2:                                ##   in Loop: Header=BB0_1 Depth=1
	movl	-20(%rbp), %eax
	movl	%eax, -40(%rbp)
	movslq	-40(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movslq	(%rdx,%rcx,4), %rcx
	movl	-28(%rbp), %eax
	shll	$1, %eax
	addl	$1, %eax
	movslq	%eax, %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-8(%rbp), %rdx
	movl	4(%rdx,%rcx,4), %eax
	movslq	-40(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movslq	(%rdx,%rcx,4), %rcx
	movslq	-28(%rbp), %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-8(%rbp), %rdx
	addl	4(%rdx,%rcx,4), %eax
	movl	%eax, 4(%rdx,%rcx,4)
	movl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -20(%rbp)
	jmp	LBB0_1
LBB0_3:
	jmp	LBB0_4
LBB0_4:                                 ## =>This Inner Loop Header: Depth=1
	movl	-36(%rbp), %eax
	cmpl	-24(%rbp), %eax
	jge	LBB0_6
## BB#5:                                ##   in Loop: Header=BB0_4 Depth=1
	movl	-36(%rbp), %eax
	movl	%eax, -40(%rbp)
	movslq	-40(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movslq	(%rdx,%rcx,4), %rcx
	movl	-28(%rbp), %eax
	shll	$1, %eax
	addl	$2, %eax
	movslq	%eax, %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-8(%rbp), %rdx
	movl	4(%rdx,%rcx,4), %eax
	movslq	-40(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movslq	(%rdx,%rcx,4), %rcx
	movslq	-28(%rbp), %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-8(%rbp), %rdx
	addl	4(%rdx,%rcx,4), %eax
	movl	%eax, 4(%rdx,%rcx,4)
	movl	-36(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -36(%rbp)
	jmp	LBB0_4
LBB0_6:
	popq	%rbp
	retq
	.cfi_endproc

	.globl	__Z16ConstructSegTreePiP7SegTreeiii
	.align	4, 0x90
__Z16ConstructSegTreePiP7SegTreeiii:    ## @_Z16ConstructSegTreePiP7SegTreeiii
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp3:
	.cfi_def_cfa_offset 16
Ltmp4:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp5:
	.cfi_def_cfa_register %rbp
	subq	$64, %rsp
	movq	%rdi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	movl	%edx, -20(%rbp)
	movl	%ecx, -24(%rbp)
	movl	%r8d, -28(%rbp)
	movl	-20(%rbp), %ecx
	movl	-24(%rbp), %edx
	subl	$1, %edx
	cmpl	%edx, %ecx
	jne	LBB1_2
## BB#1:
	movslq	-20(%rbp), %rax
	movq	-8(%rbp), %rcx
	movl	(%rcx,%rax,4), %edx
	movslq	-28(%rbp), %rax
	imulq	$404, %rax, %rax        ## imm = 0x194
	addq	-16(%rbp), %rax
	movl	%edx, (%rax)
	movslq	-20(%rbp), %rax
	movq	-8(%rbp), %rcx
	movslq	(%rcx,%rax,4), %rax
	movslq	-28(%rbp), %rcx
	imulq	$404, %rcx, %rcx        ## imm = 0x194
	addq	-16(%rbp), %rcx
	movl	4(%rcx,%rax,4), %edx
	addl	$1, %edx
	movl	%edx, 4(%rcx,%rax,4)
	jmp	LBB1_10
LBB1_2:
	movl	$2, %eax
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	-20(%rbp), %edx
	movl	-20(%rbp), %ecx
	addl	-24(%rbp), %ecx
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	movl	%edx, -40(%rbp)         ## 4-byte Spill
	cltd
	movl	-36(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	movl	-28(%rbp), %r8d
	shll	$1, %r8d
	addl	$1, %r8d
	movl	-40(%rbp), %r9d         ## 4-byte Reload
	movl	%r9d, %edx
	movl	%eax, %ecx
	callq	__Z16ConstructSegTreePiP7SegTreeiii
	movl	$2, %eax
	movq	-8(%rbp), %rdi
	movq	-16(%rbp), %rsi
	movl	-20(%rbp), %ecx
	addl	-24(%rbp), %ecx
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	cltd
	movl	-44(%rbp), %ecx         ## 4-byte Reload
	idivl	%ecx
	addl	$1, %eax
	movl	-24(%rbp), %ecx
	movl	-28(%rbp), %r8d
	shll	$1, %r8d
	addl	$2, %r8d
	movl	%eax, %edx
	callq	__Z16ConstructSegTreePiP7SegTreeiii
	movq	-16(%rbp), %rdi
	movq	-8(%rbp), %rsi
	movl	-20(%rbp), %edx
	movl	-24(%rbp), %ecx
	movl	-28(%rbp), %r8d
	callq	__Z5mergeP7SegTreePiiii
	movl	-24(%rbp), %eax
	subl	-20(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -32(%rbp)
	movl	-28(%rbp), %eax
	shll	$1, %eax
	addl	$1, %eax
	movslq	%eax, %rsi
	imulq	$404, %rsi, %rsi        ## imm = 0x194
	addq	-16(%rbp), %rsi
	movslq	(%rsi), %rsi
	movslq	-28(%rbp), %rdi
	imulq	$404, %rdi, %rdi        ## imm = 0x194
	addq	-16(%rbp), %rdi
	cmpl	$0, 4(%rdi,%rsi,4)
	jle	LBB1_5
## BB#3:
	movl	$2, %eax
	movl	-28(%rbp), %ecx
	shll	$1, %ecx
	addl	$1, %ecx
	movslq	%ecx, %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-16(%rbp), %rdx
	movslq	(%rdx), %rdx
	movslq	-28(%rbp), %rsi
	imulq	$404, %rsi, %rsi        ## imm = 0x194
	addq	-16(%rbp), %rsi
	movl	4(%rsi,%rdx,4), %ecx
	movl	-32(%rbp), %edi
	movl	%eax, -48(%rbp)         ## 4-byte Spill
	movl	%edi, %eax
	cltd
	movl	-48(%rbp), %edi         ## 4-byte Reload
	idivl	%edi
	cmpl	%eax, %ecx
	jle	LBB1_5
## BB#4:
	movl	-28(%rbp), %eax
	shll	$1, %eax
	addl	$1, %eax
	movslq	%eax, %rcx
	imulq	$404, %rcx, %rcx        ## imm = 0x194
	addq	-16(%rbp), %rcx
	movl	(%rcx), %eax
	movslq	-28(%rbp), %rcx
	imulq	$404, %rcx, %rcx        ## imm = 0x194
	addq	-16(%rbp), %rcx
	movl	%eax, (%rcx)
	jmp	LBB1_10
LBB1_5:
	movl	-28(%rbp), %eax
	shll	$1, %eax
	addl	$2, %eax
	movslq	%eax, %rcx
	imulq	$404, %rcx, %rcx        ## imm = 0x194
	addq	-16(%rbp), %rcx
	movslq	(%rcx), %rcx
	movslq	-28(%rbp), %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-16(%rbp), %rdx
	cmpl	$0, 4(%rdx,%rcx,4)
	jle	LBB1_8
## BB#6:
	movl	$2, %eax
	movl	-28(%rbp), %ecx
	shll	$1, %ecx
	addl	$2, %ecx
	movslq	%ecx, %rdx
	imulq	$404, %rdx, %rdx        ## imm = 0x194
	addq	-16(%rbp), %rdx
	movslq	(%rdx), %rdx
	movslq	-28(%rbp), %rsi
	imulq	$404, %rsi, %rsi        ## imm = 0x194
	addq	-16(%rbp), %rsi
	movl	4(%rsi,%rdx,4), %ecx
	movl	-32(%rbp), %edi
	movl	%eax, -52(%rbp)         ## 4-byte Spill
	movl	%edi, %eax
	cltd
	movl	-52(%rbp), %edi         ## 4-byte Reload
	idivl	%edi
	cmpl	%eax, %ecx
	jle	LBB1_8
## BB#7:
	movl	-28(%rbp), %eax
	shll	$1, %eax
	addl	$2, %eax
	movslq	%eax, %rcx
	imulq	$404, %rcx, %rcx        ## imm = 0x194
	addq	-16(%rbp), %rcx
	movl	(%rcx), %eax
	movslq	-28(%rbp), %rcx
	imulq	$404, %rcx, %rcx        ## imm = 0x194
	addq	-16(%rbp), %rcx
	movl	%eax, (%rcx)
	jmp	LBB1_9
LBB1_8:
	movslq	-28(%rbp), %rax
	imulq	$404, %rax, %rax        ## imm = 0x194
	addq	-16(%rbp), %rax
	movl	$-1, (%rax)
LBB1_9:
	jmp	LBB1_10
LBB1_10:
	addq	$64, %rsp
	popq	%rbp
	retq
	.cfi_endproc

	.section	__TEXT,__literal8,8byte_literals
	.align	3
LCPI2_0:
	.quad	4611686018427387904     ## double 2
LCPI2_1:
	.quad	-4616189618054758400    ## double -1
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## BB#0:
	pushq	%rbp
Ltmp6:
	.cfi_def_cfa_offset 16
Ltmp7:
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
Ltmp8:
	.cfi_def_cfa_register %rbp
	subq	$400112, %rsp           ## imm = 0x61AF0
	xorl	%edi, %edi
	movq	___stack_chk_guard@GOTPCREL(%rip), %rax
	movq	(%rax), %rax
	movq	%rax, -8(%rbp)
	movl	$0, -400020(%rbp)
	callq	__ZNSt3__18ios_base15sync_with_stdioEb
	movq	__ZNSt3__13cinE@GOTPCREL(%rip), %rdi
	leaq	-400024(%rbp), %rsi
	movb	%al, -400053(%rbp)      ## 1-byte Spill
	callq	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	leaq	-400028(%rbp), %rsi
	movq	%rax, %rdi
	callq	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	movl	$0, -400032(%rbp)
	movq	%rax, -400064(%rbp)     ## 8-byte Spill
LBB2_1:                                 ## =>This Inner Loop Header: Depth=1
	movl	-400032(%rbp), %eax
	cmpl	-400024(%rbp), %eax
	jge	LBB2_4
## BB#2:                                ##   in Loop: Header=BB2_1 Depth=1
	movq	__ZNSt3__13cinE@GOTPCREL(%rip), %rdi
	leaq	-400016(%rbp), %rax
	movslq	-400032(%rbp), %rcx
	shlq	$2, %rcx
	addq	%rcx, %rax
	movq	%rax, %rsi
	callq	__ZNSt3__113basic_istreamIcNS_11char_traitsIcEEErsERi
	movq	%rax, -400072(%rbp)     ## 8-byte Spill
## BB#3:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-400032(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -400032(%rbp)
	jmp	LBB2_1
LBB2_4:
	xorl	%eax, %eax
	leaq	-400016(%rbp), %rdi
	cvtsi2sdl	-400024(%rbp), %xmm0
	movl	%eax, -400076(%rbp)     ## 4-byte Spill
	movq	%rdi, -400088(%rbp)     ## 8-byte Spill
	callq	_log2
	callq	_ceil
	cvttsd2si	%xmm0, %eax
	movl	%eax, -400036(%rbp)
	cvtsi2sdl	%eax, %xmm1
	movsd	LCPI2_0(%rip), %xmm0    ## xmm0 = mem[0],zero
	callq	_pow
	addsd	%xmm0, %xmm0
	movsd	LCPI2_1(%rip), %xmm1    ## xmm1 = mem[0],zero
	addsd	%xmm1, %xmm0
	cvttsd2si	%xmm0, %eax
	movl	%eax, -400040(%rbp)
	movl	-400040(%rbp), %eax
	movl	%eax, %edi
	movq	%rsp, %rcx
	movq	%rcx, -400048(%rbp)
	imulq	$404, %rdi, %rcx        ## imm = 0x194
	addq	$15, %rcx
	andq	$-16, %rcx
	movq	%rsp, %rdi
	subq	%rcx, %rdi
	movq	%rdi, %rsp
	movl	-400024(%rbp), %eax
	subl	$1, %eax
	movq	-400088(%rbp), %rcx     ## 8-byte Reload
	movq	%rdi, -400096(%rbp)     ## 8-byte Spill
	movq	%rcx, %rdi
	movq	-400096(%rbp), %rsi     ## 8-byte Reload
	movl	-400076(%rbp), %edx     ## 4-byte Reload
	movl	%eax, %ecx
	movl	-400076(%rbp), %r8d     ## 4-byte Reload
	callq	__Z16ConstructSegTreePiP7SegTreeiii
	movq	___stack_chk_guard@GOTPCREL(%rip), %rsi
	movl	$0, -400020(%rbp)
	movl	$1, -400052(%rbp)
	movq	-400048(%rbp), %rdi
	movq	%rdi, %rsp
	movl	-400020(%rbp), %eax
	movq	(%rsi), %rsi
	cmpq	-8(%rbp), %rsi
	movl	%eax, -400100(%rbp)     ## 4-byte Spill
	jne	LBB2_6
## BB#5:                                ## %SP_return
	movl	-400100(%rbp), %eax     ## 4-byte Reload
	movq	%rbp, %rsp
	popq	%rbp
	retq
LBB2_6:                                 ## %CallStackCheckFailBlk
	callq	___stack_chk_fail
	.cfi_endproc


.subsections_via_symbols
