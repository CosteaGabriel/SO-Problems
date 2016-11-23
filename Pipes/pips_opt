	.file	"pipes.c"
	.section .rdata,"dr"
.LC0:
	.ascii "r\0"
.LC1:
	.ascii "date.txt\0"
.LC2:
	.ascii "Doesn't open date.txt\0"
	.text
	.globl	parent_write
	.def	parent_write;	.scl	2;	.type	32;	.endef
	.seh_proc	parent_write
parent_write:
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$256, %rsp
	.seh_stackalloc	256
	.seh_endprologue
	movq	$0, 32(%rsp)
	leaq	40(%rsp), %rdi
	movl	$11, %ecx
	movl	$0, %eax
	rep stosq
	movl	$0, (%rdi)
	leaq	.LC0(%rip), %rdx
	leaq	.LC1(%rip), %rcx
	call	fopen
	movq	%rax, %rsi
	testq	%rax, %rax
	jne	.L2
	leaq	.LC2(%rip), %rcx
	call	puts
.L2:
	leaq	144(%rsp), %rbx
	leaq	32(%rsp), %rdi
	jmp	.L3
.L4:
	movq	%rbx, %rdx
	movq	%rdi, %rcx
	call	strcat
.L3:
	movq	%rsi, %r8
	movl	$100, %edx
	movq	%rbx, %rcx
	call	fgets
	testq	%rax, %rax
	jne	.L4
	leaq	32(%rsp), %rdx
	movl	$100, %r8d
	movl	4+pfd(%rip), %ecx
	call	write
	movq	%rsi, %rcx
	call	fclose
	nop
	addq	$256, %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	ret
	.seh_endproc
	.globl	child_1_ReadAndWrite
	.def	child_1_ReadAndWrite;	.scl	2;	.type	32;	.endef
	.seh_proc	child_1_ReadAndWrite
child_1_ReadAndWrite:
	pushq	%rdi
	.seh_pushreg	%rdi
	subq	$2192, %rsp
	.seh_stackalloc	2192
	.seh_endprologue
	movq	$0, 1168(%rsp)
	leaq	1176(%rsp), %rdi
	movl	$127, %ecx
	movl	$0, %eax
	rep stosq
	leaq	1056(%rsp), %rdi
	movl	$104, %r8d
	movq	%rdi, %rdx
	movl	pfd(%rip), %ecx
	call	read
	movb	$0, 32(%rsp)
	leaq	32(%rsp), %rcx
	movq	%rdi, %rdx
	call	strcat
	movl	$0, %edx
	movl	$0, %r10d
	leaq	32(%rsp), %r8
	movq	$-1, %r11
	movl	$0, %eax
	jmp	.L6
.L8:
	movzbl	(%rdx,%r8), %ecx
	leal	-97(%rcx), %r9d
	cmpb	$25, %r9b
	ja	.L7
	movslq	%r10d, %r9
	movb	%cl, 1168(%rsp,%r9)
	addl	$1, %r10d
.L7:
	addq	$1, %rdx
.L6:
	movq	%r11, %rcx
	movq	%r8, %rdi
	repnz scasb
	notq	%rcx
	subq	$1, %rcx
	cmpq	%rdx, %rcx
	ja	.L8
	leaq	1168(%rsp), %rdx
	movl	$1024, %r8d
	movl	4+pfd2(%rip), %ecx
	call	write
	nop
	addq	$2192, %rsp
	popq	%rdi
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC3:
	.ascii "w\0"
.LC4:
	.ascii "statistica.txt\0"
.LC5:
	.ascii "couldn't open statistica.txt\0"
.LC6:
	.ascii "%c -> %d\15\12\0"
.LC7:
	.ascii "count = %d  string->%c\12\0"
	.text
	.globl	child_2_Write
	.def	child_2_Write;	.scl	2;	.type	32;	.endef
	.seh_proc	child_2_Write
child_2_Write:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%r15
	.seh_pushreg	%r15
	pushq	%r14
	.seh_pushreg	%r14
	pushq	%r13
	.seh_pushreg	%r13
	pushq	%r12
	.seh_pushreg	%r12
	pushq	%rdi
	.seh_pushreg	%rdi
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$296, %rsp
	.seh_stackalloc	296
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	leaq	.LC3(%rip), %rdx
	leaq	.LC4(%rip), %rcx
	call	fopen
	movq	%rax, %r12
	testq	%rax, %rax
	jne	.L10
	leaq	.LC5(%rip), %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L10:
	leaq	48(%rbp), %rdi
	movl	$104, %r8d
	movq	%rdi, %rdx
	movl	pfd2(%rip), %ecx
	call	read
	movl	$0, %eax
	movq	$-1, %rcx
	repnz scasb
	movq	%rcx, %rax
	notq	%rax
	leaq	10(,%rax,4), %rax
	andq	$-16, %rax
	call	___chkstk_ms
	subq	%rax, %rsp
	leaq	32(%rsp), %rsi
	movl	$0, %r8d
	leaq	48(%rbp), %r10
	movq	$-1, %r9
	movl	$0, %eax
	jmp	.L11
.L12:
	movslq	%r8d, %rdx
	movl	$0, (%rsi,%rdx,4)
	addl	$1, %r8d
.L11:
	movq	%r9, %rcx
	movq	%r10, %rdi
	repnz scasb
	notq	%rcx
	leaq	-1(%rcx), %rdx
	movslq	%r8d, %rcx
	cmpq	%rdx, %rcx
	jb	.L12
	leaq	48(%rbp), %rdx
	leaq	-64(%rbp), %rcx
	call	strcpy
	movl	$0, %r13d
	leaq	48(%rbp), %rbx
	movl	$0, %r14d
	jmp	.L13
.L15:
	movzbl	(%rbx,%r13), %eax
	cmpb	%al, -64(%rbp,%rdx)
	jne	.L14
	movb	$42, -64(%rbp,%rdx)
	addl	$1, %r15d
.L14:
	addq	$1, %rdx
	jmp	.L17
.L21:
	movl	$0, %edx
	movl	$0, %r15d
	movq	$-1, %r8
.L17:
	movq	%r8, %rcx
	movq	%rbx, %rdi
	movl	%r14d, %eax
	repnz scasb
	notq	%rcx
	subq	$1, %rcx
	cmpq	%rdx, %rcx
	ja	.L15
	testl	%r15d, %r15d
	jle	.L16
	movl	%r15d, %r9d
	movsbl	(%rbx,%r13), %r8d
	leaq	.LC6(%rip), %rdx
	movq	%r12, %rcx
	call	fprintf
	movq	%r12, %rdx
	movl	$10, %ecx
	call	fputc
	movl	%r15d, (%rsi,%r13,4)
.L16:
	addq	$1, %r13
.L13:
	movq	$-1, %rcx
	movq	%rbx, %rdi
	movl	%r14d, %eax
	repnz scasb
	notq	%rcx
	leaq	-1(%rcx), %rax
	movslq	%r13d, %rdx
	cmpq	%rax, %rdx
	jb	.L21
	movl	$0, %ebx
	movl	$0, -84(%rbp)
	leaq	48(%rbp), %r13
	movq	$-1, %r15
	movl	$0, %r14d
	jmp	.L18
.L20:
	movslq	%ebx, %rax
	cmpl	$1, (%rsi,%rax,4)
	jne	.L19
	addl	$1, -84(%rbp)
	movsbl	0(%r13,%rbx), %r8d
	movl	$1, %edx
	leaq	.LC7(%rip), %rcx
	call	printf
.L19:
	addq	$1, %rbx
.L18:
	movq	%r15, %rcx
	movq	%r13, %rdi
	movl	%r14d, %eax
	repnz scasb
	notq	%rcx
	leaq	-1(%rcx), %rax
	movslq	%ebx, %rdx
	cmpq	%rax, %rdx
	jb	.L20
	movzbl	-84(%rbp), %eax
	movb	%al, -65(%rbp)
	leaq	-65(%rbp), %rdx
	movl	$1, %r8d
	movl	4+pfd3(%rip), %ecx
	call	write
	movq	%r12, %rcx
	call	fclose
	nop
	leaq	168(%rbp), %rsp
	popq	%rbx
	popq	%rsi
	popq	%rdi
	popq	%r12
	popq	%r13
	popq	%r14
	popq	%r15
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC8:
	.ascii "Numarul de caractere disctinte este: %d\12\0"
	.text
	.globl	parent_afis
	.def	parent_afis;	.scl	2;	.type	32;	.endef
	.seh_proc	parent_afis
parent_afis:
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	leaq	44(%rsp), %rdx
	movl	$4, %r8d
	movl	pfd3(%rip), %ecx
	call	read
	testq	%rax, %rax
	jle	.L22
	movl	44(%rsp), %edx
	leaq	.LC8(%rip), %rcx
	call	printf
	nop
.L22:
	addq	$56, %rsp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC9:
	.ascii "Eroare la creearea pipe-ului\0"
.LC10:
	.ascii "Eroare la fork\0"
.LC11:
	.ascii "waitpid\0"
.LC12:
	.ascii "exited, status=%d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rsi
	.seh_pushreg	%rsi
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$56, %rsp
	.seh_stackalloc	56
	.seh_endprologue
	call	__main
	leaq	pfd(%rip), %rcx
	call	pipe
	testl	%eax, %eax
	js	.L25
	leaq	pfd2(%rip), %rcx
	call	pipe
	testl	%eax, %eax
	js	.L25
	leaq	pfd3(%rip), %rcx
	call	pipe
	testl	%eax, %eax
	jns	.L26
.L25:
	leaq	.LC9(%rip), %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L26:
	call	fork
	movl	%eax, %ebx
	testl	%eax, %eax
	js	.L27
	call	fork
	movl	%eax, %esi
	testl	%eax, %eax
	jns	.L28
.L27:
	leaq	.LC10(%rip), %rcx
	call	puts
	movl	$1, %ecx
	call	exit
.L28:
	testl	%ebx, %ebx
	jne	.L29
	movl	4+pfd(%rip), %ecx
	call	close
	movl	pfd2(%rip), %ecx
	call	close
	call	child_1_ReadAndWrite
	movl	pfd(%rip), %ecx
	call	close
	movl	4+pfd2(%rip), %ecx
	call	close
	jmp	.L30
.L29:
	testl	%eax, %eax
	jne	.L31
	movl	4+pfd2(%rip), %ecx
	call	close
	movl	pfd3(%rip), %ecx
	call	close
	call	child_2_Write
	movl	pfd2(%rip), %ecx
	call	close
	movl	4+pfd3(%rip), %ecx
	call	close
	jmp	.L30
.L31:
	movl	pfd(%rip), %ecx
	call	close
	call	parent_write
	movl	4+pfd(%rip), %ecx
	call	close
	movl	4+pfd3(%rip), %ecx
	call	close
	call	parent_afis
	movl	pfd2(%rip), %ecx
	call	close
	leaq	44(%rsp), %rdx
	movl	$10, %r8d
	movl	%ebx, %ecx
	call	waitpid
	movl	%eax, %ebx
	leaq	40(%rsp), %rdx
	movl	$10, %r8d
	movl	%esi, %ecx
	call	waitpid
	cmpl	$-1, %ebx
	jne	.L32
	cmpl	$-1, %eax
	jne	.L32
	leaq	.LC11(%rip), %rcx
	call	perror
	movl	$1, %ecx
	call	exit
.L32:
	movl	44(%rsp), %edx
	movzbl	%dh, %edx
	leaq	.LC12(%rip), %rcx
	call	printf
	movl	40(%rsp), %edx
	movzbl	%dh, %edx
	leaq	.LC12(%rip), %rcx
	call	printf
.L30:
	movl	$0, %eax
	addq	$56, %rsp
	popq	%rbx
	popq	%rsi
	ret
	.seh_endproc
	.comm	pfd3, 8, 3
	.comm	pfd2, 8, 3
	.comm	pfd, 8, 3
	.globl	pr
	.data
	.align 8
pr:
	.ascii "merge aici\12\0"
	.ident	"GCC: (GNU) 5.4.0"
	.def	fopen;	.scl	2;	.type	32;	.endef
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	strcat;	.scl	2;	.type	32;	.endef
	.def	fgets;	.scl	2;	.type	32;	.endef
	.def	write;	.scl	2;	.type	32;	.endef
	.def	fclose;	.scl	2;	.type	32;	.endef
	.def	read;	.scl	2;	.type	32;	.endef
	.def	exit;	.scl	2;	.type	32;	.endef
	.def	strcpy;	.scl	2;	.type	32;	.endef
	.def	fprintf;	.scl	2;	.type	32;	.endef
	.def	fputc;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	pipe;	.scl	2;	.type	32;	.endef
	.def	fork;	.scl	2;	.type	32;	.endef
	.def	close;	.scl	2;	.type	32;	.endef
	.def	waitpid;	.scl	2;	.type	32;	.endef
	.def	perror;	.scl	2;	.type	32;	.endef
