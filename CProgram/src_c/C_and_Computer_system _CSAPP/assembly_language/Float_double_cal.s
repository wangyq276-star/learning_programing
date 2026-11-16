	.file	"Float_double_cal.c"
	.text
	.globl	func
	.type	func, @function
func:
.LFB0:
	.cfi_startproc
	vcvtss2sd	%xmm1, %xmm1, %xmm1
	vmulsd	%xmm0, %xmm1, %xmm1
	vxorps	%xmm0, %xmm0, %xmm0
	vcvtsi2sdl	%edi, %xmm0, %xmm0
	vdivsd	%xmm0, %xmm2, %xmm2
	vsubsd	%xmm2, %xmm1, %xmm0
	ret
	.cfi_endproc
.LFE0:
	.size	func, .-func
	.ident	"GCC: (Ubuntu 15.2.0-16ubuntu1) 15.2.0"
	.section	.note.GNU-stack,"",@progbits
