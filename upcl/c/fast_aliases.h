#ifndef __upcl_c_fast_aliases_h
#define __upcl_c_fast_aliases_h

#include "c/expression.h"

#define CADD expression::Add
#define CSUB expression::Sub
#define CMUL expression::Mul
#define CDIV expression::Div
#define CREM expression::Rem
#define CAND c::expression::And
#define COR expression::Or
#define CXOR expression::Xor
#define CSHL expression::Shl
#define CSHR expression::Shr
#define CSHLC expression::ShlC
#define CSHRC expression::ShrC
#define CROL expression::Rol
#define CROR expression::Ror
#define CROLC expression::RolC
#define CRORC expression::RorC
#define CNEG expression::Neg
#define CCOM expression::Com
#define CNOT expression::Not
#define CCONSTn(x,n) c::expression::fromInteger(x, n)
#define CCONST(x) (((x) == 0 ? CCONSTn((uint64_t)0, (unsigned int)sizeof(x)*8) : \
			CCONSTn((x), (unsigned int)sizeof(x)*8)))
#define CREG expression::fromRegister
#define CASSIGN expression::Assign
#define CBITSLICE c::expression::BitSlice
#define CBITCOMBINE expression::BitCombine
#define CCAST c::expression::Cast
#define CSIGN expression::Signed
#define CUNSIGN(x) (x)
#define __CMASK(n,b) CSUB(CSHL(CCONSTn(1U, n), b), CCONSTn(1U, n))
#define CMASKTYPE(t) CCAST(t, __CMASK((t)->get_bits()+1, CCONSTn((t)->get_bits(), (t)->get_bits()+1)))
#define CMASKBIT(n) __CMASK((n)->get_type()->get_bits(), (n))

#define CEQ expression::Eq
#define CNE expression::Ne
#define CLT expression::Lt
#define CLE expression::Le
#define CGT expression::Gt
#define CGE expression::Ge

#endif  // !__upcl_c_fast_aliases_h
