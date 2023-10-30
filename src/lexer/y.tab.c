/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/lexer/parser.y"

    #include <stdio.h>
    #include <assert.h>
    #include <stdlib.h>
    #define YYSTYPE double /* double type for yacc stack */

    extern FILE  * yyin, *yyout;
    int yylex();
    void yyerror(char * msg);


#line 83 "src/lexer/y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "y.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DATA_TYPE = 3,                  /* DATA_TYPE  */
  YYSYMBOL_IDENTIFIER = 4,                 /* IDENTIFIER  */
  YYSYMBOL_STRING = 5,                     /* STRING  */
  YYSYMBOL_IN = 6,                         /* IN  */
  YYSYMBOL_DOTS = 7,                       /* DOTS  */
  YYSYMBOL_CHAR = 8,                       /* CHAR  */
  YYSYMBOL_RETURN = 9,                     /* RETURN  */
  YYSYMBOL_INTEGER = 10,                   /* INTEGER  */
  YYSYMBOL_CURVE = 11,                     /* CURVE  */
  YYSYMBOL_FOR = 12,                       /* FOR  */
  YYSYMBOL_STRUCT = 13,                    /* STRUCT  */
  YYSYMBOL_AUG_ASSIGN = 14,                /* AUG_ASSIGN  */
  YYSYMBOL_DIFF = 15,                      /* DIFF  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_ARROW = 17,                     /* ARROW  */
  YYSYMBOL_COMPARE = 18,                   /* COMPARE  */
  YYSYMBOL_AND = 19,                       /* AND  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_SHIFT = 21,                     /* SHIFT  */
  YYSYMBOL_DECREMENT = 22,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT = 23,                 /* INCREMENT  */
  YYSYMBOL_REAL = 24,                      /* REAL  */
  YYSYMBOL_NEWLINE = 25,                   /* NEWLINE  */
  YYSYMBOL_IF = 26,                        /* IF  */
  YYSYMBOL_ELSE = 27,                      /* ELSE  */
  YYSYMBOL_REPEAT = 28,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 29,                     /* UNTIL  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 31,                  /* CONTINUE  */
  YYSYMBOL_IMPORT = 32,                    /* IMPORT  */
  YYSYMBOL_TRUE = 33,                      /* TRUE  */
  YYSYMBOL_FALSE = 34,                     /* FALSE  */
  YYSYMBOL_FUNC = 35,                      /* FUNC  */
  YYSYMBOL_36_ = 36,                       /* ';'  */
  YYSYMBOL_37_ = 37,                       /* '{'  */
  YYSYMBOL_38_ = 38,                       /* '}'  */
  YYSYMBOL_39_ = 39,                       /* '('  */
  YYSYMBOL_40_ = 40,                       /* ')'  */
  YYSYMBOL_41_ = 41,                       /* ','  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '<'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '['  */
  YYSYMBOL_46_ = 46,                       /* ']'  */
  YYSYMBOL_47_ = 47,                       /* '='  */
  YYSYMBOL_48_ = 48,                       /* '+'  */
  YYSYMBOL_49_ = 49,                       /* '-'  */
  YYSYMBOL_50_ = 50,                       /* '%'  */
  YYSYMBOL_51_ = 51,                       /* '/'  */
  YYSYMBOL_52_ = 52,                       /* '|'  */
  YYSYMBOL_53_ = 53,                       /* '&'  */
  YYSYMBOL_54_ = 54,                       /* '^'  */
  YYSYMBOL_55_ = 55,                       /* '~'  */
  YYSYMBOL_56_ = 56,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_start = 58,                     /* start  */
  YYSYMBOL_program = 59,                   /* program  */
  YYSYMBOL_global_decl = 60,               /* global_decl  */
  YYSYMBOL_struct = 61,                    /* struct  */
  YYSYMBOL_function = 62,                  /* function  */
  YYSYMBOL_funcDef = 63,                   /* funcDef  */
  YYSYMBOL_parameters = 64,                /* parameters  */
  YYSYMBOL_type_defs = 65,                 /* type_defs  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_parameter = 67,                 /* parameter  */
  YYSYMBOL_typelist = 68,                  /* typelist  */
  YYSYMBOL_block = 69,                     /* block  */
  YYSYMBOL_statements = 70,                /* statements  */
  YYSYMBOL_statement = 71,                 /* statement  */
  YYSYMBOL_import = 72,                    /* import  */
  YYSYMBOL_declarations = 73,              /* declarations  */
  YYSYMBOL_decl_only = 74,                 /* decl_only  */
  YYSYMBOL_curve_decl = 75,                /* curve_decl  */
  YYSYMBOL_curve_decl_list = 76,           /* curve_decl_list  */
  YYSYMBOL_decl_id_list = 77,              /* decl_id_list  */
  YYSYMBOL_decl_id = 78,                   /* decl_id  */
  YYSYMBOL_decl_id2 = 79,                  /* decl_id2  */
  YYSYMBOL_decl_assgn = 80,                /* decl_assgn  */
  YYSYMBOL_curveAssignList = 81,           /* curveAssignList  */
  YYSYMBOL_curve_assign = 82,              /* curve_assign  */
  YYSYMBOL_assignList = 83,                /* assignList  */
  YYSYMBOL_assign_decl = 84,               /* assign_decl  */
  YYSYMBOL_assign = 85,                    /* assign  */
  YYSYMBOL_augAssign = 86,                 /* augAssign  */
  YYSYMBOL_initializerList = 87,           /* initializerList  */
  YYSYMBOL_multi_assign = 88,              /* multi_assign  */
  YYSYMBOL_idlist = 89,                    /* idlist  */
  YYSYMBOL_lhs = 90,                       /* lhs  */
  YYSYMBOL_rhs = 91,                       /* rhs  */
  YYSYMBOL_and = 92,                       /* and  */
  YYSYMBOL_comparision = 93,               /* comparision  */
  YYSYMBOL_compare_op = 94,                /* compare_op  */
  YYSYMBOL_plus = 95,                      /* plus  */
  YYSYMBOL_product = 96,                   /* product  */
  YYSYMBOL_mod = 97,                       /* mod  */
  YYSYMBOL_division = 98,                  /* division  */
  YYSYMBOL_bit_or = 99,                    /* bit_or  */
  YYSYMBOL_bit_and = 100,                  /* bit_and  */
  YYSYMBOL_shift = 101,                    /* shift  */
  YYSYMBOL_power = 102,                    /* power  */
  YYSYMBOL_unary_op = 103,                 /* unary_op  */
  YYSYMBOL_final = 104,                    /* final  */
  YYSYMBOL_value = 105,                    /* value  */
  YYSYMBOL_number = 106,                   /* number  */
  YYSYMBOL_ret = 107,                      /* ret  */
  YYSYMBOL_call = 108,                     /* call  */
  YYSYMBOL_obj_call = 109,                 /* obj_call  */
  YYSYMBOL_name = 110,                     /* name  */
  YYSYMBOL_starred_name = 111,             /* starred_name  */
  YYSYMBOL_arglist = 112,                  /* arglist  */
  YYSYMBOL_differentiate = 113,            /* differentiate  */
  YYSYMBOL_conditional = 114,              /* conditional  */
  YYSYMBOL_ifBlock = 115,                  /* ifBlock  */
  YYSYMBOL_loop = 116,                     /* loop  */
  YYSYMBOL_forLoop = 117,                  /* forLoop  */
  YYSYMBOL_loopVals = 118                  /* loopVals  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  27
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   372

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  62
/* YYNRULES -- Number of rules.  */
#define YYNRULES  157
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  292

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   290


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    56,     2,     2,     2,    50,    53,     2,
      39,    40,    42,    48,    41,    49,     2,    51,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    36,
      43,    47,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    45,     2,    46,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    37,    52,    38,    55,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    21,    21,    22,    24,    25,    27,    28,    29,    30,
      32,    34,    36,    37,    38,    39,    41,    42,    44,    45,
      46,    47,    49,    50,    51,    53,    54,    56,    57,    59,
      61,    62,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    78,    80,    81,    83,    84,
      86,    87,    89,    90,    92,    93,    95,    96,    98,    99,
     102,   103,   105,   106,   108,   109,   111,   112,   113,   114,
     115,   116,   118,   119,   121,   122,   124,   126,   127,   129,
     130,   132,   133,   135,   138,   139,   141,   142,   144,   145,
     147,   148,   149,   152,   153,   154,   156,   157,   159,   160,
     162,   163,   166,   167,   169,   170,   172,   173,   175,   176,
     179,   180,   183,   184,   185,   186,   187,   188,   189,   191,
     192,   194,   195,   196,   197,   198,   199,   200,   201,   202,
     204,   205,   207,   208,   210,   212,   218,   219,   220,   221,
     223,   224,   225,   227,   228,   229,   231,   232,   235,   236,
     238,   240,   241,   243,   244,   245,   247,   248
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "DATA_TYPE",
  "IDENTIFIER", "STRING", "IN", "DOTS", "CHAR", "RETURN", "INTEGER",
  "CURVE", "FOR", "STRUCT", "AUG_ASSIGN", "DIFF", "VOID", "ARROW",
  "COMPARE", "AND", "OR", "SHIFT", "DECREMENT", "INCREMENT", "REAL",
  "NEWLINE", "IF", "ELSE", "REPEAT", "UNTIL", "BREAK", "CONTINUE",
  "IMPORT", "TRUE", "FALSE", "FUNC", "';'", "'{'", "'}'", "'('", "')'",
  "','", "'*'", "'<'", "'>'", "'['", "']'", "'='", "'+'", "'-'", "'%'",
  "'/'", "'|'", "'&'", "'^'", "'~'", "'!'", "$accept", "start", "program",
  "global_decl", "struct", "function", "funcDef", "parameters",
  "type_defs", "type", "parameter", "typelist", "block", "statements",
  "statement", "import", "declarations", "decl_only", "curve_decl",
  "curve_decl_list", "decl_id_list", "decl_id", "decl_id2", "decl_assgn",
  "curveAssignList", "curve_assign", "assignList", "assign_decl", "assign",
  "augAssign", "initializerList", "multi_assign", "idlist", "lhs", "rhs",
  "and", "comparision", "compare_op", "plus", "product", "mod", "division",
  "bit_or", "bit_and", "shift", "power", "unary_op", "final", "value",
  "number", "ret", "call", "obj_call", "name", "starred_name", "arglist",
  "differentiate", "conditional", "ifBlock", "loop", "forLoop", "loopVals", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-240)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     126,   -14,  -240,    89,    91,  -240,  -240,   104,   164,   124,
    -240,   218,  -240,  -240,    10,  -240,    95,   144,  -240,   101,
    -240,   109,   137,   150,   184,   158,   194,  -240,  -240,  -240,
      10,   168,   170,  -240,  -240,  -240,    97,   214,    89,   186,
    -240,   191,   300,  -240,   199,  -240,    10,   215,   144,  -240,
    -240,    50,  -240,   201,   207,    61,     8,   110,    89,   242,
     210,   158,   219,   212,   223,  -240,    12,    11,  -240,   222,
     300,   225,  -240,   226,   227,    23,  -240,   231,   234,    68,
    -240,  -240,   248,  -240,  -240,    76,   170,   233,  -240,  -240,
     264,  -240,   186,    14,  -240,   123,  -240,    17,   268,   238,
    -240,  -240,  -240,   235,    34,    34,  -240,  -240,  -240,  -240,
     268,    34,    34,    34,    -9,   263,    84,   130,   243,   236,
     244,   237,   240,   273,   230,  -240,    52,  -240,  -240,  -240,
    -240,    68,  -240,   249,   256,  -240,   292,   268,   270,   268,
    -240,  -240,  -240,    18,  -240,   261,   -17,   265,  -240,  -240,
    -240,  -240,  -240,  -240,   268,   177,  -240,  -240,   301,   268,
     300,  -240,   143,  -240,  -240,  -240,    89,  -240,  -240,   241,
    -240,   304,   295,   153,   268,  -240,  -240,    63,  -240,  -240,
    -240,   268,  -240,   268,  -240,  -240,  -240,   268,   268,   268,
     268,   268,   268,   268,   268,   268,   268,  -240,  -240,  -240,
     268,    89,    15,    86,   279,   115,  -240,     0,   268,   232,
      19,   295,   268,  -240,   272,   295,    49,   286,    51,  -240,
    -240,  -240,  -240,  -240,  -240,   268,    69,  -240,   263,    84,
     130,   243,   243,   236,   244,   237,   240,   273,   230,  -240,
     295,  -240,   300,  -240,   320,   158,   268,   305,   328,  -240,
     167,   268,   295,   296,   -17,  -240,   131,   295,   268,  -240,
     295,   268,  -240,    16,  -240,   116,   158,  -240,  -240,   135,
     268,  -240,   268,   172,    66,  -240,    74,  -240,  -240,  -240,
     183,   295,  -240,   324,  -240,    16,  -240,  -240,   293,   158,
    -240,  -240
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    26,    23,     0,     0,    24,     3,     0,     0,     0,
       2,     5,     8,     7,     0,     9,     0,     0,    22,    51,
      53,    49,     0,     0,     0,     0,     0,     1,     4,    59,
       0,    48,    55,    57,     6,    27,     0,     0,     0,    47,
      45,     0,    31,    11,     0,    58,     0,     0,     0,    25,
      81,     0,    52,     0,     0,     0,   138,     0,     0,     0,
       0,     0,     0,     0,     0,    44,     0,     0,    41,     0,
      31,     0,    80,     0,     0,     0,    35,     0,     0,    83,
     139,    36,   148,    37,    38,     0,    54,     0,    28,    50,
       0,    10,    47,     0,    15,     0,    16,     0,   145,   138,
     122,   123,   131,     0,     0,     0,   130,   124,   125,   133,
       0,     0,     0,     0,     0,    85,    87,    89,    95,    97,
      99,   101,   103,   105,   107,   109,   118,   119,   121,   127,
     128,   126,   129,    65,    61,    63,     0,     0,     0,     0,
      42,    43,   142,     0,   141,    59,    69,    60,    67,    29,
      30,    32,    34,    33,     0,     0,    39,    40,     0,     0,
       0,    13,     0,    56,    82,    46,     0,    20,    14,     0,
      18,     0,   143,     0,     0,   116,   114,     0,   111,   110,
     112,     0,   132,     0,    92,    90,    91,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   115,   113,
       0,     0,     0,     0,     0,     0,   138,     0,   145,     0,
       0,    76,     0,    79,     0,    74,   126,   136,     0,   149,
      12,    21,    17,    19,   134,     0,     0,   120,    84,    86,
      88,    93,    94,    96,    98,   100,   102,   104,   106,   108,
      64,    62,   157,   156,     0,     0,     0,     0,     0,   140,
       0,     0,    72,    59,    68,    66,     0,    78,   145,   137,
     144,     0,   155,     0,   150,     0,     0,   136,    71,     0,
     145,    75,     0,     0,     0,   157,     0,   152,   151,    73,
       0,    77,   135,     0,   146,     0,   153,    70,     0,     0,
     147,   154
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -240,  -240,   327,  -240,  -240,  -240,  -240,   255,   174,    -7,
    -240,  -240,   -25,   271,  -154,  -240,   252,   -30,     5,  -240,
    -240,   -33,   315,  -240,  -240,   145,  -240,   138,  -240,  -240,
      96,   195,  -240,   196,   -55,   171,   166,  -240,   169,    39,
     163,   173,   162,   165,   161,   175,   176,   209,  -240,  -240,
    -240,   -39,   -37,   -38,   291,  -201,  -240,  -240,  -240,  -240,
    -240,  -239
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    13,    25,    95,    96,    14,
      18,    36,    68,    69,    70,    15,    53,    16,   133,    21,
      31,    32,    33,    71,   134,   135,   147,   148,    72,    73,
     256,    74,    51,    75,   172,   115,   116,   187,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
      76,   129,   130,   131,    80,   173,   132,    81,    82,    83,
      84,   244
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      43,    26,   114,    77,    79,    78,   219,   250,    20,    54,
      35,   181,   -23,    86,    29,   145,   142,   248,    19,   242,
     275,   170,   206,   253,   276,   243,   243,   182,    47,    17,
     209,    77,    79,    78,   146,    67,   138,   154,    99,   100,
     249,    88,   101,    52,   102,   159,   289,    98,    97,   103,
     -23,   143,    30,    30,    66,   177,   166,   273,   106,   171,
      66,    30,    54,    67,     1,     2,   158,   107,   108,   280,
     155,   181,    93,   110,   197,   198,    66,     5,    97,     1,
       2,   285,   203,   181,   205,   158,   181,    93,   262,   181,
      89,    90,     5,    19,   159,    22,   -83,   259,   167,   211,
     215,    94,   184,   227,   218,   207,   181,   283,   199,    23,
     261,    42,   284,   159,    99,   100,   161,   216,   101,   226,
     102,    77,    79,    78,    27,   103,   245,   185,   186,     1,
       2,    34,   104,   105,   106,   181,   181,     3,    48,     4,
      37,    49,     5,   107,   108,   240,   109,     1,     2,   110,
      38,     6,    66,    67,   252,   247,   277,   257,     7,   111,
       5,     8,    97,   168,   169,   112,   113,     1,     2,   271,
     260,   221,   272,   279,    39,    24,   272,   254,   188,   189,
       5,    99,   100,   220,   169,   101,    40,   102,    41,     1,
       2,   265,   103,   224,   225,    42,   257,     3,    44,   104,
     105,   106,     5,    77,    79,    78,   274,   268,   225,    46,
     107,   108,   282,   225,   212,    47,   110,   281,    50,    66,
     264,     1,     2,   287,   225,    87,   111,   231,   232,     3,
      55,     4,   112,   113,     5,    67,    99,   100,    85,    91,
     101,   278,   102,    92,     1,     2,   136,   103,   140,   137,
       7,   286,    93,     8,   104,   105,   106,     5,   139,   141,
     149,   151,   152,   153,   291,   107,   108,   156,   164,   251,
     157,   110,    99,   100,    66,   160,   101,    98,   102,   163,
     174,   111,   183,   103,   196,   190,   191,   112,   113,   193,
     104,   105,   106,   194,   195,   192,   200,   201,   202,   204,
     208,   107,   108,     1,    56,   217,   210,   110,   223,    57,
      66,    58,    59,   175,   176,   181,     5,   111,   246,   155,
     178,   179,   180,   112,   113,   258,    60,   263,    61,    62,
      63,    64,   267,   266,   288,   270,    65,    42,    28,   290,
     162,   150,    66,   222,   165,    45,   241,   269,   255,   229,
     213,   214,   228,   233,   235,   237,   230,   144,   236,     0,
       0,     0,     0,     0,   234,     0,     0,     0,     0,     0,
     238,     0,   239
};

static const yytype_int16 yycheck[] =
{
      25,     8,    57,    42,    42,    42,   160,   208,     3,    39,
      17,    20,     4,    46,     4,     4,     4,    17,     4,     4,
       4,     4,     4,     4,   263,    10,    10,    36,    45,    43,
      47,    70,    70,    70,    67,    42,    61,    14,     4,     5,
      40,    48,     8,    38,    10,    45,   285,    39,    55,    15,
      42,    39,    42,    42,    42,   110,    42,   258,    24,    42,
      42,    42,    92,    70,     3,     4,    17,    33,    34,   270,
      47,    20,    11,    39,    22,    23,    42,    16,    85,     3,
       4,     7,   137,    20,   139,    17,    20,    11,   242,    20,
      40,    41,    16,     4,    45,     4,    47,    46,    93,   154,
     155,    40,    18,    40,   159,   143,    20,    41,    56,     5,
      41,    37,    46,    45,     4,     5,    40,   155,     8,   174,
      10,   160,   160,   160,     0,    15,    40,    43,    44,     3,
       4,    36,    22,    23,    24,    20,    20,    11,    41,    13,
      39,    44,    16,    33,    34,   200,    36,     3,     4,    39,
      41,    25,    42,   160,   209,    40,    40,   212,    32,    49,
      16,    35,   169,    40,    41,    55,    56,     3,     4,    38,
     225,   166,    41,    38,    37,    11,    41,   210,    48,    49,
      16,     4,     5,    40,    41,     8,    36,    10,     4,     3,
       4,   246,    15,    40,    41,    37,   251,    11,     4,    22,
      23,    24,    16,   242,   242,   242,   261,    40,    41,    41,
      33,    34,    40,    41,    37,    45,    39,   272,     4,    42,
     245,     3,     4,    40,    41,    10,    49,   188,   189,    11,
      39,    13,    55,    56,    16,   242,     4,     5,    39,    38,
       8,   266,    10,    36,     3,     4,     4,    15,    36,    39,
      32,   276,    11,    35,    22,    23,    24,    16,    39,    36,
      38,    36,    36,    36,   289,    33,    34,    36,     4,    37,
      36,    39,     4,     5,    42,    27,     8,    39,    10,    46,
      45,    49,    19,    15,    54,    42,    50,    55,    56,    52,
      22,    23,    24,    53,    21,    51,    47,    41,     6,    29,
      39,    33,    34,     3,     4,     4,    41,    39,     4,     9,
      42,    11,    12,   104,   105,    20,    16,    49,    39,    47,
     111,   112,   113,    55,    56,    39,    26,     7,    28,    29,
      30,    31,     4,    28,    10,    39,    36,    37,    11,    46,
      85,    70,    42,   169,    92,    30,   201,   251,   210,   183,
     155,   155,   181,   190,   192,   194,   187,    66,   193,    -1,
      -1,    -1,    -1,    -1,   191,    -1,    -1,    -1,    -1,    -1,
     195,    -1,   196
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,    11,    13,    16,    25,    32,    35,    58,
      59,    60,    61,    62,    66,    72,    74,    43,    67,     4,
      75,    76,     4,     5,    11,    63,    66,     0,    59,     4,
      42,    77,    78,    79,    36,    66,    68,    39,    41,    37,
      36,     4,    37,    69,     4,    79,    41,    45,    41,    44,
       4,    89,    75,    73,    74,    39,     4,     9,    11,    12,
      26,    28,    29,    30,    31,    36,    42,    66,    69,    70,
      71,    80,    85,    86,    88,    90,   107,   108,   109,   110,
     111,   114,   115,   116,   117,    39,    78,    10,    66,    40,
      41,    38,    36,    11,    40,    64,    65,    66,    39,     4,
       5,     8,    10,    15,    22,    23,    24,    33,    34,    36,
      39,    49,    55,    56,    91,    92,    93,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   108,
     109,   110,   113,    75,    81,    82,     4,    39,    69,    39,
      36,    36,     4,    39,   111,     4,    78,    83,    84,    38,
      70,    36,    36,    36,    14,    47,    36,    36,    17,    45,
      27,    40,    64,    46,     4,    73,    42,    75,    40,    41,
       4,    42,    91,   112,    45,   104,   104,    91,   104,   104,
     104,    20,    36,    19,    18,    43,    44,    94,    48,    49,
      42,    50,    51,    52,    53,    21,    54,    22,    23,    56,
      47,    41,     6,    91,    29,    91,     4,   110,    39,    47,
      41,    91,    37,    88,    90,    91,   110,     4,    91,    71,
      40,    75,    65,     4,    40,    41,    91,    40,    92,    93,
      95,    96,    96,    97,    98,    99,   100,   101,   102,   103,
      91,    82,     4,    10,   118,    40,    39,    40,    17,    40,
     112,    37,    91,     4,    78,    84,    87,    91,    39,    46,
      91,    41,    71,     7,    69,    91,    28,     4,    40,    87,
      39,    38,    41,   112,    91,     4,   118,    40,    69,    38,
     112,    91,    40,    41,    46,     7,    69,    40,    10,   118,
      46,    69
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    58,    59,    59,    60,    60,    60,    60,
      61,    62,    63,    63,    63,    63,    64,    64,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    72,    73,    73,    74,    74,
      75,    75,    76,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    83,    83,    83,
      83,    83,    84,    84,    85,    85,    86,    87,    87,    88,
      88,    89,    89,    90,    91,    91,    92,    92,    93,    93,
      94,    94,    94,    95,    95,    95,    96,    96,    97,    97,
      98,    98,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   105,   105,   105,   105,   105,   105,   105,   105,   105,
     106,   106,   107,   107,   108,   109,   110,   110,   110,   110,
     111,   111,   111,   112,   112,   112,   113,   113,   114,   114,
     115,   116,   116,   117,   117,   117,   118,   118
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     2,     1,     1,     1,
       5,     3,     5,     4,     5,     4,     1,     3,     2,     3,
       2,     3,     2,     1,     1,     3,     0,     1,     3,     3,
       2,     0,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     1,     3,     3,     0,     2,     2,
       4,     1,     3,     1,     3,     1,     4,     1,     2,     1,
       2,     2,     3,     1,     3,     1,     3,     1,     3,     1,
       6,     4,     3,     5,     3,     5,     3,     3,     1,     3,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       2,     2,     2,     2,     2,     2,     2,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     2,     4,     6,     3,     4,     1,     1,
       4,     2,     2,     1,     3,     0,     6,     8,     1,     3,
       5,     6,     6,     7,     9,     5,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* start: NEWLINE  */
#line 22 "src/lexer/parser.y"
                           {printf(" : invalid program"); exit(0);}
#line 1412 "src/lexer/y.tab.c"
    break;


#line 1416 "src/lexer/y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 250 "src/lexer/parser.y"


void yyerror(char * msg){
    printf("%s\n",msg);
}

int main(int argc, char *argv[]){


    if (argc != 3){
        printf("Format not Used: [executable] [input file] [c output file]\n");
        assert(0);
    }
 
 
    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2],"w");

    yyparse();

    
    return 0;
}
