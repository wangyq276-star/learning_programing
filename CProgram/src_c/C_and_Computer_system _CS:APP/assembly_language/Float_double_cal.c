double func(double a, float x, double b, int y) { return a * x - b / y; }

/*
汇编代码

vcvtss2sd	%xmm1, %xmm1, %xmm1
vmulsd	%xmm0, %xmm1, %xmm1
vxorps	%xmm0, %xmm0, %xmm0
vcvtsi2sdl	%edi, %xmm0, %xmm0
vdivsd	%xmm0, %xmm2, %xmm2
vsubsd	%xmm2, %xmm1, %xmm0
ret

*/