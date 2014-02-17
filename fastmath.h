#ifdef __sysvnecv70_target
double EXFUN(fast_sin,(double));
double EXFUN(fast_cos,(double));
double EXFUN(fast_tan,(double));

double EXFUN(fast_asin,(double));
double EXFUN(fast_acos,(double));
double EXFUN(fast_atan,(double));

double EXFUN(fast_sinh,(double));
double EXFUN(fast_cosh,(double));
double EXFUN(fast_tanh,(double));

double EXFUN(fast_asinh,(double));
double EXFUN(fast_acosh,(double));
double EXFUN(fast_atanh,(double));

double EXFUN(fast_abs,(double));
double EXFUN(fast_sqrt,(double));
double EXFUN(fast_exp2,(double));
double EXFUN(fast_exp10,(double));
double EXFUN(fast_expe,(double));
double EXFUN(fast_log10,(double));
double EXFUN(fast_log2,(double));
double EXFUN(fast_loge,(double));


#define	sin(x)		fast_sin(x)
#define	cos(x)		fast_cos(x)
#define	tan(x)		fast_tan(x)
#define	asin(x)		fast_asin(x)
#define	acos(x)		fast_acos(x)
#define	atan(x)		fast_atan(x)
#define	sinh(x)		fast_sinh(x)
#define	cosh(x)		fast_cosh(x)
#define	tanh(x)		fast_tanh(x)
#define	asinh(x)	fast_asinh(x)
#define	acosh(x)	fast_acosh(x)
#define	atanh(x)	fast_atanh(x)
#define	abs(x)		fast_abs(x)
#define	sqrt(x)		fast_sqrt(x)
#define	exp2(x)		fast_exp2(x)
#define	exp10(x)	fast_exp10(x)
#define	expe(x)		fast_expe(x)
#define	log10(x)	fast_log10(x)
#define	log2(x)		fast_log2(x)
#define	loge(x)		fast_loge(x)

#ifdef _HAVE_STDC
/* These functions are in assembler, they really do take floats. This
   can only be used with a real ANSI compiler */

float EXFUN(fast_sinf,(float));
float EXFUN(fast_cosf,(float));
float EXFUN(fast_tanf,(float));

float EXFUN(fast_asinf,(float));
float EXFUN(fast_acosf,(float));
float EXFUN(fast_atanf,(float));

float EXFUN(fast_sinhf,(float));
