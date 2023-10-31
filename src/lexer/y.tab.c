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

#line 86 "src/lexer/y.tab.c"

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
  YYSYMBOL_DOLLAR_ID = 12,                 /* DOLLAR_ID  */
  YYSYMBOL_FOR = 13,                       /* FOR  */
  YYSYMBOL_STRUCT = 14,                    /* STRUCT  */
  YYSYMBOL_AUG_ASSIGN = 15,                /* AUG_ASSIGN  */
  YYSYMBOL_DIFF = 16,                      /* DIFF  */
  YYSYMBOL_VOID = 17,                      /* VOID  */
  YYSYMBOL_ARROW = 18,                     /* ARROW  */
  YYSYMBOL_COMPARE = 19,                   /* COMPARE  */
  YYSYMBOL_AND = 20,                       /* AND  */
  YYSYMBOL_OR = 21,                        /* OR  */
  YYSYMBOL_SHIFT = 22,                     /* SHIFT  */
  YYSYMBOL_DECREMENT = 23,                 /* DECREMENT  */
  YYSYMBOL_INCREMENT = 24,                 /* INCREMENT  */
  YYSYMBOL_REAL = 25,                      /* REAL  */
  YYSYMBOL_NEWLINE = 26,                   /* NEWLINE  */
  YYSYMBOL_IF = 27,                        /* IF  */
  YYSYMBOL_ELSE = 28,                      /* ELSE  */
  YYSYMBOL_DOT = 29,                       /* DOT  */
  YYSYMBOL_REPEAT = 30,                    /* REPEAT  */
  YYSYMBOL_UNTIL = 31,                     /* UNTIL  */
  YYSYMBOL_BREAK = 32,                     /* BREAK  */
  YYSYMBOL_CONTINUE = 33,                  /* CONTINUE  */
  YYSYMBOL_IMPORT = 34,                    /* IMPORT  */
  YYSYMBOL_TRUE = 35,                      /* TRUE  */
  YYSYMBOL_FALSE = 36,                     /* FALSE  */
  YYSYMBOL_FUNC = 37,                      /* FUNC  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '{'  */
  YYSYMBOL_40_ = 40,                       /* '}'  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* ','  */
  YYSYMBOL_44_ = 44,                       /* '<'  */
  YYSYMBOL_45_ = 45,                       /* '>'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* '['  */
  YYSYMBOL_48_ = 48,                       /* ']'  */
  YYSYMBOL_49_ = 49,                       /* '='  */
  YYSYMBOL_50_ = 50,                       /* '+'  */
  YYSYMBOL_51_ = 51,                       /* '-'  */
  YYSYMBOL_52_ = 52,                       /* '%'  */
  YYSYMBOL_53_ = 53,                       /* '/'  */
  YYSYMBOL_54_ = 54,                       /* '|'  */
  YYSYMBOL_55_ = 55,                       /* '&'  */
  YYSYMBOL_56_ = 56,                       /* '^'  */
  YYSYMBOL_57_ = 57,                       /* '~'  */
  YYSYMBOL_58_ = 58,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 59,                  /* $accept  */
  YYSYMBOL_start = 60,                     /* start  */
  YYSYMBOL_program = 61,                   /* program  */
  YYSYMBOL_global_decl = 62,               /* global_decl  */
  YYSYMBOL_struct = 63,                    /* struct  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_function = 65,                  /* function  */
  YYSYMBOL_funcDef = 66,                   /* funcDef  */
  YYSYMBOL_ret_type = 67,                  /* ret_type  */
  YYSYMBOL_parameters = 68,                /* parameters  */
  YYSYMBOL_type_defs = 69,                 /* type_defs  */
  YYSYMBOL_type = 70,                      /* type  */
  YYSYMBOL_temp_params = 71,               /* temp_params  */
  YYSYMBOL_typelist = 72,                  /* typelist  */
  YYSYMBOL_block = 73,                     /* block  */
  YYSYMBOL_statements = 74,                /* statements  */
  YYSYMBOL_statement = 75,                 /* statement  */
  YYSYMBOL_import = 76,                    /* import  */
  YYSYMBOL_declarations = 77,              /* declarations  */
  YYSYMBOL_78_2 = 78,                      /* $@2  */
  YYSYMBOL_decl_only = 79,                 /* decl_only  */
  YYSYMBOL_curve_decl_list = 80,           /* curve_decl_list  */
  YYSYMBOL_curve_decl = 81,                /* curve_decl  */
  YYSYMBOL_decl_id_list = 82,              /* decl_id_list  */
  YYSYMBOL_decl_id = 83,                   /* decl_id  */
  YYSYMBOL_decl_id2 = 84,                  /* decl_id2  */
  YYSYMBOL_decl_assgn = 85,                /* decl_assgn  */
  YYSYMBOL_curveAssignList = 86,           /* curveAssignList  */
  YYSYMBOL_curve_assign = 87,              /* curve_assign  */
  YYSYMBOL_assignList = 88,                /* assignList  */
  YYSYMBOL_assign_decl = 89,               /* assign_decl  */
  YYSYMBOL_assign = 90,                    /* assign  */
  YYSYMBOL_augAssign = 91,                 /* augAssign  */
  YYSYMBOL_initializerList = 92,           /* initializerList  */
  YYSYMBOL_multi_assign = 93,              /* multi_assign  */
  YYSYMBOL_idlist = 94,                    /* idlist  */
  YYSYMBOL_lhs = 95,                       /* lhs  */
  YYSYMBOL_rhs = 96,                       /* rhs  */
  YYSYMBOL_and = 97,                       /* and  */
  YYSYMBOL_comparision = 98,               /* comparision  */
  YYSYMBOL_compare_op = 99,                /* compare_op  */
  YYSYMBOL_plus = 100,                     /* plus  */
  YYSYMBOL_product = 101,                  /* product  */
  YYSYMBOL_mod = 102,                      /* mod  */
  YYSYMBOL_division = 103,                 /* division  */
  YYSYMBOL_bit_or = 104,                   /* bit_or  */
  YYSYMBOL_bit_and = 105,                  /* bit_and  */
  YYSYMBOL_shift = 106,                    /* shift  */
  YYSYMBOL_power = 107,                    /* power  */
  YYSYMBOL_unary_op = 108,                 /* unary_op  */
  YYSYMBOL_unary_op_only = 109,            /* unary_op_only  */
  YYSYMBOL_final = 110,                    /* final  */
  YYSYMBOL_value = 111,                    /* value  */
  YYSYMBOL_number = 112,                   /* number  */
  YYSYMBOL_ret = 113,                      /* ret  */
  YYSYMBOL_call = 114,                     /* call  */
  YYSYMBOL_obj_call = 115,                 /* obj_call  */
  YYSYMBOL_arglist = 116,                  /* arglist  */
  YYSYMBOL_name = 117,                     /* name  */
  YYSYMBOL_starred_name = 118,             /* starred_name  */
  YYSYMBOL_differentiate = 119,            /* differentiate  */
  YYSYMBOL_conditional = 120,              /* conditional  */
  YYSYMBOL_121_3 = 121,                    /* $@3  */
  YYSYMBOL_ifBlock = 122,                  /* ifBlock  */
  YYSYMBOL_123_4 = 123,                    /* $@4  */
  YYSYMBOL_loop = 124,                     /* loop  */
  YYSYMBOL_125_5 = 125,                    /* $@5  */
  YYSYMBOL_126_6 = 126,                    /* $@6  */
  YYSYMBOL_forLoop = 127,                  /* forLoop  */
  YYSYMBOL_128_7 = 128,                    /* $@7  */
  YYSYMBOL_129_8 = 129,                    /* $@8  */
  YYSYMBOL_130_9 = 130,                    /* $@9  */
  YYSYMBOL_131_10 = 131,                   /* $@10  */
  YYSYMBOL_loopVals = 132                  /* loopVals  */
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
#define YYFINAL  31
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   529

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  173
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  316

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


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
       2,     2,     2,    58,     2,     2,     2,    52,    55,     2,
      41,    42,    46,    50,    43,    51,     2,    53,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      44,    49,    45,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    47,     2,    48,    56,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    39,    54,    40,    57,     2,     2,     2,
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
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    24,    24,    25,    28,    29,    32,    33,    34,    35,
      36,    39,    39,    42,    45,    46,    48,    49,    52,    53,
      56,    57,    59,    60,    61,    64,    65,    67,    68,    71,
      73,    74,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    93,    96,    96,    97,
     100,   101,   104,   105,   108,   109,   112,   113,   116,   117,
     120,   121,   124,   125,   128,   129,   132,   133,   136,   137,
     138,   139,   140,   141,   144,   145,   148,   149,   152,   155,
     156,   159,   160,   163,   164,   167,   170,   171,   173,   174,
     177,   178,   180,   181,   182,   185,   186,   187,   189,   190,
     192,   193,   195,   196,   199,   200,   202,   203,   205,   206,
     209,   210,   212,   213,   216,   217,   220,   221,   222,   223,
     224,   225,   227,   228,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   244,   245,   248,   249,   252,   255,
     256,   259,   260,   261,   264,   265,   266,   267,   268,   271,
     272,   273,   275,   276,   279,   280,   280,   283,   283,   286,
     286,   287,   287,   290,   290,   291,   291,   292,   292,   293,
     293,   295,   296,   297
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
  "CURVE", "DOLLAR_ID", "FOR", "STRUCT", "AUG_ASSIGN", "DIFF", "VOID",
  "ARROW", "COMPARE", "AND", "OR", "SHIFT", "DECREMENT", "INCREMENT",
  "REAL", "NEWLINE", "IF", "ELSE", "DOT", "REPEAT", "UNTIL", "BREAK",
  "CONTINUE", "IMPORT", "TRUE", "FALSE", "FUNC", "';'", "'{'", "'}'",
  "'('", "')'", "','", "'<'", "'>'", "'*'", "'['", "']'", "'='", "'+'",
  "'-'", "'%'", "'/'", "'|'", "'&'", "'^'", "'~'", "'!'", "$accept",
  "start", "program", "global_decl", "struct", "$@1", "function",
  "funcDef", "ret_type", "parameters", "type_defs", "type", "temp_params",
  "typelist", "block", "statements", "statement", "import", "declarations",
  "$@2", "decl_only", "curve_decl_list", "curve_decl", "decl_id_list",
  "decl_id", "decl_id2", "decl_assgn", "curveAssignList", "curve_assign",
  "assignList", "assign_decl", "assign", "augAssign", "initializerList",
  "multi_assign", "idlist", "lhs", "rhs", "and", "comparision",
  "compare_op", "plus", "product", "mod", "division", "bit_or", "bit_and",
  "shift", "power", "unary_op", "unary_op_only", "final", "value",
  "number", "ret", "call", "obj_call", "arglist", "name", "starred_name",
  "differentiate", "conditional", "$@3", "ifBlock", "$@4", "loop", "$@5",
  "$@6", "forLoop", "$@7", "$@8", "$@9", "$@10", "loopVals", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-253)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-173)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     123,   -19,  -253,    20,    35,  -253,  -253,    41,   202,    55,
    -253,   227,  -253,  -253,    27,  -253,    47,    33,  -253,    49,
      27,    56,  -253,  -253,    24,  -253,    65,  -253,   116,   128,
    -253,  -253,  -253,  -253,   127,  -253,  -253,  -253,     2,   177,
    -253,    20,   178,   159,  -253,  -253,   112,  -253,   160,    27,
      33,  -253,  -253,   150,  -253,   164,   229,     3,   271,    20,
     210,   170,   193,  -253,   198,   207,   239,  -253,    29,    28,
    -253,   208,   112,   240,  -253,   244,   247,     4,  -253,   252,
     253,    73,  -253,   254,  -253,   190,  -253,  -253,    37,  -253,
    -253,  -253,   216,  -253,   257,   255,   391,   258,  -253,  -253,
    -253,  -253,    30,    30,  -253,  -253,  -253,  -253,   391,   175,
     175,   175,    66,   278,   103,   115,   256,   248,   250,   251,
     246,   282,   262,  -253,  -253,   266,  -253,  -253,  -253,  -253,
     179,  -253,   259,   267,  -253,   305,   391,   391,   112,   391,
    -253,  -253,  -253,    30,  -253,   272,   265,   287,  -253,  -253,
    -253,  -253,  -253,  -253,   391,   311,  -253,  -253,   328,   329,
     391,  -253,  -253,    27,  -253,   153,  -253,    27,  -253,  -253,
    -253,   316,   180,  -253,   106,   106,    59,  -253,    73,  -253,
    -253,   391,  -253,   391,  -253,  -253,  -253,   391,   391,   391,
     391,   391,   391,   391,   391,   391,   391,  -253,  -253,  -253,
     391,    20,   431,     9,    63,   307,    68,    89,   391,   351,
      31,   316,   391,  -253,   290,   316,   302,   299,   300,    38,
     112,  -253,  -253,   269,  -253,   229,  -253,   391,   338,   339,
    -253,   278,   103,   115,   256,   256,   248,   250,   251,   246,
     282,   262,  -253,   316,  -253,   391,  -253,   266,    11,   337,
     391,  -253,   304,   318,  -253,   182,   391,   316,   312,   265,
    -253,    90,   316,   391,   391,  -253,  -253,  -253,  -253,   316,
    -253,  -253,    96,   112,   471,   141,   315,   391,  -253,  -253,
     121,   391,  -253,   391,   211,   220,    14,  -253,   391,   306,
     353,   348,  -253,  -253,   125,   112,  -253,   224,   316,  -253,
    -253,   112,   152,   471,   112,   317,  -253,  -253,  -253,  -253,
     308,  -253,  -253,  -253,   112,  -253
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    26,    23,     0,     0,    24,     3,     0,     0,     0,
       2,     5,     9,     7,     0,    10,     0,     0,    22,    61,
       0,    51,    53,    55,    59,    11,     0,    17,     0,     0,
      16,     1,     4,    61,    50,    57,     6,    27,     0,     0,
      58,     0,     0,     0,    46,     8,    31,    13,     0,     0,
       0,    25,    83,     0,    52,     0,    49,   147,     0,     0,
       0,     0,     0,   161,     0,     0,     0,    45,     0,     0,
      42,     0,    31,     0,    82,     0,     0,     0,    35,     0,
       0,    85,   148,     0,    36,   154,    37,    38,     0,    56,
      28,    54,     0,    60,     0,     0,   143,   147,   125,   126,
     135,   133,     0,     0,   134,   127,   128,   137,     0,     0,
       0,     0,     0,    87,    89,    91,    97,    99,   101,   103,
     105,   107,   109,   111,   112,   113,   122,   124,   130,   131,
     129,   132,    67,    63,    65,     0,     0,     0,     0,     0,
      43,    44,   151,     0,   150,    61,    71,    62,    69,    29,
      30,    32,    34,    33,     0,     0,    39,    40,     0,     0,
       0,    41,   155,     0,    15,     0,    18,     0,    84,    12,
      47,   141,     0,   147,   120,   118,     0,   115,   129,   114,
     116,     0,   136,     0,    94,    92,    93,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   117,   121,   119,
       0,     0,     0,     0,     0,     0,     0,     0,   143,     0,
       0,    78,     0,    81,     0,    76,   129,   144,   145,     0,
       0,    21,    14,     0,    20,    49,   138,     0,     0,     0,
     123,    86,    88,    90,    95,    96,    98,   100,   102,   104,
     106,   108,   110,    66,    64,     0,   173,     0,   169,     0,
       0,   157,     0,     0,   149,     0,     0,    74,    61,    70,
      68,     0,    80,   143,   143,   146,   156,    19,    48,   142,
     144,   145,     0,     0,     0,     0,     0,     0,   159,    73,
       0,   143,    77,     0,     0,     0,   167,   170,     0,   171,
     163,     0,   152,   158,     0,     0,    75,     0,    79,   139,
     140,     0,     0,     0,     0,     0,   162,   160,    72,   168,
     172,   165,   164,   153,     0,   166
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -253,  -253,   359,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
     148,    12,  -253,  -253,   -24,   301,  -132,  -253,   147,  -253,
     -48,  -253,    40,  -253,   -11,  -253,  -253,  -253,   176,  -253,
     168,  -253,  -253,   124,   226,  -253,   228,   -41,   201,   196,
    -253,   197,   100,   195,   200,   206,   212,   194,   199,   204,
    -192,   -96,  -191,  -253,  -253,   -45,   -44,  -203,   -46,   321,
     -30,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,  -253,
    -253,  -253,  -253,  -252
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    43,    13,    28,    29,   165,
     166,    69,    18,    38,    70,    71,    72,    15,    94,   225,
      16,    21,   132,    34,    23,    24,    73,   133,   134,   147,
     148,    74,    75,   261,    76,    53,    77,   171,   113,   114,
     187,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,    78,   128,   129,   172,   130,    82,
     131,    84,   220,    85,   276,    86,   295,   138,    87,   304,
     314,   301,   273,   249
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,    79,    80,    35,    47,   255,   205,   -23,    95,    40,
     246,   248,    14,   177,   179,   180,    83,   112,  -171,   154,
      30,  -172,   290,    14,    19,    17,    81,    79,    80,    37,
     181,    33,   145,   142,   173,   258,     1,     2,    89,    25,
       1,     2,    83,    22,    96,    50,    26,    51,   163,   -23,
       5,   311,   250,   155,     5,    31,   174,   175,   146,   181,
     284,   285,    90,   178,   178,   178,    20,   176,    14,  -122,
     143,    42,  -123,    20,    20,    68,    68,    20,   297,   164,
     181,    54,   246,   289,   181,    36,   265,   181,   266,   181,
      39,   158,    81,    79,    80,   203,   204,   207,   206,    41,
     167,   230,   159,    44,   182,   251,   247,   228,    83,   216,
     253,   246,   289,   211,   215,     1,    57,   181,   229,   219,
     160,    58,   184,    59,   228,    60,     1,     2,    61,     5,
     282,   254,    48,   283,     3,   229,   160,     4,   286,    62,
       5,   287,    63,    64,    65,    66,   181,   185,   186,     6,
      67,    46,   221,   160,    45,    46,   224,     7,    68,   243,
       8,   296,   181,   307,   283,   188,   189,   306,   257,   309,
      49,   262,   312,   181,    81,    79,    80,    95,   247,    97,
      98,    52,   315,    99,   291,   100,   269,   101,    55,   292,
      83,    61,    91,    92,   310,   222,   223,   158,    56,   259,
     104,    88,   198,   199,   272,     1,     2,   247,   159,   275,
     105,   106,    93,    27,   135,   262,   108,   136,   162,     5,
     168,    68,   226,   227,   279,   227,   160,    81,    79,    80,
       1,     2,     1,     2,   137,   167,   294,    14,     3,   139,
       3,     4,   298,    83,     5,   140,     5,   302,   149,    81,
      79,    80,   293,   299,   227,    81,    79,    80,    81,    79,
      80,     7,   300,   227,     8,    83,   308,   227,    81,    79,
      80,    83,     1,     2,    83,    97,    98,   141,   151,    99,
     163,   100,   152,   101,    83,   153,     5,    61,   234,   235,
     156,   157,   161,   170,   102,   103,   104,   169,   183,    96,
     191,   194,   190,   192,   195,   193,   105,   106,   200,   107,
     201,   202,   108,   208,   209,    97,    98,    68,   196,    99,
     158,   100,   109,   101,   197,   198,   199,    61,   110,   111,
     210,   159,   217,   218,   102,   103,   104,   181,   252,   155,
     263,   264,   270,   271,   274,   277,   105,   106,   278,   160,
     212,   -85,   108,   281,    46,    97,    98,    68,   305,    99,
     303,   100,   109,   101,  -122,   313,  -123,    61,   110,   111,
      32,   267,   268,   150,   102,   103,   104,   244,   260,   232,
     280,   213,   231,   214,   233,   236,   105,   106,   240,   144,
     256,   237,   108,     0,   241,    97,    98,    68,   238,    99,
     242,   100,   109,   101,     0,   239,     0,    61,   110,   111,
       0,     0,     0,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
       0,     0,   108,     0,     0,    97,    98,    68,     0,    99,
       0,   100,   109,   101,     0,     0,     0,    61,   110,   111,
       0,     0,     0,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
       0,     0,   245,     0,     0,    97,    98,    68,     0,    99,
       0,   100,   109,   101,     0,     0,     0,    61,   110,   111,
       0,     0,     0,     0,   102,   103,   104,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   105,   106,     0,     0,
       0,     0,   288,     0,     0,     0,     0,    68,     0,     0,
       0,     0,   109,     0,     0,     0,     0,     0,   110,   111
};

static const yytype_int16 yycheck[] =
{
      46,    46,    46,    14,    28,   208,   138,     4,    56,    20,
     202,   202,     0,   109,   110,   111,    46,    58,     7,    15,
       8,     7,   274,    11,     4,    44,    72,    72,    72,    17,
      21,     4,     4,     4,     4,     4,     3,     4,    49,     4,
       3,     4,    72,     3,    41,    43,     5,    45,    11,    46,
      17,   303,    43,    49,    17,     0,   102,   103,    69,    21,
     263,   264,    50,   109,   110,   111,    46,   108,    56,    58,
      41,    47,    58,    46,    46,    46,    46,    46,   281,    42,
      21,    41,   274,   274,    21,    38,    48,    21,   220,    21,
      41,    18,   138,   138,   138,   136,   137,   143,   139,    43,
      88,    42,    29,    38,    38,    42,   202,    18,   138,   155,
      42,   303,   303,   154,   155,     3,     4,    21,    29,   160,
      47,     9,    19,    11,    18,    13,     3,     4,    16,    17,
      40,    42,     4,    43,    11,    29,    47,    14,    42,    27,
      17,   273,    30,    31,    32,    33,    21,    44,    45,    26,
      38,    39,   163,    47,    38,    39,   167,    34,    46,   200,
      37,    40,    21,   295,    43,    50,    51,    42,   209,   301,
      43,   212,   304,    21,   220,   220,   220,   225,   274,     4,
       5,     4,   314,     8,    43,    10,   227,    12,    10,    48,
     220,    16,    42,    43,    42,    42,    43,    18,    39,   210,
      25,    41,    23,    24,   245,     3,     4,   303,    29,   250,
      35,    36,    48,    11,     4,   256,    41,    47,    28,    17,
       4,    46,    42,    43,    42,    43,    47,   273,   273,   273,
       3,     4,     3,     4,    41,   223,   277,   225,    11,    41,
      11,    14,   283,   273,    17,    38,    17,   288,    40,   295,
     295,   295,   276,    42,    43,   301,   301,   301,   304,   304,
     304,    34,    42,    43,    37,   295,    42,    43,   314,   314,
     314,   301,     3,     4,   304,     4,     5,    38,    38,     8,
      11,    10,    38,    12,   314,    38,    17,    16,   188,   189,
      38,    38,    38,    38,    23,    24,    25,    40,    20,    41,
      52,    55,    46,    53,    22,    54,    35,    36,    49,    38,
      43,     6,    41,    41,    49,     4,     5,    46,    56,     8,
      18,    10,    51,    12,    58,    23,    24,    16,    57,    58,
      43,    29,     4,     4,    23,    24,    25,    21,    31,    49,
      41,    41,     4,     4,     7,    41,    35,    36,    30,    47,
      39,    49,    41,    41,    39,     4,     5,    46,    10,     8,
       7,    10,    51,    12,    58,    48,    58,    16,    57,    58,
      11,   223,   225,    72,    23,    24,    25,   201,   210,   183,
     256,   155,   181,   155,   187,   190,    35,    36,   194,    68,
      39,   191,    41,    -1,   195,     4,     5,    46,   192,     8,
     196,    10,    51,    12,    -1,   193,    -1,    16,    57,    58,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,     4,     5,    46,    -1,     8,
      -1,    10,    51,    12,    -1,    -1,    -1,    16,    57,    58,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,     4,     5,    46,    -1,     8,
      -1,    10,    51,    12,    -1,    -1,    -1,    16,    57,    58,
      -1,    -1,    -1,    -1,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    -1,    -1,
      -1,    -1,    41,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    58
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    11,    14,    17,    26,    34,    37,    60,
      61,    62,    63,    65,    70,    76,    79,    44,    71,     4,
      46,    80,    81,    83,    84,     4,     5,    11,    66,    67,
      70,     0,    61,     4,    82,    83,    38,    70,    72,    41,
      83,    43,    47,    64,    38,    38,    39,    73,     4,    43,
      43,    45,     4,    94,    81,    10,    39,     4,     9,    11,
      13,    16,    27,    30,    31,    32,    33,    38,    46,    70,
      73,    74,    75,    85,    90,    91,    93,    95,   113,   114,
     115,   117,   118,   119,   120,   122,   124,   127,    41,    83,
      70,    42,    43,    48,    77,    79,    41,     4,     5,     8,
      10,    12,    23,    24,    25,    35,    36,    38,    41,    51,
      57,    58,    96,    97,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   114,   115,
     117,   119,    81,    86,    87,     4,    47,    41,   126,    41,
      38,    38,     4,    41,   118,     4,    83,    88,    89,    40,
      74,    38,    38,    38,    15,    49,    38,    38,    18,    29,
      47,    38,    28,    11,    42,    68,    69,    70,     4,    40,
      38,    96,   116,     4,   117,   117,    96,   110,   117,   110,
     110,    21,    38,    20,    19,    44,    45,    99,    50,    51,
      46,    52,    53,    54,    55,    22,    56,    58,    23,    24,
      49,    43,     6,    96,    96,    75,    96,   117,    41,    49,
      43,    96,    39,    93,    95,    96,   117,     4,     4,    96,
     121,    83,    42,    43,    83,    78,    42,    43,    18,    29,
      42,    97,    98,   100,   101,   101,   102,   103,   104,   105,
     106,   107,   108,    96,    87,    41,   109,   110,   111,   132,
      43,    42,    31,    42,    42,   116,    39,    96,     4,    83,
      89,    92,    96,    41,    41,    48,    75,    69,    77,    96,
       4,     4,    96,   131,     7,    96,   123,    41,    30,    42,
      92,    41,    40,    43,   116,   116,    42,    75,    41,   111,
     132,    43,    48,    73,    96,   125,    40,   116,    96,    42,
      42,   130,    96,     7,   128,    10,    42,    75,    42,    75,
      42,   132,    75,    48,   129,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    64,    63,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    76,    78,    77,    77,
      79,    79,    80,    80,    81,    81,    82,    82,    83,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    92,
      92,    93,    93,    94,    94,    95,    96,    96,    97,    97,
      98,    98,    99,    99,    99,   100,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     107,   107,   108,   108,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   110,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   111,   112,   112,   113,   113,   114,   115,
     115,   116,   116,   116,   117,   117,   117,   117,   117,   118,
     118,   118,   119,   119,   120,   121,   120,   123,   122,   125,
     124,   126,   124,   128,   127,   129,   127,   130,   127,   131,
     127,   132,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     2,     1,     3,     1,
       1,     0,     6,     3,     5,     4,     1,     1,     1,     3,
       2,     2,     2,     1,     1,     3,     0,     1,     3,     3,
       2,     0,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     2,     1,     2,     2,     1,     3,     0,     4,     0,
       2,     2,     3,     1,     4,     1,     3,     1,     2,     1,
       4,     1,     2,     2,     3,     1,     3,     1,     3,     1,
       3,     1,     6,     4,     3,     5,     3,     5,     3,     3,
       1,     3,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     1,     3,     3,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     2,     2,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     2,     4,     6,
       6,     1,     3,     0,     3,     3,     4,     1,     1,     4,
       2,     2,     6,     8,     1,     0,     4,     0,     6,     0,
       7,     0,     7,     0,     8,     0,    10,     0,     8,     0,
       6,     1,     3,     1
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
#line 25 "src/lexer/parser.y"
                           {printf(" : invalid program\n"); exit(0);}
#line 1475 "src/lexer/y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 39 "src/lexer/parser.y"
                                     {label("Struct def");}
#line 1481 "src/lexer/y.tab.c"
    break;

  case 14: /* funcDef: ret_type IDENTIFIER '(' parameters ')'  */
#line 45 "src/lexer/parser.y"
                                                          {label("Function def");}
#line 1487 "src/lexer/y.tab.c"
    break;

  case 15: /* funcDef: ret_type IDENTIFIER '(' ')'  */
#line 46 "src/lexer/parser.y"
                                               {label("Function def");}
#line 1493 "src/lexer/y.tab.c"
    break;

  case 32: /* statement: decl_assgn ';'  */
#line 77 "src/lexer/parser.y"
                                    {label("Declaration");}
#line 1499 "src/lexer/y.tab.c"
    break;

  case 33: /* statement: multi_assign ';'  */
#line 78 "src/lexer/parser.y"
                                    {label("Assignment");}
#line 1505 "src/lexer/y.tab.c"
    break;

  case 34: /* statement: augAssign ';'  */
#line 79 "src/lexer/parser.y"
                                    {label("Augmented Assignment");}
#line 1511 "src/lexer/y.tab.c"
    break;

  case 35: /* statement: ret  */
#line 80 "src/lexer/parser.y"
                                    {label("Return");}
#line 1517 "src/lexer/y.tab.c"
    break;

  case 39: /* statement: call ';'  */
#line 84 "src/lexer/parser.y"
                                    {label("Function Call");}
#line 1523 "src/lexer/y.tab.c"
    break;

  case 40: /* statement: obj_call ';'  */
#line 85 "src/lexer/parser.y"
                                    {label("Object Function Call");}
#line 1529 "src/lexer/y.tab.c"
    break;

  case 41: /* statement: differentiate ';'  */
#line 86 "src/lexer/parser.y"
                                     {label("Differentiate");}
#line 1535 "src/lexer/y.tab.c"
    break;

  case 43: /* statement: BREAK ';'  */
#line 88 "src/lexer/parser.y"
                                    {label("Break");}
#line 1541 "src/lexer/y.tab.c"
    break;

  case 44: /* statement: CONTINUE ';'  */
#line 89 "src/lexer/parser.y"
                                    {label("Continue");}
#line 1547 "src/lexer/y.tab.c"
    break;

  case 47: /* $@2: %empty  */
#line 96 "src/lexer/parser.y"
                                 {label("Declaration");}
#line 1553 "src/lexer/y.tab.c"
    break;

  case 155: /* $@3: %empty  */
#line 280 "src/lexer/parser.y"
                                {label("Else stetement");}
#line 1559 "src/lexer/y.tab.c"
    break;

  case 157: /* $@4: %empty  */
#line 283 "src/lexer/parser.y"
                                  {label("If statement");}
#line 1565 "src/lexer/y.tab.c"
    break;

  case 159: /* $@5: %empty  */
#line 286 "src/lexer/parser.y"
                                            {label("Loop");}
#line 1571 "src/lexer/y.tab.c"
    break;

  case 161: /* $@6: %empty  */
#line 287 "src/lexer/parser.y"
                          {label("Loop");}
#line 1577 "src/lexer/y.tab.c"
    break;

  case 163: /* $@7: %empty  */
#line 290 "src/lexer/parser.y"
                                                            {label("For loop");}
#line 1583 "src/lexer/y.tab.c"
    break;

  case 165: /* $@8: %empty  */
#line 291 "src/lexer/parser.y"
                                                                          {label("For loop");}
#line 1589 "src/lexer/y.tab.c"
    break;

  case 167: /* $@9: %empty  */
#line 292 "src/lexer/parser.y"
                                                 {label("For loop");}
#line 1595 "src/lexer/y.tab.c"
    break;

  case 169: /* $@10: %empty  */
#line 293 "src/lexer/parser.y"
                                           {label("For loop");}
#line 1601 "src/lexer/y.tab.c"
    break;


#line 1605 "src/lexer/y.tab.c"

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

#line 299 "src/lexer/parser.y"


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
