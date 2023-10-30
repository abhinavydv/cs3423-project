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

    extern FILE  * yyin, *yyout, *parsed_file;
    int yylex();
    void yyerror(char * msg);

    void label(char * msg){
        fprintf(parsed_file," /* %s */ ",msg);
    }


#line 87 "src/lexer/y.tab.c"

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
  YYSYMBOL_DOT = 28,                       /* DOT  */
  YYSYMBOL_REPEAT = 29,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 30,                     /* UNTIL  */
  YYSYMBOL_BREAK = 31,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 32,                  /* CONTINUE  */
  YYSYMBOL_IMPORT = 33,                    /* IMPORT  */
  YYSYMBOL_TRUE = 34,                      /* TRUE  */
  YYSYMBOL_FALSE = 35,                     /* FALSE  */
  YYSYMBOL_FUNC = 36,                      /* FUNC  */
  YYSYMBOL_37_ = 37,                       /* ';'  */
  YYSYMBOL_38_ = 38,                       /* '{'  */
  YYSYMBOL_39_ = 39,                       /* '}'  */
  YYSYMBOL_40_ = 40,                       /* '('  */
  YYSYMBOL_41_ = 41,                       /* ')'  */
  YYSYMBOL_42_ = 42,                       /* ','  */
  YYSYMBOL_43_ = 43,                       /* '<'  */
  YYSYMBOL_44_ = 44,                       /* '>'  */
  YYSYMBOL_45_ = 45,                       /* '*'  */
  YYSYMBOL_46_ = 46,                       /* '['  */
  YYSYMBOL_47_ = 47,                       /* ']'  */
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_49_ = 49,                       /* '+'  */
  YYSYMBOL_50_ = 50,                       /* '-'  */
  YYSYMBOL_51_ = 51,                       /* '%'  */
  YYSYMBOL_52_ = 52,                       /* '/'  */
  YYSYMBOL_53_ = 53,                       /* '|'  */
  YYSYMBOL_54_ = 54,                       /* '&'  */
  YYSYMBOL_55_ = 55,                       /* '^'  */
  YYSYMBOL_56_ = 56,                       /* '~'  */
  YYSYMBOL_57_ = 57,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_start = 59,                     /* start  */
  YYSYMBOL_program = 60,                   /* program  */
  YYSYMBOL_global_decl = 61,               /* global_decl  */
  YYSYMBOL_struct = 62,                    /* struct  */
  YYSYMBOL_63_1 = 63,                      /* $@1  */
  YYSYMBOL_function = 64,                  /* function  */
  YYSYMBOL_funcDef = 65,                   /* funcDef  */
  YYSYMBOL_parameters = 66,                /* parameters  */
  YYSYMBOL_type_defs = 67,                 /* type_defs  */
  YYSYMBOL_type = 68,                      /* type  */
  YYSYMBOL_temp_params = 69,               /* temp_params  */
  YYSYMBOL_typelist = 70,                  /* typelist  */
  YYSYMBOL_block = 71,                     /* block  */
  YYSYMBOL_statements = 72,                /* statements  */
  YYSYMBOL_statement = 73,                 /* statement  */
  YYSYMBOL_import = 74,                    /* import  */
  YYSYMBOL_declarations = 75,              /* declarations  */
  YYSYMBOL_76_2 = 76,                      /* $@2  */
  YYSYMBOL_decl_only = 77,                 /* decl_only  */
  YYSYMBOL_curve_decl_list = 78,           /* curve_decl_list  */
  YYSYMBOL_curve_decl = 79,                /* curve_decl  */
  YYSYMBOL_decl_id_list = 80,              /* decl_id_list  */
  YYSYMBOL_decl_id = 81,                   /* decl_id  */
  YYSYMBOL_decl_id2 = 82,                  /* decl_id2  */
  YYSYMBOL_decl_assgn = 83,                /* decl_assgn  */
  YYSYMBOL_curveAssignList = 84,           /* curveAssignList  */
  YYSYMBOL_curve_assign = 85,              /* curve_assign  */
  YYSYMBOL_assignList = 86,                /* assignList  */
  YYSYMBOL_assign_decl = 87,               /* assign_decl  */
  YYSYMBOL_assign = 88,                    /* assign  */
  YYSYMBOL_augAssign = 89,                 /* augAssign  */
  YYSYMBOL_initializerList = 90,           /* initializerList  */
  YYSYMBOL_multi_assign = 91,              /* multi_assign  */
  YYSYMBOL_idlist = 92,                    /* idlist  */
  YYSYMBOL_lhs = 93,                       /* lhs  */
  YYSYMBOL_rhs = 94,                       /* rhs  */
  YYSYMBOL_and = 95,                       /* and  */
  YYSYMBOL_comparision = 96,               /* comparision  */
  YYSYMBOL_compare_op = 97,                /* compare_op  */
  YYSYMBOL_plus = 98,                      /* plus  */
  YYSYMBOL_product = 99,                   /* product  */
  YYSYMBOL_mod = 100,                      /* mod  */
  YYSYMBOL_division = 101,                 /* division  */
  YYSYMBOL_bit_or = 102,                   /* bit_or  */
  YYSYMBOL_bit_and = 103,                  /* bit_and  */
  YYSYMBOL_shift = 104,                    /* shift  */
  YYSYMBOL_power = 105,                    /* power  */
  YYSYMBOL_unary_op = 106,                 /* unary_op  */
  YYSYMBOL_final = 107,                    /* final  */
  YYSYMBOL_value = 108,                    /* value  */
  YYSYMBOL_number = 109,                   /* number  */
  YYSYMBOL_ret = 110,                      /* ret  */
  YYSYMBOL_call = 111,                     /* call  */
  YYSYMBOL_obj_call = 112,                 /* obj_call  */
  YYSYMBOL_arglist = 113,                  /* arglist  */
  YYSYMBOL_name = 114,                     /* name  */
  YYSYMBOL_starred_name = 115,             /* starred_name  */
  YYSYMBOL_differentiate = 116,            /* differentiate  */
  YYSYMBOL_conditional = 117,              /* conditional  */
  YYSYMBOL_118_3 = 118,                    /* $@3  */
  YYSYMBOL_ifBlock = 119,                  /* ifBlock  */
  YYSYMBOL_120_4 = 120,                    /* $@4  */
  YYSYMBOL_loop = 121,                     /* loop  */
  YYSYMBOL_122_5 = 122,                    /* $@5  */
  YYSYMBOL_123_6 = 123,                    /* $@6  */
  YYSYMBOL_forLoop = 124,                  /* forLoop  */
  YYSYMBOL_125_7 = 125,                    /* $@7  */
  YYSYMBOL_126_8 = 126,                    /* $@8  */
  YYSYMBOL_127_9 = 127,                    /* $@9  */
  YYSYMBOL_128_10 = 128,                   /* $@10  */
  YYSYMBOL_loopVals = 129                  /* loopVals  */
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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   411

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  72
/* YYNRULES -- Number of rules.  */
#define YYNRULES  169
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  313

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


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
       2,     2,     2,    57,     2,     2,     2,    51,    54,     2,
      40,    41,    45,    49,    42,    50,     2,    52,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    37,
      43,    48,    44,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,    47,    55,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,    53,    39,    56,     2,     2,     2,
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
      35,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    25,    25,    26,    29,    30,    33,    34,    35,    36,
      37,    40,    40,    43,    46,    47,    48,    49,    52,    53,
      56,    57,    59,    60,    61,    64,    65,    67,    68,    71,
      73,    74,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    92,    95,    95,    96,    99,
     100,   103,   104,   107,   108,   111,   112,   115,   116,   119,
     120,   123,   124,   127,   128,   131,   132,   135,   136,   137,
     138,   139,   140,   143,   144,   147,   148,   151,   154,   155,
     158,   159,   162,   163,   166,   169,   170,   172,   173,   176,
     177,   179,   180,   181,   184,   185,   186,   188,   189,   191,
     192,   194,   195,   198,   199,   201,   202,   204,   205,   208,
     209,   212,   213,   216,   217,   218,   219,   220,   221,   222,
     224,   225,   229,   230,   231,   232,   233,   234,   235,   236,
     237,   240,   241,   244,   245,   248,   251,   252,   255,   256,
     257,   260,   261,   262,   263,   264,   267,   268,   269,   271,
     272,   276,   277,   277,   280,   280,   283,   283,   284,   284,
     287,   287,   288,   288,   289,   289,   290,   290,   292,   293
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
  "NEWLINE", "IF", "ELSE", "DOT", "REPEAT", "UNTIL", "BREAK", "CONTINUE",
  "IMPORT", "TRUE", "FALSE", "FUNC", "';'", "'{'", "'}'", "'('", "')'",
  "','", "'<'", "'>'", "'*'", "'['", "']'", "'='", "'+'", "'-'", "'%'",
  "'/'", "'|'", "'&'", "'^'", "'~'", "'!'", "$accept", "start", "program",
  "global_decl", "struct", "$@1", "function", "funcDef", "parameters",
  "type_defs", "type", "temp_params", "typelist", "block", "statements",
  "statement", "import", "declarations", "$@2", "decl_only",
  "curve_decl_list", "curve_decl", "decl_id_list", "decl_id", "decl_id2",
  "decl_assgn", "curveAssignList", "curve_assign", "assignList",
  "assign_decl", "assign", "augAssign", "initializerList", "multi_assign",
  "idlist", "lhs", "rhs", "and", "comparision", "compare_op", "plus",
  "product", "mod", "division", "bit_or", "bit_and", "shift", "power",
  "unary_op", "final", "value", "number", "ret", "call", "obj_call",
  "arglist", "name", "starred_name", "differentiate", "conditional", "$@3",
  "ifBlock", "$@4", "loop", "$@5", "$@6", "forLoop", "$@7", "$@8", "$@9",
  "$@10", "loopVals", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-258)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-170)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     368,   -14,  -258,     5,    21,  -258,  -258,    42,   216,    52,
    -258,   350,  -258,  -258,    26,  -258,    -4,   179,  -258,    29,
      26,    62,  -258,  -258,    38,  -258,    61,   122,   159,   131,
    -258,  -258,  -258,   104,  -258,  -258,  -258,    89,   147,  -258,
       5,   148,   115,  -258,   126,  -258,   176,  -258,   130,    26,
     179,  -258,  -258,   168,  -258,   117,   226,    45,     6,   105,
       5,   182,   153,  -258,   158,   166,   181,  -258,    28,    27,
    -258,   172,   176,   191,  -258,   206,   210,    66,  -258,   232,
     238,   106,  -258,  -258,   218,  -258,  -258,    78,  -258,  -258,
    -258,   273,  -258,   244,   253,    26,  -258,   174,  -258,    26,
     312,   251,  -258,  -258,  -258,   254,    30,    30,  -258,  -258,
    -258,  -258,   312,    30,    30,    30,    87,   280,    73,   151,
     259,   255,   258,   252,   257,   286,   260,  -258,     0,  -258,
    -258,  -258,  -258,   106,  -258,   265,   276,  -258,   315,   312,
     285,   312,  -258,  -258,  -258,    32,  -258,   288,   277,   284,
    -258,  -258,  -258,  -258,  -258,  -258,   312,   236,  -258,  -258,
     325,   328,   312,  -258,  -258,   192,  -258,  -258,  -258,  -258,
    -258,   269,  -258,   313,   194,   312,  -258,  -258,    56,  -258,
    -258,  -258,   312,  -258,   312,  -258,  -258,  -258,   312,   312,
     312,   312,   312,   312,   312,   312,   312,   312,  -258,  -258,
    -258,   312,     5,   133,    59,   307,   124,  -258,   108,   312,
     274,    33,   313,   312,  -258,   290,   313,    84,   299,   300,
      75,   176,  -258,   226,  -258,  -258,   312,    -1,  -258,   280,
      73,   151,   259,   259,   255,   258,   252,   257,   286,   260,
    -258,   313,  -258,   312,   334,   335,  -258,   303,   320,   347,
     352,  -258,   197,   312,   313,   318,   277,  -258,   -18,   313,
     312,   312,  -258,  -258,  -258,   313,   312,   140,   176,   340,
     285,   312,  -258,  -258,  -258,  -258,   152,   312,  -258,   312,
     208,   220,    -3,   353,  -258,   312,  -258,   358,  -258,   143,
     285,  -258,   222,   313,  -258,  -258,   349,  -258,   176,   149,
     340,   176,  -258,  -258,  -258,   323,  -258,  -258,  -258,  -258,
    -258,   176,  -258
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    26,    23,     0,     0,    24,     3,     0,     0,     0,
       2,     5,     9,     7,     0,    10,     0,     0,    22,    60,
       0,    50,    52,    54,    58,    11,     0,     0,     0,     0,
       1,     4,    60,    49,    56,     6,    27,     0,     0,    57,
       0,     0,     0,    45,     0,     8,    31,    13,     0,     0,
       0,    25,    82,     0,    51,     0,    48,     0,   144,     0,
       0,     0,     0,   158,     0,     0,     0,    44,     0,     0,
      41,     0,    31,     0,    81,     0,     0,     0,    35,     0,
       0,    84,   145,    36,   151,    37,    38,     0,    55,    28,
      53,     0,    59,     0,     0,     0,    17,     0,    18,     0,
     140,   144,   123,   124,   132,     0,     0,     0,   131,   125,
     126,   134,     0,     0,     0,     0,     0,    86,    88,    90,
      96,    98,   100,   102,   104,   106,   108,   110,   119,   120,
     122,   128,   129,   127,   130,    66,    62,    64,     0,     0,
       0,     0,    42,    43,   148,     0,   147,    60,    70,    61,
      68,    29,    30,    32,    34,    33,     0,     0,    39,    40,
       0,     0,     0,   152,    15,     0,    83,    12,    46,    21,
      16,     0,    20,   138,     0,     0,   117,   115,     0,   112,
     111,   113,     0,   133,     0,    93,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   118,   116,
     114,     0,     0,     0,     0,     0,     0,   144,     0,   140,
       0,     0,    77,     0,    80,     0,    75,   127,   141,   142,
       0,     0,    14,    48,    19,   135,     0,     0,   121,    85,
      87,    89,    94,    95,    97,    99,   101,   103,   105,   107,
     109,    65,    63,     0,   166,     0,   154,     0,     0,     0,
       0,   146,     0,     0,    73,    60,    69,    67,     0,    79,
     140,   140,   143,   153,    47,   139,     0,     0,     0,     0,
       0,     0,   156,   141,   142,    72,     0,   140,    76,     0,
       0,     0,     0,   164,   167,     0,   168,   160,   155,     0,
       0,    74,     0,    78,   136,   137,     0,   149,     0,     0,
       0,     0,   159,   157,    71,     0,   165,   169,   162,   161,
     150,     0,   163
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -258,  -258,   356,  -258,  -258,  -258,  -258,  -258,   289,   202,
       3,  -258,  -258,   -22,   305,  -205,  -258,   155,  -258,   -52,
    -258,    15,  -258,    -7,  -258,  -258,  -258,   180,  -258,   177,
    -258,  -258,   134,   233,  -258,   234,   -54,   207,   211,  -258,
     204,    98,   203,   205,   209,   212,   201,   213,   214,   188,
    -195,  -258,  -258,   -45,   -44,  -194,   -46,   330,  -258,  -258,
    -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,  -258,
    -258,  -257
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    42,    13,    28,    97,    98,
      69,    18,    37,    70,    71,    72,    15,    93,   223,    16,
      21,   135,    33,    23,    24,    73,   136,   137,   149,   150,
      74,    75,   258,    76,    53,    77,   173,   117,   118,   188,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,    78,   131,   132,   174,   133,    82,   134,    83,
     221,    84,   270,    85,   290,   140,    86,   301,   311,   298,
     268,   245
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    79,    80,    14,    94,   116,    47,    34,   244,    19,
     -23,    29,   287,    39,    14,   252,   263,   182,    22,   182,
      36,   278,   198,   199,   279,    25,    81,    79,    80,    17,
      32,   147,   144,    35,   101,   102,   207,   255,   103,   296,
     104,   266,    88,   308,   297,   105,   100,    26,     1,     2,
      20,   -23,    30,    89,   108,    54,    95,   200,   178,    14,
      99,     5,   148,   284,   109,   110,   280,   281,   145,    38,
     112,    20,    20,    68,   286,    68,   182,    68,    20,   182,
     156,     1,     2,   292,    41,   204,    96,   206,   169,    95,
      99,   185,   172,   306,     5,   182,   309,   228,    43,   208,
     246,   160,   212,   216,    40,   286,   312,   182,   220,   101,
     102,   217,   161,   103,   157,   104,   186,   187,   205,   164,
     105,   227,   262,   160,   183,   249,    44,   106,   107,   108,
     162,    50,   -84,    51,   161,    48,   250,   101,   102,   109,
     110,   103,   111,   104,   182,   112,    49,   241,   105,   251,
      68,    52,   162,    56,   162,   113,   254,   108,    55,   259,
     182,   114,   115,   182,    92,   248,    57,   109,   110,   182,
      87,    94,   265,   243,    99,    81,    79,    80,    68,     1,
      58,   283,     1,     2,   302,    59,   138,    60,    61,   267,
     307,   291,     5,   139,   279,     5,    45,    46,   141,   259,
     189,   190,    62,   142,   256,    63,    64,    65,    66,    90,
      91,   151,   282,    67,    46,   170,   171,   289,   143,     1,
       2,    68,    81,    79,    80,   293,    14,    27,   153,     1,
       2,   299,     5,   222,   171,   225,   226,     3,   275,   226,
     101,   102,     5,   154,   103,   163,   104,   155,   288,   294,
     226,   105,    81,    79,    80,    81,    79,    80,   106,   107,
     108,   295,   226,   304,   226,    81,    79,    80,   303,   158,
     109,   110,     1,     2,   213,   159,   112,   166,   101,   102,
      95,    68,   103,   167,   104,     5,   113,   232,   233,   105,
     168,   100,   114,   115,   176,   177,   106,   107,   108,   184,
     175,   179,   180,   181,   191,   194,   192,   196,   109,   110,
     193,   195,   253,   201,   112,   197,   101,   102,   202,    68,
     103,   203,   104,    46,   113,   210,   211,   105,   209,   218,
     114,   115,   219,   182,   106,   107,   108,   247,   157,   260,
     261,  -168,   269,   271,   101,   102,   109,   110,   103,   272,
     104,   273,   112,     1,     2,   105,   274,    68,   277,   305,
    -169,     3,   113,     4,   108,   300,     5,    31,   114,   115,
     310,     1,     2,   224,   109,   110,   165,   152,   264,     3,
     285,     4,   242,     7,     5,    68,     8,   276,   257,   229,
     214,   215,   231,     6,   234,   230,   238,   235,   146,     0,
       0,     7,   236,     0,     8,     0,   237,     0,     0,   239,
       0,   240
};

static const yytype_int16 yycheck[] =
{
      46,    46,    46,     0,    56,    59,    28,    14,   203,     4,
       4,     8,   269,    20,    11,   209,   221,    20,     3,    20,
      17,    39,    22,    23,    42,     4,    72,    72,    72,    43,
       4,     4,     4,    37,     4,     5,     4,     4,     8,    42,
      10,    42,    49,   300,    47,    15,    40,     5,     3,     4,
      45,    45,     0,    50,    24,    40,    11,    57,   112,    56,
      57,    16,    69,   268,    34,    35,   260,   261,    40,    40,
      40,    45,    45,    45,   269,    45,    20,    45,    45,    20,
      14,     3,     4,   277,    46,   139,    41,   141,    95,    11,
      87,    18,    99,   298,    16,    20,   301,    41,    37,   145,
      41,    17,   156,   157,    42,   300,   311,    20,   162,     4,
       5,   157,    28,     8,    48,    10,    43,    44,   140,    41,
      15,   175,    47,    17,    37,    17,     4,    22,    23,    24,
      46,    42,    48,    44,    28,     4,    28,     4,     5,    34,
      35,     8,    37,    10,    20,    40,    42,   201,    15,    41,
      45,     4,    46,    38,    46,    50,   210,    24,    10,   213,
      20,    56,    57,    20,    47,    41,    40,    34,    35,    20,
      40,   223,   226,    40,   171,   221,   221,   221,    45,     3,
       4,    41,     3,     4,    41,     9,     4,    11,    12,   243,
      41,    39,    16,    40,    42,    16,    37,    38,    40,   253,
      49,    50,    26,    37,   211,    29,    30,    31,    32,    41,
      42,    39,   266,    37,    38,    41,    42,   271,    37,     3,
       4,    45,   268,   268,   268,   279,   223,    11,    37,     3,
       4,   285,    16,    41,    42,    41,    42,    11,    41,    42,
       4,     5,    16,    37,     8,    27,    10,    37,   270,    41,
      42,    15,   298,   298,   298,   301,   301,   301,    22,    23,
      24,    41,    42,    41,    42,   311,   311,   311,   290,    37,
      34,    35,     3,     4,    38,    37,    40,     4,     4,     5,
      11,    45,     8,    39,    10,    16,    50,   189,   190,    15,
      37,    40,    56,    57,   106,   107,    22,    23,    24,    19,
      46,   113,   114,   115,    45,    53,    51,    21,    34,    35,
      52,    54,    38,    48,    40,    55,     4,     5,    42,    45,
       8,     6,    10,    38,    50,    48,    42,    15,    40,     4,
      56,    57,     4,    20,    22,    23,    24,    30,    48,    40,
      40,     7,     7,    40,     4,     5,    34,    35,     8,    29,
      10,     4,    40,     3,     4,    15,     4,    45,    40,    10,
       7,    11,    50,    13,    24,     7,    16,    11,    56,    57,
      47,     3,     4,   171,    34,    35,    87,    72,   223,    11,
      40,    13,   202,    33,    16,    45,    36,   253,   211,   182,
     157,   157,   188,    25,   191,   184,   195,   192,    68,    -1,
      -1,    33,   193,    -1,    36,    -1,   194,    -1,    -1,   196,
      -1,   197
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    11,    13,    16,    25,    33,    36,    59,
      60,    61,    62,    64,    68,    74,    77,    43,    69,     4,
      45,    78,    79,    81,    82,     4,     5,    11,    65,    68,
       0,    60,     4,    80,    81,    37,    68,    70,    40,    81,
      42,    46,    63,    37,     4,    37,    38,    71,     4,    42,
      42,    44,     4,    92,    79,    10,    38,    40,     4,     9,
      11,    12,    26,    29,    30,    31,    32,    37,    45,    68,
      71,    72,    73,    83,    88,    89,    91,    93,   110,   111,
     112,   114,   115,   117,   119,   121,   124,    40,    81,    68,
      41,    42,    47,    75,    77,    11,    41,    66,    67,    68,
      40,     4,     5,     8,    10,    15,    22,    23,    24,    34,
      35,    37,    40,    50,    56,    57,    94,    95,    96,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
     109,   111,   112,   114,   116,    79,    84,    85,     4,    40,
     123,    40,    37,    37,     4,    40,   115,     4,    81,    86,
      87,    39,    72,    37,    37,    37,    14,    48,    37,    37,
      17,    28,    46,    27,    41,    66,     4,    39,    37,    81,
      41,    42,    81,    94,   113,    46,   107,   107,    94,   107,
     107,   107,    20,    37,    19,    18,    43,    44,    97,    49,
      50,    45,    51,    52,    53,    54,    21,    55,    22,    23,
      57,    48,    42,     6,    94,    71,    94,     4,   114,    40,
      48,    42,    94,    38,    91,    93,    94,   114,     4,     4,
      94,   118,    41,    76,    67,    41,    42,    94,    41,    95,
      96,    98,    99,    99,   100,   101,   102,   103,   104,   105,
     106,    94,    85,    40,   108,   129,    41,    30,    41,    17,
      28,    41,   113,    38,    94,     4,    81,    87,    90,    94,
      40,    40,    47,    73,    75,    94,    42,    94,   128,     7,
     120,    40,    29,     4,     4,    41,    90,    40,    39,    42,
     113,   113,    94,    41,    73,    40,   108,   129,    71,    94,
     122,    39,   113,    94,    41,    41,    42,    47,   127,    94,
       7,   125,    41,    71,    41,    10,    73,    41,   129,    73,
      47,   126,    73
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    63,    62,    64,    65,    65,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    71,
      72,    72,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    76,    75,    75,    77,
      77,    78,    78,    79,    79,    80,    80,    81,    81,    82,
      82,    83,    83,    84,    84,    85,    85,    86,    86,    86,
      86,    86,    86,    87,    87,    88,    88,    89,    90,    90,
      91,    91,    92,    92,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    98,    98,    98,    99,    99,   100,
     100,   101,   101,   102,   102,   103,   103,   104,   104,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     107,   107,   108,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   111,   112,   112,   113,   113,
     113,   114,   114,   114,   114,   114,   115,   115,   115,   116,
     116,   117,   118,   117,   120,   119,   122,   121,   123,   121,
     125,   124,   126,   124,   127,   124,   128,   124,   129,   129
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     2,     1,     3,     1,
       1,     0,     6,     3,     5,     4,     5,     4,     1,     3,
       2,     2,     2,     1,     1,     3,     0,     1,     3,     3,
       2,     0,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     1,     3,     0,     4,     0,     2,
       2,     3,     1,     4,     1,     3,     1,     2,     1,     4,
       1,     2,     2,     3,     1,     3,     1,     3,     1,     3,
       1,     6,     4,     3,     5,     3,     5,     3,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     2,     2,     2,     2,     2,     2,     2,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     2,     4,     6,     6,     1,     3,
       0,     3,     3,     4,     1,     1,     4,     2,     2,     6,
       8,     1,     0,     4,     0,     6,     0,     7,     0,     7,
       0,     8,     0,    10,     0,     8,     0,     6,     1,     3
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
#line 26 "src/lexer/parser.y"
                           {printf(" : invalid program\n"); exit(0);}
#line 1448 "src/lexer/y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 40 "src/lexer/parser.y"
                                     {label("Struct def");}
#line 1454 "src/lexer/y.tab.c"
    break;

  case 14: /* funcDef: type IDENTIFIER '(' parameters ')'  */
#line 46 "src/lexer/parser.y"
                                                      {label("Function def");}
#line 1460 "src/lexer/y.tab.c"
    break;

  case 15: /* funcDef: type IDENTIFIER '(' ')'  */
#line 47 "src/lexer/parser.y"
                                           {label("Function def");}
#line 1466 "src/lexer/y.tab.c"
    break;

  case 16: /* funcDef: CURVE IDENTIFIER '(' parameters ')'  */
#line 48 "src/lexer/parser.y"
                                                       {label("Function def");}
#line 1472 "src/lexer/y.tab.c"
    break;

  case 17: /* funcDef: CURVE IDENTIFIER '(' ')'  */
#line 49 "src/lexer/parser.y"
                                            {label("Function def");}
#line 1478 "src/lexer/y.tab.c"
    break;

  case 32: /* statement: decl_assgn ';'  */
#line 77 "src/lexer/parser.y"
                                    {label("Declaration");}
#line 1484 "src/lexer/y.tab.c"
    break;

  case 33: /* statement: multi_assign ';'  */
#line 78 "src/lexer/parser.y"
                                    {label("Assignment");}
#line 1490 "src/lexer/y.tab.c"
    break;

  case 34: /* statement: augAssign ';'  */
#line 79 "src/lexer/parser.y"
                                    {label("Augmented Assignment");}
#line 1496 "src/lexer/y.tab.c"
    break;

  case 35: /* statement: ret  */
#line 80 "src/lexer/parser.y"
                                    {label("Return");}
#line 1502 "src/lexer/y.tab.c"
    break;

  case 39: /* statement: call ';'  */
#line 84 "src/lexer/parser.y"
                                    {label("Function Call");}
#line 1508 "src/lexer/y.tab.c"
    break;

  case 40: /* statement: obj_call ';'  */
#line 85 "src/lexer/parser.y"
                                    {label("Object Function Call");}
#line 1514 "src/lexer/y.tab.c"
    break;

  case 42: /* statement: BREAK ';'  */
#line 87 "src/lexer/parser.y"
                                    {label("Break");}
#line 1520 "src/lexer/y.tab.c"
    break;

  case 43: /* statement: CONTINUE ';'  */
#line 88 "src/lexer/parser.y"
                                    {label("Continue");}
#line 1526 "src/lexer/y.tab.c"
    break;

  case 46: /* $@2: %empty  */
#line 95 "src/lexer/parser.y"
                                 {label("Declaration");}
#line 1532 "src/lexer/y.tab.c"
    break;

  case 152: /* $@3: %empty  */
#line 277 "src/lexer/parser.y"
                                {label("Else stetement");}
#line 1538 "src/lexer/y.tab.c"
    break;

  case 154: /* $@4: %empty  */
#line 280 "src/lexer/parser.y"
                                  {label("If statement");}
#line 1544 "src/lexer/y.tab.c"
    break;

  case 156: /* $@5: %empty  */
#line 283 "src/lexer/parser.y"
                                            {label("Loop");}
#line 1550 "src/lexer/y.tab.c"
    break;

  case 158: /* $@6: %empty  */
#line 284 "src/lexer/parser.y"
                          {label("Loop");}
#line 1556 "src/lexer/y.tab.c"
    break;

  case 160: /* $@7: %empty  */
#line 287 "src/lexer/parser.y"
                                                            {label("For loop");}
#line 1562 "src/lexer/y.tab.c"
    break;

  case 162: /* $@8: %empty  */
#line 288 "src/lexer/parser.y"
                                                                          {label("For loop");}
#line 1568 "src/lexer/y.tab.c"
    break;

  case 164: /* $@9: %empty  */
#line 289 "src/lexer/parser.y"
                                                 {label("For loop");}
#line 1574 "src/lexer/y.tab.c"
    break;

  case 166: /* $@10: %empty  */
#line 290 "src/lexer/parser.y"
                                           {label("For loop");}
#line 1580 "src/lexer/y.tab.c"
    break;


#line 1584 "src/lexer/y.tab.c"

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

#line 295 "src/lexer/parser.y"


void yyerror(char * msg){
    printf("%s\n",msg);
    exit(1);
}

int main(int argc, char *argv[]){

    if (argc != 4){
        printf("Format not Used: [executable] [input file] [token file] [parsed file]\n");
        exit(1);
    }

    yyin = fopen(argv[1], "r");
    yyout = fopen(argv[2],"w");
    parsed_file = fopen(argv[3],"w");

    yyparse();

    fclose(yyin);
    fclose(yyout);
    fclose(parsed_file);
    return 0;
}
