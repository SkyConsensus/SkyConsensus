/*
 * Copyright (c) 2012-2020 MIRACL UK Ltd.
 *
 * This file is part of MIRACL Core
 * (see https://github.com/miracl/core).
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/* CORE Fp^2 functions */
/* SU=m, m is Stack Usage (no lazy )*/

/* FP2 elements are of the form a+ib, where i is sqrt(-1) */

#include "fp2_FP256BN.h"

/* test x==0 ? */
/* SU= 8 */
int FP2_FP256BN_iszilch(FP2_FP256BN *x)
{
    return (FP_FP256BN_iszilch(&(x->a)) & FP_FP256BN_iszilch(&(x->b)));
}

/* Move b to a if d=1 */
void FP2_FP256BN_cmove(FP2_FP256BN *f, FP2_FP256BN *g, int d)
{
    FP_FP256BN_cmove(&(f->a), &(g->a), d);
    FP_FP256BN_cmove(&(f->b), &(g->b), d);
}

/* test x==1 ? */
/* SU= 48 */
int FP2_FP256BN_isunity(FP2_FP256BN *x)
{
    FP_FP256BN one;
    FP_FP256BN_one(&one);
    return (FP_FP256BN_equals(&(x->a), &one) & FP_FP256BN_iszilch(&(x->b)));
}

/* SU= 8 */
/* Fully reduce a and b mod Modulus */
void FP2_FP256BN_reduce(FP2_FP256BN *w)
{
    FP_FP256BN_reduce(&(w->a));
    FP_FP256BN_reduce(&(w->b));
}

/* return 1 if x==y, else 0 */
/* SU= 16 */
int FP2_FP256BN_equals(FP2_FP256BN *x, FP2_FP256BN *y)
{
    return (FP_FP256BN_equals(&(x->a), &(y->a)) & FP_FP256BN_equals(&(x->b), &(y->b)));
}


// Is x lexically larger than p-x?
// return -1 for no, 0 if x=0, 1 for yes
int FP2_FP256BN_islarger(FP2_FP256BN *x)
{
    int cmp;
    if (FP2_FP256BN_iszilch(x)) return 0;
    cmp=FP_FP256BN_islarger(&(x->b));
    if (cmp!=0) return cmp;
    return FP_FP256BN_islarger(&(x->a));
}

void FP2_FP256BN_toBytes(char *b,FP2_FP256BN *x)
{
    FP_FP256BN_toBytes(b,&(x->b));
    FP_FP256BN_toBytes(&b[MODBYTES_256_28],&(x->a));
}

void FP2_FP256BN_fromBytes(FP2_FP256BN *x,char *b)
{
    FP_FP256BN_fromBytes(&(x->b),b);
    FP_FP256BN_fromBytes(&(x->a),&b[MODBYTES_256_28]);
}


/* Create FP2 from two FPs */
/* SU= 16 */
void FP2_FP256BN_from_FPs(FP2_FP256BN *w, FP_FP256BN *x, FP_FP256BN *y)
{
    FP_FP256BN_copy(&(w->a), x);
    FP_FP256BN_copy(&(w->b), y);
}

/* Create FP2 from two BIGS */
/* SU= 16 */
void FP2_FP256BN_from_BIGs(FP2_FP256BN *w, BIG_256_28 x, BIG_256_28 y)
{
    FP_FP256BN_nres(&(w->a), x);
    FP_FP256BN_nres(&(w->b), y);
}

/* Create FP2 from two ints */
void FP2_FP256BN_from_ints(FP2_FP256BN *w, int xa, int xb)
{
    FP_FP256BN a,b;
    FP_FP256BN_from_int(&a,xa);
    FP_FP256BN_from_int(&b,xb);
    FP2_FP256BN_from_FPs(w,&a,&b);
//    BIG_256_28 a, b;
//    BIG_256_28_zero(a); BIG_256_28_inc(a, xa); BIG_256_28_norm(a);
//    BIG_256_28_zero(b); BIG_256_28_inc(b, xb); BIG_256_28_norm(b);
//    FP2_FP256BN_from_BIGs(w, a, b);
}

/* Create FP2 from FP */
/* SU= 8 */
void FP2_FP256BN_from_FP(FP2_FP256BN *w, FP_FP256BN *x)
{
    FP_FP256BN_copy(&(w->a), x);
    FP_FP256BN_zero(&(w->b));
}

/* Create FP2 from BIG */
/* SU= 8 */
void FP2_FP256BN_from_BIG(FP2_FP256BN *w, BIG_256_28 x)
{
    FP_FP256BN_nres(&(w->a), x);
    FP_FP256BN_zero(&(w->b));
}

/* FP2 copy w=x */
/* SU= 16 */
void FP2_FP256BN_copy(FP2_FP256BN *w, FP2_FP256BN *x)
{
    if (w == x) return;
    FP_FP256BN_copy(&(w->a), &(x->a));
    FP_FP256BN_copy(&(w->b), &(x->b));
}

/* FP2 set w=0 */
/* SU= 8 */
void FP2_FP256BN_zero(FP2_FP256BN *w)
{
    FP_FP256BN_zero(&(w->a));
    FP_FP256BN_zero(&(w->b));
}

/* FP2 set w=1 */
/* SU= 48 */
void FP2_FP256BN_one(FP2_FP256BN *w)
{
    FP_FP256BN one;
    FP_FP256BN_one(&one);
    FP2_FP256BN_from_FP(w, &one);
}

void FP2_FP256BN_rcopy(FP2_FP256BN *w,const BIG_256_28 a,const BIG_256_28 b)
{
    FP_FP256BN_rcopy(&(w->a),a);
    FP_FP256BN_rcopy(&(w->b),b);
}

int FP2_FP256BN_sign(FP2_FP256BN *w)
{
    int p1,p2;
    p1=FP_FP256BN_sign(&(w->a));
    p2=FP_FP256BN_sign(&(w->b));
#ifdef BIG_ENDIAN_SIGN_FP256BN
    p2 ^= (p1 ^ p2)&FP_FP256BN_iszilch(&(w->b));
    return p2;
#else
    p1 ^= (p1 ^ p2)&FP_FP256BN_iszilch(&(w->a));
    return p1;
#endif
}

/* Set w=-x */
/* SU= 88 */
void FP2_FP256BN_neg(FP2_FP256BN *w, FP2_FP256BN *x)
{
    /* Just one neg! */
    FP_FP256BN m, t;
    FP_FP256BN_add(&m, &(x->a), &(x->b));
    FP_FP256BN_neg(&m, &m);
    FP_FP256BN_add(&t, &m, &(x->b));
    FP_FP256BN_add(&(w->b), &m, &(x->a));
    FP_FP256BN_copy(&(w->a), &t);

}

/* Set w=conj(x) */
/* SU= 16 */
void FP2_FP256BN_conj(FP2_FP256BN *w, FP2_FP256BN *x)
{
    FP_FP256BN_copy(&(w->a), &(x->a));
    FP_FP256BN_neg(&(w->b), &(x->b));
    FP_FP256BN_norm(&(w->b));
}

/* Set w=x+y */
/* SU= 16 */
void FP2_FP256BN_add(FP2_FP256BN *w, FP2_FP256BN *x, FP2_FP256BN *y)
{
    FP_FP256BN_add(&(w->a), &(x->a), &(y->a));
    FP_FP256BN_add(&(w->b), &(x->b), &(y->b));
}

/* Set w=x-y */
/* Input y MUST be normed */
void FP2_FP256BN_sub(FP2_FP256BN *w, FP2_FP256BN *x, FP2_FP256BN *y)
{
    FP2_FP256BN m;
    FP2_FP256BN_neg(&m, y);
    FP2_FP256BN_add(w, x, &m);
}

/* Set w=s*x, where s is FP */
/* SU= 16 */
void FP2_FP256BN_pmul(FP2_FP256BN *w, FP2_FP256BN *x, FP_FP256BN *s)
{
    FP_FP256BN_mul(&(w->a), &(x->a), s);
    FP_FP256BN_mul(&(w->b), &(x->b), s);
}

/* SU= 16 */
/* Set w=s*x, where s is int */
void FP2_FP256BN_imul(FP2_FP256BN *w, FP2_FP256BN *x, int s)
{
    FP_FP256BN_imul(&(w->a), &(x->a), s);
    FP_FP256BN_imul(&(w->b), &(x->b), s);
}

/* Set w=x^2 */
/* SU= 128 */
void FP2_FP256BN_sqr(FP2_FP256BN *w, FP2_FP256BN *x)
{
    FP_FP256BN w1, w3, mb;

    FP_FP256BN_add(&w1, &(x->a), &(x->b));
    FP_FP256BN_neg(&mb, &(x->b));

    FP_FP256BN_add(&w3, &(x->a), &(x->a));
    FP_FP256BN_norm(&w3);
    FP_FP256BN_mul(&(w->b), &w3, &(x->b));

    FP_FP256BN_add(&(w->a), &(x->a), &mb);

    FP_FP256BN_norm(&w1);
    FP_FP256BN_norm(&(w->a));

    FP_FP256BN_mul(&(w->a), &w1, &(w->a));   /* w->a#2 w->a=1 w1&w2=6 w1*w2=2 */
}

/* Set w=x*y */
/* Inputs MUST be normed  */
/* Now uses Lazy reduction */
void FP2_FP256BN_mul(FP2_FP256BN *w, FP2_FP256BN *x, FP2_FP256BN *y)
{
    DBIG_256_28 A, B, E, F, pR;
    BIG_256_28 C, D, p;

    BIG_256_28_rcopy(p, Modulus_FP256BN);
    BIG_256_28_dsucopy(pR, p);

// reduce excesses of a and b as required (so product < pR)

    if ((sign64)(x->a.XES + x->b.XES) * (y->a.XES + y->b.XES) > (sign64)FEXCESS_FP256BN)
    {
#ifdef DEBUG_REDUCE
        printf("FP2 Product too large - reducing it\n");
#endif
        if (x->a.XES > 1) FP_FP256BN_reduce(&(x->a));
        if (x->b.XES > 1) FP_FP256BN_reduce(&(x->b));
    }

    BIG_256_28_mul(A, x->a.g, y->a.g);
    BIG_256_28_mul(B, x->b.g, y->b.g);

    BIG_256_28_add(C, x->a.g, x->b.g);
    BIG_256_28_norm(C);
    BIG_256_28_add(D, y->a.g, y->b.g);
    BIG_256_28_norm(D);

    BIG_256_28_mul(E, C, D);
    BIG_256_28_dadd(F, A, B);
    BIG_256_28_dsub(B, pR, B); //

    BIG_256_28_dadd(A, A, B);  // A<pR? Not necessarily, but <2pR
    BIG_256_28_dsub(E, E, F);  // E<pR ? Yes

    BIG_256_28_dnorm(A);
    FP_FP256BN_mod(w->a.g, A);
    w->a.XES = 3; // may drift above 2p...
    BIG_256_28_dnorm(E);
    FP_FP256BN_mod(w->b.g, E);
    w->b.XES = 2;

}

/* output FP2 in hex format [a,b] */
/* SU= 16 */
void FP2_FP256BN_output(FP2_FP256BN *w)
{
    BIG_256_28 bx, by;
    FP2_FP256BN_reduce(w);
    FP_FP256BN_redc(bx, &(w->a));
    FP_FP256BN_redc(by, &(w->b));
    printf("[");
    BIG_256_28_output(bx);
    printf(",");
    BIG_256_28_output(by);
    printf("]");
    FP_FP256BN_nres(&(w->a), bx);
    FP_FP256BN_nres(&(w->b), by);
}

/* SU= 8 */
void FP2_FP256BN_rawoutput(FP2_FP256BN *w)
{
    printf("[");
    BIG_256_28_rawoutput(w->a.g);
    printf(",");
    BIG_256_28_rawoutput(w->b.g);
    printf("]");
}


/* Set w=1/x */
/* SU= 128 */
void FP2_FP256BN_inv(FP2_FP256BN *w, FP2_FP256BN *x, FP_FP256BN *h)
{
    BIG_256_28 m, b;
    FP_FP256BN w1, w2;

    FP2_FP256BN_norm(x);
    FP_FP256BN_sqr(&w1, &(x->a));
    FP_FP256BN_sqr(&w2, &(x->b));
    FP_FP256BN_add(&w1, &w1, &w2);

    FP_FP256BN_inv(&w1, &w1, h);

    FP_FP256BN_mul(&(w->a), &(x->a), &w1);
    FP_FP256BN_neg(&w1, &w1);
    FP_FP256BN_norm(&w1);
    FP_FP256BN_mul(&(w->b), &(x->b), &w1);
}


/* Set w=x/2 */
/* SU= 16 */
void FP2_FP256BN_div2(FP2_FP256BN *w, FP2_FP256BN *x)
{
    FP_FP256BN_div2(&(w->a), &(x->a));
    FP_FP256BN_div2(&(w->b), &(x->b));
}

/* Set w*=(1+sqrt(-1)) */
/* where X^2-(1+sqrt(-1)) is irreducible for FP4, assumes p=3 mod 8 */

/* Input MUST be normed */
void FP2_FP256BN_mul_ip(FP2_FP256BN *w)
{
    FP2_FP256BN t;

    int i = QNRI_FP256BN;

    FP2_FP256BN_copy(&t, w);
    FP2_FP256BN_times_i(w);

// add 2^i.t
    while (i > 0)
    {
        FP2_FP256BN_add(&t, &t, &t);
        FP2_FP256BN_norm(&t);
        i--;
    }
    FP2_FP256BN_add(w, &t, w);

#if TOWER_FP256BN == POSITOWER
    FP2_FP256BN_norm(w);
    FP2_FP256BN_neg(w, w);  // ***
#endif
//    Output NOT normed, so use with care
}

/* Set w/=(1+sqrt(-1)) */
/* SU= 88 */
void FP2_FP256BN_div_ip(FP2_FP256BN *w)
{
    FP2_FP256BN z;
    FP2_FP256BN_norm(w);
    FP2_FP256BN_from_ints(&z, (1 << QNRI_FP256BN), 1);
    FP2_FP256BN_inv(&z, &z, NULL);
    FP2_FP256BN_mul(w, &z, w);
#if TOWER_FP256BN == POSITOWER
    FP2_FP256BN_neg(w, w);  // ***
#endif
}

/* SU= 8 */
/* normalise a and b components of w */
void FP2_FP256BN_norm(FP2_FP256BN *w)
{
    FP_FP256BN_norm(&(w->a));
    FP_FP256BN_norm(&(w->b));
}

/* Set w=a^b mod m */
/* SU= 208 */
/*
void FP2_FP256BN_pow(FP2_FP256BN *r, FP2_FP256BN* a, BIG_256_28 b)
{
    FP2_FP256BN w;
    FP_FP256BN one;
    BIG_256_28 z, zilch;
    int bt;

    BIG_256_28_norm(b);
    BIG_256_28_copy(z, b);
    FP2_FP256BN_copy(&w, a);
    FP_FP256BN_one(&one);
    BIG_256_28_zero(zilch);
    FP2_FP256BN_from_FP(r, &one);
    while (1)
    {
        bt = BIG_256_28_parity(z);
        BIG_256_28_shr(z, 1);
        if (bt) FP2_FP256BN_mul(r, r, &w);
        if (BIG_256_28_comp(z, zilch) == 0) break;
        FP2_FP256BN_sqr(&w, &w);
    }
    FP2_FP256BN_reduce(r);
}
*/
/* test for x a QR */

int FP2_FP256BN_qr(FP2_FP256BN *x, FP_FP256BN *h)
{ /* test x^(p^2-1)/2 = 1 */
    FP2_FP256BN c;
    FP2_FP256BN_conj(&c,x);
    FP2_FP256BN_mul(&c,&c,x);

    return FP_FP256BN_qr(&(c.a),h);
}

/* sqrt(a+ib) = sqrt(a+sqrt(a*a-n*b*b)/2)+ib/(2*sqrt(a+sqrt(a*a-n*b*b)/2)) */

void FP2_FP256BN_sqrt(FP2_FP256BN *w, FP2_FP256BN *u, FP_FP256BN *h)
{
    FP_FP256BN w1, w2, w3, w4, hint;
    FP2_FP256BN nw;
    int sgn,qr;

    FP2_FP256BN_copy(w, u);
    if (FP2_FP256BN_iszilch(w)) return;

    FP_FP256BN_sqr(&w1, &(w->b));
    FP_FP256BN_sqr(&w2, &(w->a));
    FP_FP256BN_add(&w1, &w1, &w2);
    FP_FP256BN_norm(&w1);
    FP_FP256BN_sqrt(&w1, &w1,h);

    FP_FP256BN_add(&w2, &(w->a), &w1);
    FP_FP256BN_norm(&w2);
    FP_FP256BN_div2(&w2, &w2);

    FP_FP256BN_div2(&w1,&(w->b));                   // w1=b/2
    qr=FP_FP256BN_qr(&w2,&hint);                    // only exp!

// tweak hint
    FP_FP256BN_neg(&w3,&hint); FP_FP256BN_norm(&w3);    // QNR = -1
    FP_FP256BN_neg(&w4,&w2); FP_FP256BN_norm(&w4);

    FP_FP256BN_cmove(&w2,&w4,1-qr);
    FP_FP256BN_cmove(&hint,&w3,1-qr);

    FP_FP256BN_sqrt(&(w->a),&w2,&hint);             // a=sqrt(w2)
    FP_FP256BN_inv(&w3,&w2,&hint);                  // w3=1/w2
    FP_FP256BN_mul(&w3,&w3,&(w->a));                // w3=1/sqrt(w2)
    FP_FP256BN_mul(&(w->b),&w3,&w1);                // b=(b/2)*1/sqrt(w2)
    FP_FP256BN_copy(&w4,&(w->a));

    FP_FP256BN_cmove(&(w->a),&(w->b),1-qr);
    FP_FP256BN_cmove(&(w->b),&w4,1-qr);


/*

    FP_FP256BN_sqrt(&(w->a),&w2,&hint);             // a=sqrt(w2)
    FP_FP256BN_inv(&w3,&w2,&hint);                  // w3=1/w2
    FP_FP256BN_mul(&w3,&w3,&(w->a));                // w3=1/sqrt(w2)
    FP_FP256BN_mul(&(w->b),&w3,&w1);                // b=(b/2)*1/sqrt(w2)

// tweak hint
    FP_FP256BN_neg(&hint,&hint); FP_FP256BN_norm(&hint);    // QNR = -1
    FP_FP256BN_neg(&w2,&w2); FP_FP256BN_norm(&w2);

    FP_FP256BN_sqrt(&w4,&w2,&hint);                 // w4=sqrt(w2)
    FP_FP256BN_inv(&w3,&w2,&hint);                  // w3=1/w2    
    FP_FP256BN_mul(&w3,&w3,&w4);                    // w3=1/sqrt(w2)
    FP_FP256BN_mul(&w3,&w3,&w1);                    // w3=(b/2)*1/sqrt(w2)

    FP_FP256BN_cmove(&(w->a),&w3,1-qr);
    FP_FP256BN_cmove(&(w->b),&w4,1-qr);
*/
    sgn=FP2_FP256BN_sign(w);
    FP2_FP256BN_neg(&nw,w); FP2_FP256BN_norm(&nw);
    FP2_FP256BN_cmove(w,&nw,sgn);

/*
    FP_FP256BN_sub(&w3, &(w->a), &w1);
    FP_FP256BN_norm(&w3);
    FP_FP256BN_div2(&w3, &w3);

    FP_FP256BN_cmove(&w2,&w3,FP_FP256BN_qr(&w3,NULL)); // one or the other will be a QR

    FP_FP256BN_invsqrt(&w3,&(w->a),&w2);
    FP_FP256BN_mul(&w3,&w3,&(w->a));
    FP_FP256BN_div2(&w2,&w3);

    FP_FP256BN_mul(&(w->b), &(w->b), &w2);

    sgn=FP2_FP256BN_sign(w);
    FP2_FP256BN_neg(&nw,w); FP2_FP256BN_norm(&nw);
    FP2_FP256BN_cmove(w,&nw,sgn); */
}

/* New stuff for ECp4 support */

/* Input MUST be normed */
void FP2_FP256BN_times_i(FP2_FP256BN *w)
{
    FP_FP256BN z;
    FP_FP256BN_copy(&z, &(w->a));
    FP_FP256BN_neg(&(w->a), &(w->b));
    FP_FP256BN_copy(&(w->b), &z);

//    Output NOT normed, so use with care
}

void FP2_FP256BN_rand(FP2_FP256BN *x,csprng *rng)
{
    FP_FP256BN_rand(&(x->a),rng);
    FP_FP256BN_rand(&(x->b),rng);
}
