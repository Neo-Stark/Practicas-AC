	.file	"SumaVectoresC-for.c"
	.section	.text.unlikely,"ax",@progbits
.LCOLDB0:
	.text
.LHOTB0:
	.p2align 4,,15
	.type	main._omp_fn.1, @function
main._omp_fn.1:
.LFB40:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	(%rdi), %ebx
	call	omp_get_num_threads
	movl	%eax, %ebp
	call	omp_get_thread_num
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ebp
	cmpl	%edx, %ecx
	jge	.L6
	addl	$1, %eax
	xorl	%edx, %edx
.L6:
	imull	%eax, %ecx
	addl	%ecx, %edx
	addl	%edx, %eax
	cmpl	%eax, %edx
	jge	.L1
	.p2align 4,,10
	.p2align 3
.L7:
	movslq	%edx, %rcx
	addl	$1, %edx
	movsd	v1(,%rcx,8), %xmm0
	cmpl	%edx, %eax
	addsd	v2(,%rcx,8), %xmm0
	movsd	%xmm0, v3(,%rcx,8)
	jne	.L7
.L1:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE40:
	.size	main._omp_fn.1, .-main._omp_fn.1
	.section	.text.unlikely
.LCOLDE0:
	.text
.LHOTE0:
	.section	.text.unlikely
.LCOLDB2:
	.text
.LHOTB2:
	.p2align 4,,15
	.type	main._omp_fn.0, @function
main._omp_fn.0:
.LFB39:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	movl	(%rdi), %ebx
	call	omp_get_num_threads
	movl	%eax, %ebp
	call	omp_get_thread_num
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ebp
	cmpl	%edx, %ecx
	jge	.L18
	addl	$1, %eax
	xorl	%edx, %edx
.L18:
	imull	%eax, %ecx
	addl	%ecx, %edx
	addl	%edx, %eax
	cmpl	%eax, %edx
	jge	.L11
	pxor	%xmm1, %xmm1
	movsd	.LC1(%rip), %xmm3
	cvtsi2sdq	%rbx, %xmm1
	mulsd	%xmm3, %xmm1
	.p2align 4,,10
	.p2align 3
.L16:
	pxor	%xmm0, %xmm0
	movapd	%xmm1, %xmm4
	movslq	%edx, %rcx
	cvtsi2sd	%edx, %xmm0
	addl	$1, %edx
	cmpl	%edx, %eax
	mulsd	%xmm3, %xmm0
	movapd	%xmm0, %xmm2
	subsd	%xmm0, %xmm4
	addsd	%xmm1, %xmm2
	movsd	%xmm4, v2(,%rcx,8)
	movsd	%xmm2, v1(,%rcx,8)
	jne	.L16
.L11:
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main._omp_fn.0, .-main._omp_fn.0
	.section	.text.unlikely
.LCOLDE2:
	.text
.LHOTE2:
	.section	.rodata.str1.8,"aMS",@progbits,1
	.align 8
.LC3:
	.string	"Faltan n\302\272 componentes del vector"
	.align 8
.LC4:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\n"
	.align 8
.LC5:
	.string	"/ V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f) /\n"
	.align 8
.LC6:
	.string	"Tiempo(seg.):%11.9f\t / Tama\303\261o Vectores:%u\t/ V1[0]+V2[0]=V3[0](%8.6f+%8.6f=%8.6f) / /     V1[%d]+V2[%d]=V3[%d](%8.6f+%8.6f=%8.6f)/\n"
	.section	.text.unlikely
.LCOLDB7:
	.section	.text.startup,"ax",@progbits
.LHOTB7:
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB38:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$40, %rsp
	.cfi_def_cfa_offset 64
	movq	%fs:40, %rax
	movq	%rax, 24(%rsp)
	xorl	%eax, %eax
	cmpl	$1, %edi
	jle	.L31
	movq	8(%rsi), %rdi
	movl	$10, %edx
	xorl	%esi, %esi
	call	strtol
	leaq	16(%rsp), %rsi
	cmpl	$33554432, %eax
	movl	$33554432, %edx
	cmova	%edx, %eax
	movl	$main._omp_fn.0, %edi
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	%eax, 16(%rsp)
	call	GOMP_parallel
	movl	16(%rsp), %ebx
	call	omp_get_wtime
	leaq	16(%rsp), %rsi
	xorl	%ecx, %ecx
	xorl	%edx, %edx
	movl	$main._omp_fn.1, %edi
	movsd	%xmm0, 8(%rsp)
	movl	%ebx, 16(%rsp)
	call	GOMP_parallel
	movl	16(%rsp), %ebx
	call	omp_get_wtime
	subsd	8(%rsp), %xmm0
	cmpl	$11, %ebx
	ja	.L23
	movl	%ebx, %edx
	movl	$.LC4, %esi
	movl	$1, %edi
	movl	$1, %eax
	call	__printf_chk
	testl	%ebx, %ebx
	je	.L25
	leal	-1(%rbx), %ebp
	xorl	%ebx, %ebx
	addq	$1, %rbp
	.p2align 4,,10
	.p2align 3
.L26:
	movsd	v3(,%rbx,8), %xmm2
	movl	%ebx, %r8d
	movl	%ebx, %ecx
	movsd	v2(,%rbx,8), %xmm1
	movl	%ebx, %edx
	movsd	v1(,%rbx,8), %xmm0
	movl	$.LC5, %esi
	movl	$1, %edi
	movl	$3, %eax
	addq	$1, %rbx
	call	__printf_chk
	cmpq	%rbp, %rbx
	jne	.L26
.L25:
	xorl	%eax, %eax
	movq	24(%rsp), %rcx
	xorq	%fs:40, %rcx
	jne	.L32
	addq	$40, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 24
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
.L23:
	.cfi_restore_state
	leal	-1(%rbx), %eax
	movsd	v3(%rip), %xmm3
	movsd	v2(%rip), %xmm2
	movl	%ebx, %edx
	movsd	v3(,%rax,8), %xmm6
	movq	%rax, %rcx
	movsd	v2(,%rax,8), %xmm5
	movl	%eax, %r9d
	movsd	v1(,%rax,8), %xmm4
	movl	%eax, %r8d
	movsd	v1(%rip), %xmm1
	movl	$.LC6, %esi
	movl	$1, %edi
	movl	$7, %eax
	call	__printf_chk
	jmp	.L25
.L31:
	movl	$.LC3, %edi
	call	puts
	orl	$-1, %edi
	call	exit
.L32:
	call	__stack_chk_fail
	.cfi_endproc
.LFE38:
	.size	main, .-main
	.section	.text.unlikely
.LCOLDE7:
	.section	.text.startup
.LHOTE7:
	.comm	v3,268435456,32
	.comm	v2,268435456,32
	.comm	v1,268435456,32
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC1:
	.long	2576980378
	.long	1069128089
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.9) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
