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
#define YYLAST   488

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  59
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  172
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

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
      85,    86,    87,    88,    89,    92,    95,    95,    96,    99,
     100,   103,   104,   107,   108,   111,   112,   115,   116,   119,
     120,   123,   124,   127,   128,   131,   132,   135,   136,   137,
     138,   139,   140,   143,   144,   147,   148,   151,   154,   155,
     158,   159,   162,   163,   166,   169,   170,   172,   173,   176,
     177,   179,   180,   181,   184,   185,   186,   188,   189,   191,
     192,   194,   195,   198,   199,   201,   202,   204,   205,   208,
     209,   211,   212,   215,   216,   219,   220,   221,   222,   223,
     224,   226,   227,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   243,   244,   247,   248,   251,   254,   255,
     258,   259,   260,   263,   264,   265,   266,   267,   270,   271,
     272,   274,   275,   278,   279,   279,   282,   282,   285,   285,
     286,   286,   289,   289,   290,   290,   291,   291,   292,   292,
     294,   295,   296
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

#define YYPACT_NINF (-252)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-172)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     127,    -7,  -252,    14,    38,  -252,  -252,    77,   248,    86,
    -252,   184,  -252,  -252,    20,  -252,    58,   163,  -252,    68,
      20,    85,  -252,  -252,    78,  -252,    94,  -252,    75,   147,
    -252,  -252,  -252,  -252,   135,  -252,  -252,  -252,   134,   166,
    -252,    14,   172,   150,  -252,  -252,   442,  -252,   151,    20,
     163,  -252,  -252,   142,  -252,   154,   280,     2,   111,    14,
     190,   165,  -252,   171,   176,   178,  -252,     3,    27,  -252,
     164,   442,   182,  -252,   191,   194,    21,  -252,   199,   212,
      36,  -252,  -252,   236,  -252,  -252,    42,  -252,  -252,  -252,
     267,  -252,   232,   238,   345,   237,  -252,  -252,  -252,  -252,
     235,    29,    29,  -252,  -252,  -252,  -252,   345,   203,   203,
     203,     9,   266,   146,   149,   241,   240,   243,   239,   244,
     276,   251,  -252,  -252,   254,  -252,  -252,  -252,  -252,    70,
    -252,   269,   271,  -252,   313,   345,   442,   345,  -252,  -252,
    -252,    29,  -252,   279,   275,   282,  -252,  -252,  -252,  -252,
    -252,  -252,   345,   265,  -252,  -252,   322,   323,   345,  -252,
      20,  -252,   167,  -252,    20,  -252,  -252,  -252,   310,   180,
     345,  -252,    51,    51,    84,  -252,    36,  -252,  -252,   345,
    -252,   345,  -252,  -252,  -252,   345,   345,   345,   345,   345,
     345,   345,   345,   345,   345,  -252,  -252,  -252,   345,    14,
     385,    91,   301,   101,    82,   345,   305,    30,   310,   345,
    -252,   284,   310,   256,   293,   294,    31,   442,  -252,  -252,
     291,  -252,   280,  -252,   345,     8,   332,   333,  -252,   266,
     146,   149,   241,   241,   240,   243,   239,   244,   276,   251,
    -252,   310,  -252,   345,  -252,   254,    10,   331,  -252,   298,
     312,  -252,   192,   345,   310,   302,   275,  -252,    -8,   310,
     345,   345,  -252,  -252,  -252,  -252,   310,   345,  -252,  -252,
     116,   442,   425,   306,   345,  -252,  -252,    -2,   345,  -252,
     345,   198,   200,    97,    16,  -252,   345,   289,   341,  -252,
     118,   442,  -252,   218,   310,  -252,  -252,   342,  -252,   442,
     121,   425,   442,  -252,  -252,  -252,   311,  -252,   296,  -252,
    -252,  -252,   442,  -252
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,    26,    23,     0,     0,    24,     3,     0,     0,     0,
       2,     5,     9,     7,     0,    10,     0,     0,    22,    60,
       0,    50,    52,    54,    58,    11,     0,    17,     0,     0,
      16,     1,     4,    60,    49,    56,     6,    27,     0,     0,
      57,     0,     0,     0,    45,     8,    31,    13,     0,     0,
       0,    25,    82,     0,    51,     0,    48,   146,     0,     0,
       0,     0,   160,     0,     0,     0,    44,     0,     0,    41,
       0,    31,     0,    81,     0,     0,     0,    35,     0,     0,
      84,   147,    36,   153,    37,    38,     0,    55,    28,    53,
       0,    59,     0,     0,   142,   146,   124,   125,   134,   132,
       0,     0,     0,   133,   126,   127,   136,     0,     0,     0,
       0,     0,    86,    88,    90,    96,    98,   100,   102,   104,
     106,   108,   110,   111,   112,   121,   123,   129,   130,   128,
     131,    66,    62,    64,     0,     0,     0,     0,    42,    43,
     150,     0,   149,    60,    70,    61,    68,    29,    30,    32,
      34,    33,     0,     0,    39,    40,     0,     0,     0,   154,
       0,    15,     0,    18,     0,    83,    12,    46,   140,     0,
       0,   146,   119,   117,     0,   114,   128,   113,   115,     0,
     135,     0,    93,    91,    92,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   116,   120,   118,     0,     0,
       0,     0,     0,     0,     0,   142,     0,     0,    77,     0,
      80,     0,    75,   128,   143,   144,     0,     0,    21,    14,
       0,    20,    48,   137,     0,     0,     0,     0,   122,    85,
      87,    89,    94,    95,    97,    99,   101,   103,   105,   107,
     109,    65,    63,     0,   172,     0,   168,     0,   156,     0,
       0,   148,     0,     0,    73,    60,    69,    67,     0,    79,
     142,   142,   145,   155,    19,    47,   141,     0,   143,   144,
       0,     0,     0,     0,     0,   158,    72,     0,   142,    76,
       0,     0,     0,     0,   166,   169,     0,   170,   162,   157,
       0,     0,    74,     0,    78,   138,   139,     0,   151,     0,
       0,     0,     0,   161,   159,    71,     0,   167,   171,   164,
     163,   152,     0,   165
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -252,  -252,   347,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
     140,    11,  -252,  -252,   -25,   295,  -116,  -252,   143,  -252,
     -41,  -252,    37,  -252,   -10,  -252,  -252,  -252,   168,  -252,
     157,  -252,  -252,   119,   220,  -252,   221,   -50,   196,   195,
    -252,   186,    76,   189,   193,   188,   197,   187,   201,   204,
    -195,   -96,  -191,  -252,  -252,   -45,   -44,  -189,   -46,   316,
    -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,  -252,
    -252,  -252,  -252,  -251
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    43,    13,    28,    29,   162,
     163,    68,    18,    38,    69,    70,    71,    15,    92,   222,
      16,    21,   131,    34,    23,    24,    72,   132,   133,   145,
     146,    73,    74,   258,    75,    53,    76,   168,   112,   113,
     185,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,   126,    77,   127,   128,   169,   129,    81,
     130,    82,   217,    83,   273,    84,   291,   136,    85,   302,
     312,   299,   271,   247
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    78,    79,    47,    35,   244,   -23,   140,   111,   246,
      40,    14,   175,   177,   178,    93,   252,  -170,    19,    30,
     202,   288,    14,  -171,    33,    80,    78,    79,    37,   179,
     179,   143,   279,   171,   255,   280,   152,    17,   292,    87,
      22,   280,    25,    94,   141,     1,     2,   180,   -23,    67,
     309,   267,   179,   160,   156,   172,   173,   174,   144,     5,
      20,    88,   176,   176,   176,   157,    20,    14,  -121,   226,
     153,   281,   282,    20,  -122,    67,    20,   244,    54,   262,
     227,   287,    26,   158,   161,   201,    31,   203,   156,   293,
      80,    78,    79,   196,   197,   204,    36,   164,   158,   157,
     226,   263,   208,   212,   245,   179,   244,   213,   216,    39,
     287,   227,   179,    45,    46,    95,    96,   158,   179,    97,
     225,    98,   179,    99,   251,    42,   228,   100,    41,   158,
       1,     2,    44,   248,   101,   102,   103,   179,     3,   179,
     297,     4,   179,   250,     5,   298,   104,   105,   241,   106,
     218,    48,   107,     6,   221,   285,   254,    67,   284,   259,
     303,     7,   108,   308,     8,   182,     1,     2,   109,   110,
      52,    80,    78,    79,   266,   304,   245,    50,    49,    51,
       5,    93,    55,   307,    89,    90,   310,     1,     2,    56,
     183,   184,    86,   270,   134,     3,   313,   256,     4,   186,
     187,     5,    91,   259,   147,   245,   135,    95,    96,   219,
     220,    97,   137,    98,   138,    99,   139,   283,     7,   100,
     149,     8,   223,   224,   290,    80,    78,    79,   103,   150,
     294,   164,   151,    14,   276,   224,   300,   154,   104,   105,
     295,   224,   296,   224,   107,    80,    78,    79,   289,    67,
     155,     1,     2,    80,    78,    79,    80,    78,    79,    27,
     305,   224,   232,   233,   159,     5,    80,    78,    79,    95,
      96,   165,   166,    97,   156,    98,   167,    99,    94,   196,
     197,   100,   170,     1,     2,   157,   181,   188,   101,   102,
     103,     3,   189,   191,     1,     2,   190,     5,   193,   192,
     104,   105,   160,   158,   209,   -84,   107,   194,     5,    95,
      96,    67,   195,    97,   199,    98,   108,    99,   198,   200,
     205,   100,   109,   110,   206,   207,   214,   215,   101,   102,
     103,   179,   249,   153,   260,   261,   268,   269,   272,   274,
     104,   105,   275,   278,   253,    46,   107,  -121,   301,    95,
      96,    67,   306,    97,  -122,    98,   108,    99,    32,   311,
     264,   100,   109,   110,   257,   265,   148,   242,   101,   102,
     103,   231,   277,   210,   211,   229,   230,   234,   236,   238,
     104,   105,   235,   142,     0,     0,   107,     0,   237,    95,
      96,    67,     0,    97,   239,    98,   108,    99,   240,     0,
       0,   100,   109,   110,     0,     0,     0,     0,   101,   102,
     103,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     104,   105,     0,     0,     0,     0,   243,     0,     0,    95,
      96,    67,     0,    97,     0,    98,   108,    99,     0,     0,
       0,   100,   109,   110,     0,     1,    57,     0,   101,   102,
     103,    58,     0,    59,     0,    60,     0,     0,     0,     5,
     104,   105,     0,     0,     0,     0,   286,     0,     0,    61,
       0,    67,    62,    63,    64,    65,   108,     0,     0,     0,
      66,    46,   109,   110,     0,     0,     0,     0,    67
};

static const yytype_int16 yycheck[] =
{
      46,    46,    46,    28,    14,   200,     4,     4,    58,   200,
      20,     0,   108,   109,   110,    56,   205,     7,     4,     8,
     136,   272,    11,     7,     4,    71,    71,    71,    17,    21,
      21,     4,    40,     4,     4,    43,    15,    44,    40,    49,
       3,    43,     4,    41,    41,     3,     4,    38,    46,    46,
     301,    43,    21,    11,    18,   101,   102,   107,    68,    17,
      46,    50,   108,   109,   110,    29,    46,    56,    58,    18,
      49,   260,   261,    46,    58,    46,    46,   272,    41,    48,
      29,   272,     5,    47,    42,   135,     0,   137,    18,   278,
     136,   136,   136,    23,    24,   141,    38,    86,    47,    29,
      18,   217,   152,   153,   200,    21,   301,   153,   158,    41,
     301,    29,    21,    38,    39,     4,     5,    47,    21,     8,
     170,    10,    21,    12,    42,    47,    42,    16,    43,    47,
       3,     4,    38,    42,    23,    24,    25,    21,    11,    21,
      43,    14,    21,    42,    17,    48,    35,    36,   198,    38,
     160,     4,    41,    26,   164,   271,   206,    46,    42,   209,
      42,    34,    51,    42,    37,    19,     3,     4,    57,    58,
       4,   217,   217,   217,   224,   291,   272,    43,    43,    45,
      17,   222,    10,   299,    42,    43,   302,     3,     4,    39,
      44,    45,    41,   243,     4,    11,   312,   207,    14,    50,
      51,    17,    48,   253,    40,   301,    41,     4,     5,    42,
      43,     8,    41,    10,    38,    12,    38,   267,    34,    16,
      38,    37,    42,    43,   274,   271,   271,   271,    25,    38,
     280,   220,    38,   222,    42,    43,   286,    38,    35,    36,
      42,    43,    42,    43,    41,   291,   291,   291,   273,    46,
      38,     3,     4,   299,   299,   299,   302,   302,   302,    11,
      42,    43,   186,   187,    28,    17,   312,   312,   312,     4,
       5,     4,    40,     8,    18,    10,    38,    12,    41,    23,
      24,    16,    47,     3,     4,    29,    20,    46,    23,    24,
      25,    11,    52,    54,     3,     4,    53,    17,    22,    55,
      35,    36,    11,    47,    39,    49,    41,    56,    17,     4,
       5,    46,    58,     8,    43,    10,    51,    12,    49,     6,
      41,    16,    57,    58,    49,    43,     4,     4,    23,    24,
      25,    21,    31,    49,    41,    41,     4,     4,     7,    41,
      35,    36,    30,    41,    39,    39,    41,    58,     7,     4,
       5,    46,    10,     8,    58,    10,    51,    12,    11,    48,
     220,    16,    57,    58,   207,   222,    71,   199,    23,    24,
      25,   185,   253,   153,   153,   179,   181,   188,   190,   192,
      35,    36,   189,    67,    -1,    -1,    41,    -1,   191,     4,
       5,    46,    -1,     8,   193,    10,    51,    12,   194,    -1,
      -1,    16,    57,    58,    -1,    -1,    -1,    -1,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,     4,
       5,    46,    -1,     8,    -1,    10,    51,    12,    -1,    -1,
      -1,    16,    57,    58,    -1,     3,     4,    -1,    23,    24,
      25,     9,    -1,    11,    -1,    13,    -1,    -1,    -1,    17,
      35,    36,    -1,    -1,    -1,    -1,    41,    -1,    -1,    27,
      -1,    46,    30,    31,    32,    33,    51,    -1,    -1,    -1,
      38,    39,    57,    58,    -1,    -1,    -1,    -1,    46
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
      13,    27,    30,    31,    32,    33,    38,    46,    70,    73,
      74,    75,    85,    90,    91,    93,    95,   113,   114,   115,
     117,   118,   120,   122,   124,   127,    41,    83,    70,    42,
      43,    48,    77,    79,    41,     4,     5,     8,    10,    12,
      16,    23,    24,    25,    35,    36,    38,    41,    51,    57,
      58,    96,    97,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   114,   115,   117,
     119,    81,    86,    87,     4,    41,   126,    41,    38,    38,
       4,    41,   118,     4,    83,    88,    89,    40,    74,    38,
      38,    38,    15,    49,    38,    38,    18,    29,    47,    28,
      11,    42,    68,    69,    70,     4,    40,    38,    96,   116,
      47,     4,   117,   117,    96,   110,   117,   110,   110,    21,
      38,    20,    19,    44,    45,    99,    50,    51,    46,    52,
      53,    54,    55,    22,    56,    58,    23,    24,    49,    43,
       6,    96,    75,    96,   117,    41,    49,    43,    96,    39,
      93,    95,    96,   117,     4,     4,    96,   121,    83,    42,
      43,    83,    78,    42,    43,    96,    18,    29,    42,    97,
      98,   100,   101,   101,   102,   103,   104,   105,   106,   107,
     108,    96,    87,    41,   109,   110,   111,   132,    42,    31,
      42,    42,   116,    39,    96,     4,    83,    89,    92,    96,
      41,    41,    48,    75,    69,    77,    96,    43,     4,     4,
      96,   131,     7,   123,    41,    30,    42,    92,    41,    40,
      43,   116,   116,    96,    42,    75,    41,   111,   132,    73,
      96,   125,    40,   116,    96,    42,    42,    43,    48,   130,
      96,     7,   128,    42,    75,    42,    10,    75,    42,   132,
      75,    48,   129,    75
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    59,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    64,    63,    65,    66,    66,    67,    67,    68,    68,
      69,    69,    70,    70,    70,    71,    71,    72,    72,    73,
      74,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    78,    77,    77,    79,
      79,    80,    80,    81,    81,    82,    82,    83,    83,    84,
      84,    85,    85,    86,    86,    87,    87,    88,    88,    88,
      88,    88,    88,    89,    89,    90,    90,    91,    92,    92,
      93,    93,    94,    94,    95,    96,    96,    97,    97,    98,
      98,    99,    99,    99,   100,   100,   100,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   108,   108,   109,   109,   109,   109,   109,   109,   109,
     109,   110,   110,   111,   111,   111,   111,   111,   111,   111,
     111,   111,   111,   112,   112,   113,   113,   114,   115,   115,
     116,   116,   116,   117,   117,   117,   117,   117,   118,   118,
     118,   119,   119,   120,   121,   120,   123,   122,   125,   124,
     126,   124,   128,   127,   129,   127,   130,   127,   131,   127,
     132,   132,   132
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     0,     2,     1,     3,     1,
       1,     0,     6,     3,     5,     4,     1,     1,     1,     3,
       2,     2,     2,     1,     1,     3,     0,     1,     3,     3,
       2,     0,     2,     2,     2,     1,     1,     1,     1,     2,
       2,     1,     2,     2,     1,     3,     0,     4,     0,     2,
       2,     3,     1,     4,     1,     3,     1,     2,     1,     4,
       1,     2,     2,     3,     1,     3,     1,     3,     1,     3,
       1,     6,     4,     3,     5,     3,     5,     3,     3,     1,
       3,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     1,     3,     3,     1,     3,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     2,     2,     2,     2,     2,     2,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     2,     4,     6,     6,
       1,     3,     0,     3,     3,     4,     1,     1,     4,     2,
       2,     6,     8,     1,     0,     4,     0,     6,     0,     7,
       0,     7,     0,     8,     0,    10,     0,     8,     0,     6,
       1,     3,     1
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
#line 1467 "src/lexer/y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 39 "src/lexer/parser.y"
                                     {label("Struct def");}
#line 1473 "src/lexer/y.tab.c"
    break;

  case 14: /* funcDef: ret_type IDENTIFIER '(' parameters ')'  */
#line 45 "src/lexer/parser.y"
                                                          {label("Function def");}
#line 1479 "src/lexer/y.tab.c"
    break;

  case 15: /* funcDef: ret_type IDENTIFIER '(' ')'  */
#line 46 "src/lexer/parser.y"
                                               {label("Function def");}
#line 1485 "src/lexer/y.tab.c"
    break;

  case 32: /* statement: decl_assgn ';'  */
#line 77 "src/lexer/parser.y"
                                    {label("Declaration");}
#line 1491 "src/lexer/y.tab.c"
    break;

  case 33: /* statement: multi_assign ';'  */
#line 78 "src/lexer/parser.y"
                                    {label("Assignment");}
#line 1497 "src/lexer/y.tab.c"
    break;

  case 34: /* statement: augAssign ';'  */
#line 79 "src/lexer/parser.y"
                                    {label("Augmented Assignment");}
#line 1503 "src/lexer/y.tab.c"
    break;

  case 35: /* statement: ret  */
#line 80 "src/lexer/parser.y"
                                    {label("Return");}
#line 1509 "src/lexer/y.tab.c"
    break;

  case 39: /* statement: call ';'  */
#line 84 "src/lexer/parser.y"
                                    {label("Function Call");}
#line 1515 "src/lexer/y.tab.c"
    break;

  case 40: /* statement: obj_call ';'  */
#line 85 "src/lexer/parser.y"
                                    {label("Object Function Call");}
#line 1521 "src/lexer/y.tab.c"
    break;

  case 42: /* statement: BREAK ';'  */
#line 87 "src/lexer/parser.y"
                                    {label("Break");}
#line 1527 "src/lexer/y.tab.c"
    break;

  case 43: /* statement: CONTINUE ';'  */
#line 88 "src/lexer/parser.y"
                                    {label("Continue");}
#line 1533 "src/lexer/y.tab.c"
    break;

  case 46: /* $@2: %empty  */
#line 95 "src/lexer/parser.y"
                                 {label("Declaration");}
#line 1539 "src/lexer/y.tab.c"
    break;

  case 154: /* $@3: %empty  */
#line 279 "src/lexer/parser.y"
                                {label("Else stetement");}
#line 1545 "src/lexer/y.tab.c"
    break;

  case 156: /* $@4: %empty  */
#line 282 "src/lexer/parser.y"
                                  {label("If statement");}
#line 1551 "src/lexer/y.tab.c"
    break;

  case 158: /* $@5: %empty  */
#line 285 "src/lexer/parser.y"
                                            {label("Loop");}
#line 1557 "src/lexer/y.tab.c"
    break;

  case 160: /* $@6: %empty  */
#line 286 "src/lexer/parser.y"
                          {label("Loop");}
#line 1563 "src/lexer/y.tab.c"
    break;

  case 162: /* $@7: %empty  */
#line 289 "src/lexer/parser.y"
                                                            {label("For loop");}
#line 1569 "src/lexer/y.tab.c"
    break;

  case 164: /* $@8: %empty  */
#line 290 "src/lexer/parser.y"
                                                                          {label("For loop");}
#line 1575 "src/lexer/y.tab.c"
    break;

  case 166: /* $@9: %empty  */
#line 291 "src/lexer/parser.y"
                                                 {label("For loop");}
#line 1581 "src/lexer/y.tab.c"
    break;

  case 168: /* $@10: %empty  */
#line 292 "src/lexer/parser.y"
                                           {label("For loop");}
#line 1587 "src/lexer/y.tab.c"
    break;


#line 1591 "src/lexer/y.tab.c"

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

#line 298 "src/lexer/parser.y"


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
