/*

* Author: Rick Candell (rick.candell@nist.gov)
* Organization: National Institute of Standards and Technology
*               U.S. Department of Commerce
* License: Public Domain

* original credits:
*
*  N. L. Ricker, 12/98.  ricker@u.washington.edu

*/

/* f2c.h  --  Standard Fortran to C header file */

/**  barf  [ba:rf]  2.  "He suggested using FORTRAN, and everybody barfed."

        - From The Shogakukan DICTIONARY OF NEW ENGLISH (Second edition) */

#ifndef __TEPROB_H__
#define __TEPROB_H__

typedef long int integer;
typedef unsigned long uinteger;
typedef char *address;
typedef short int shortint;
typedef float real;
typedef double doublereal;
typedef struct { real r, i; } complex;
typedef struct { doublereal r, i; } doublecomplex;
typedef long int logical;
typedef short int shortlogical;
typedef char logical1;
typedef char integer1;
#if 0   /* Adjust for integer*8. */
typedef long long longint;              /* system-dependent */
typedef unsigned long long ulongint;    /* system-dependent */
#define qbit_clear(a,b) ((a) & ~((ulongint)1 << (b)))
#define qbit_set(a,b)   ((a) |  ((ulongint)1 << (b)))
#endif

#define TRUE_ (1)
#define FALSE_ (0)

/* Extern is for use with -E */
#ifndef Extern
#define Extern extern
#endif

/* I/O stuff */

#ifdef f2c_i2
/* for -i2 */
typedef short flag;
typedef short ftnlen;
typedef short ftnint;
#else
typedef long int flag;
typedef long int ftnlen;
typedef long int ftnint;
#endif

/*external read, write*/
typedef struct
{       flag cierr;
        ftnint ciunit;
        flag ciend;
        char *cifmt;
        ftnint cirec;
} cilist;

/*internal read, write*/
typedef struct
{       flag icierr;
        char *iciunit;
        flag iciend;
        char *icifmt;
        ftnint icirlen;
        ftnint icirnum;
} icilist;

/*open*/
typedef struct
{       flag oerr;
        ftnint ounit;
        char *ofnm;
        ftnlen ofnmlen;
        char *osta;
        char *oacc;
        char *ofm;
        ftnint orl;
        char *oblnk;
} olist;

/*close*/
typedef struct
{       flag cerr;
        ftnint cunit;
        char *csta;
} cllist;

/*rewind, backspace, endfile*/
typedef struct
{       flag aerr;
        ftnint aunit;
} alist;

/* inquire */
typedef struct
{       flag inerr;
        ftnint inunit;
        char *infile;
        ftnlen infilen;
        ftnint  *inex;  /*parameters in standard's order*/
        ftnint  *inopen;
        ftnint  *innum;
        ftnint  *innamed;
        char    *inname;
        ftnlen  innamlen;
        char    *inacc;
        ftnlen  inacclen;
        char    *inseq;
        ftnlen  inseqlen;
        char    *indir;
        ftnlen  indirlen;
        char    *infmt;
        ftnlen  infmtlen;
        char    *inform;
        ftnint  informlen;
        char    *inunf;
        ftnlen  inunflen;
        ftnint  *inrecl;
        ftnint  *innrec;
        char    *inblank;
        ftnlen  inblanklen;
} inlist;

#define VOID void

union Multitype {       /* for multiple entry points */
        integer1 g;
        shortint h;
        integer i;
        /* longint j; */
        real r;
        doublereal d;
        complex c;
        doublecomplex z;
        };

typedef union Multitype Multitype;

/*typedef long int Long;*/      /* No longer used; formerly in Namelist */

struct Vardesc {        /* for Namelist */
        char *name;
        char *addr;
        ftnlen *dims;
        int  type;
        };
typedef struct Vardesc Vardesc;

struct Namelist {
        char *name;
        Vardesc **vars;
        int nvars;
        };
typedef struct Namelist Namelist;

#define abs(x) ((x) >= 0 ? (x) : -(x))
#define dabs(x) (doublereal)abs(x)
//#define min(a,b) ((a) <= (b) ? (a) : (b))
//#define max(a,b) ((a) >= (b) ? (a) : (b))
#define dmin(a,b) (doublereal)min(a,b)
#define dmax(a,b) (doublereal)max(a,b)
#define bit_test(a,b)   ((a) >> (b) & 1)
#define bit_clear(a,b)  ((a) & ~((uinteger)1 << (b)))
#define bit_set(a,b)    ((a) |  ((uinteger)1 << (b)))

/* procedure parameter types for -A and -C++ */

#define F2C_proc_par_types 1
#ifdef __cplusplus
typedef int /* Unknown procedure type */ (*U_fp)(...);
typedef shortint (*J_fp)(...);
typedef integer (*I_fp)(...);
typedef real (*R_fp)(...);
typedef doublereal (*D_fp)(...), (*E_fp)(...);
typedef /* Complex */ VOID (*C_fp)(...);
typedef /* Double Complex */ VOID (*Z_fp)(...);
typedef logical (*L_fp)(...);
typedef shortlogical (*K_fp)(...);
typedef /* Character */ VOID (*H_fp)(...);
typedef /* Subroutine */ int (*S_fp)(...);
#else
typedef int /* Unknown procedure type */ (*U_fp)();
typedef shortint (*J_fp)();
typedef integer (*I_fp)();
typedef real (*R_fp)();
typedef doublereal (*D_fp)(), (*E_fp)();
typedef /* Complex */ VOID (*C_fp)();
typedef /* Double Complex */ VOID (*Z_fp)();
typedef logical (*L_fp)();
typedef shortlogical (*K_fp)();
typedef /* Character */ VOID (*H_fp)();
typedef /* Subroutine */ int (*S_fp)();
#endif
/* E_fp is for real functions when -R is not specified */
typedef VOID C_f;       /* complex function */
typedef VOID H_f;       /* character function */
typedef VOID Z_f;       /* double complex function */
typedef doublereal E_f; /* real function with -R not specified */

/* undef any lower-case symbols that your C compiler predefines, e.g.: */

#ifndef Skip_f2c_Undefs
#undef cray
#undef gcos
#undef mc68010
#undef mc68020
#undef mips
#undef pdp11
#undef sgi
#undef sparc
#undef sun
#undef sun2
#undef sun3
#undef sun4
#undef u370
#undef u3b
#undef u3b2
#undef u3b5
#undef unix
#undef vax
#endif



// more defs by rc
typedef double real_T;
//typedef struct
//{
//	doublereal x0;
//} SimStruct;

const int NX = 50;			// number of states
const int NU = 12;			// number of xmv
const int NY = 41;			// number of xmeas
const int NPAR = 1;			// number of parameters for encapsulating simulink block
const int NIDV = 20;		// number of disturbance types

// Prototypes
//void setidv(SimStruct *S);
//doublereal getcurr(doublereal x[], SimStruct *S);
void get_curr_xmeas(double* xmeas);
void get_curr_xmv(double* xmv);
void set_curr_xmv(double* xmv);
void set_curr_idv(int* idv);
int get_curr_shutdown();
char* get_shutdown_msg();

int tefunc(const integer *nn, doublereal *time, doublereal *yy, doublereal *yp);
int teinit(const integer *nn, doublereal *time, doublereal *yy, doublereal *yp);
int tesub1_(doublereal *z__, doublereal *t, doublereal *h__, 
			const integer *ity);
int tesub2_(doublereal *z__, doublereal *t, doublereal *h__, 
			const integer *ity);
int tesub3_(doublereal *z__, doublereal *t, doublereal *dh, 
			const integer *ity);
int tesub4_(doublereal *x, doublereal *t, doublereal *r__);
int tesub5_(doublereal *s, doublereal *sp, doublereal *adist, doublereal *bdist, 
			doublereal *cdist, doublereal *ddist, doublereal *tlast, 
			doublereal *tnext, doublereal *hspan, doublereal *hzero, 
			doublereal *sspan, doublereal *szero, doublereal *spspan, 
			integer *idvflag);
int tesub6_(doublereal *std, doublereal *x);
doublereal tesub7_(integer *i__);
doublereal tesub8_(const integer *i__, doublereal *t);
double pow_dd(doublereal *ap, const doublereal *bp);
double d_mod(doublereal *x, doublereal *y);




#endif