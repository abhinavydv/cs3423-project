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
  YYSYMBOL_ret_type = 66,                  /* ret_type  */
  YYSYMBOL_parameters = 67,                /* parameters  */
  YYSYMBOL_type_defs = 68,                 /* type_defs  */
  YYSYMBOL_type = 69,                      /* type  */
  YYSYMBOL_temp_params = 70,               /* temp_params  */
  YYSYMBOL_typelist = 71,                  /* typelist  */
  YYSYMBOL_block = 72,                     /* block  */
  YYSYMBOL_statements = 73,                /* statements  */
  YYSYMBOL_statement = 74,                 /* statement  */
  YYSYMBOL_import = 75,                    /* import  */
  YYSYMBOL_declarations = 76,              /* declarations  */
  YYSYMBOL_77_2 = 77,                      /* $@2  */
  YYSYMBOL_decl_only = 78,                 /* decl_only  */
  YYSYMBOL_curve_decl_list = 79,           /* curve_decl_list  */
  YYSYMBOL_curve_decl = 80,                /* curve_decl  */
  YYSYMBOL_decl_id_list = 81,              /* decl_id_list  */
  YYSYMBOL_decl_id = 82,                   /* decl_id  */
  YYSYMBOL_decl_id2 = 83,                  /* decl_id2  */
  YYSYMBOL_decl_assgn = 84,                /* decl_assgn  */
  YYSYMBOL_curveAssignList = 85,           /* curveAssignList  */
  YYSYMBOL_curve_assign = 86,              /* curve_assign  */
  YYSYMBOL_assignList = 87,                /* assignList  */
  YYSYMBOL_assign_decl = 88,               /* assign_decl  */
  YYSYMBOL_assign = 89,                    /* assign  */
  YYSYMBOL_augAssign = 90,                 /* augAssign  */
  YYSYMBOL_initializerList = 91,           /* initializerList  */
  YYSYMBOL_multi_assign = 92,              /* multi_assign  */
  YYSYMBOL_idlist = 93,                    /* idlist  */
  YYSYMBOL_lhs = 94,                       /* lhs  */
  YYSYMBOL_rhs = 95,                       /* rhs  */
  YYSYMBOL_and = 96,                       /* and  */
  YYSYMBOL_comparision = 97,               /* comparision  */
  YYSYMBOL_compare_op = 98,                /* compare_op  */
  YYSYMBOL_plus = 99,                      /* plus  */
  YYSYMBOL_product = 100,                  /* product  */
  YYSYMBOL_mod = 101,                      /* mod  */
  YYSYMBOL_division = 102,                 /* division  */
  YYSYMBOL_bit_or = 103,                   /* bit_or  */
  YYSYMBOL_bit_and = 104,                  /* bit_and  */
  YYSYMBOL_shift = 105,                    /* shift  */
  YYSYMBOL_power = 106,                    /* power  */
  YYSYMBOL_unary_op = 107,                 /* unary_op  */
  YYSYMBOL_unary_op_only = 108,            /* unary_op_only  */
  YYSYMBOL_final = 109,                    /* final  */
  YYSYMBOL_value = 110,                    /* value  */
  YYSYMBOL_number = 111,                   /* number  */
  YYSYMBOL_ret = 112,                      /* ret  */
  YYSYMBOL_call = 113,                     /* call  */
  YYSYMBOL_obj_call = 114,                 /* obj_call  */
  YYSYMBOL_arglist = 115,                  /* arglist  */
  YYSYMBOL_name = 116,                     /* name  */
  YYSYMBOL_starred_name = 117,             /* starred_name  */
  YYSYMBOL_differentiate = 118,            /* differentiate  */
  YYSYMBOL_conditional = 119,              /* conditional  */
  YYSYMBOL_120_3 = 120,                    /* $@3  */
  YYSYMBOL_ifBlock = 121,                  /* ifBlock  */
  YYSYMBOL_122_4 = 122,                    /* $@4  */
  YYSYMBOL_loop = 123,                     /* loop  */
  YYSYMBOL_124_5 = 124,                    /* $@5  */
  YYSYMBOL_125_6 = 125,                    /* $@6  */
  YYSYMBOL_forLoop = 126,                  /* forLoop  */
  YYSYMBOL_127_7 = 127,                    /* $@7  */
  YYSYMBOL_128_8 = 128,                    /* $@8  */
  YYSYMBOL_129_9 = 129,                    /* $@9  */
  YYSYMBOL_130_10 = 130,                   /* $@10  */
  YYSYMBOL_loopVals = 131                  /* loopVals  */
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
#define YYLAST   506

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  74
/* YYNRULES -- Number of rules.  */
#define YYNRULES  171
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
     238,   239,   242,   243,   246,   247,   250,   253,   254,   257,
     258,   259,   262,   263,   264,   265,   266,   269,   270,   271,
     273,   274,   279,   280,   280,   283,   283,   286,   286,   287,
     287,   290,   290,   291,   291,   292,   292,   293,   293,   295,
     296,   297
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
  "global_decl", "struct", "$@1", "function", "funcDef", "ret_type",
  "parameters", "type_defs", "type", "temp_params", "typelist", "block",
  "statements", "statement", "import", "declarations", "$@2", "decl_only",
  "curve_decl_list", "curve_decl", "decl_id_list", "decl_id", "decl_id2",
  "decl_assgn", "curveAssignList", "curve_assign", "assignList",
  "assign_decl", "assign", "augAssign", "initializerList", "multi_assign",
  "idlist", "lhs", "rhs", "and", "comparision", "compare_op", "plus",
  "product", "mod", "division", "bit_or", "bit_and", "shift", "power",
  "unary_op", "unary_op_only", "final", "value", "number", "ret", "call",
  "obj_call", "arglist", "name", "starred_name", "differentiate",
  "conditional", "$@3", "ifBlock", "$@4", "loop", "$@5", "$@6", "forLoop",
  "$@7", "$@8", "$@9", "$@10", "loopVals", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-256)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-171)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     118,    24,  -256,    33,    30,  -256,  -256,    80,   230,    87,
    -256,   275,  -256,  -256,    35,  -256,    61,   181,  -256,    52,
      35,    70,  -256,  -256,    74,  -256,    73,  -256,   -15,   136,
    -256,  -256,  -256,  -256,    72,  -256,  -256,  -256,    -9,   146,
    -256,    33,   116,   106,  -256,  -256,   177,  -256,   120,    35,
     181,  -256,  -256,   -13,  -256,   115,   269,    13,   259,    33,
     160,   147,  -256,   154,   161,   163,  -256,    48,    55,  -256,
     166,   177,   184,  -256,   202,   214,    18,  -256,   217,   220,
     182,  -256,  -256,   186,  -256,  -256,   112,  -256,  -256,  -256,
     215,  -256,   223,   231,   373,   235,  -256,  -256,  -256,   224,
      64,    64,  -256,  -256,  -256,  -256,   373,    36,    36,    36,
     129,   268,     6,   141,   245,   241,   243,   244,   246,   277,
     248,  -256,  -256,   249,  -256,  -256,  -256,  -256,   110,  -256,
     262,   276,  -256,   311,   373,   177,   373,  -256,  -256,  -256,
      64,  -256,   282,   278,   281,  -256,  -256,  -256,  -256,  -256,
    -256,   373,   297,  -256,  -256,   320,   321,   373,  -256,    35,
    -256,   170,  -256,    35,  -256,  -256,  -256,   307,   176,   373,
    -256,   203,   203,    76,  -256,   182,  -256,  -256,   373,  -256,
     373,  -256,  -256,  -256,   373,   373,   373,   373,   373,   373,
     373,   373,   373,   373,  -256,  -256,  -256,   373,    33,   411,
      77,   298,    84,   155,   373,   335,    68,   307,   373,  -256,
     285,   307,   113,   289,   290,     1,   177,  -256,  -256,   273,
    -256,   269,  -256,   373,    57,   330,   332,  -256,   268,     6,
     141,   245,   245,   241,   243,   244,   246,   277,   248,  -256,
     307,  -256,   373,  -256,   249,     7,   331,  -256,   301,   315,
    -256,   195,   373,   307,   306,   278,  -256,   135,   307,   373,
     373,  -256,  -256,  -256,  -256,   307,   373,  -256,  -256,   104,
     177,   449,   177,   373,  -256,  -256,   140,   373,  -256,   373,
     201,   206,     0,     8,  -256,   373,   291,   342,  -256,   122,
     177,  -256,   218,   307,  -256,  -256,   341,  -256,   177,   126,
     449,   177,  -256,  -256,  -256,   305,  -256,   299,  -256,  -256,
    -256,   177,  -256
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
       0,    25,    82,     0,    51,     0,    48,   145,     0,     0,
       0,     0,   159,     0,     0,     0,    44,     0,     0,    41,
       0,    31,     0,    81,     0,     0,     0,    35,     0,     0,
      84,   146,    36,   152,    37,    38,     0,    55,    28,    53,
       0,    59,     0,     0,   141,   145,   124,   125,   133,     0,
       0,     0,   132,   126,   127,   135,     0,     0,     0,     0,
       0,    86,    88,    90,    96,    98,   100,   102,   104,   106,
     108,   110,   111,   112,   121,   123,   129,   130,   128,   131,
      66,    62,    64,     0,     0,     0,     0,    42,    43,   149,
       0,   148,    60,    70,    61,    68,    29,    30,    32,    34,
      33,     0,     0,    39,    40,     0,     0,     0,   153,     0,
      15,     0,    18,     0,    83,    12,    46,   139,     0,     0,
     145,   119,   117,     0,   114,   128,   113,   115,     0,   134,
       0,    93,    91,    92,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   116,   120,   118,     0,     0,     0,
       0,     0,     0,     0,   141,     0,     0,    77,     0,    80,
       0,    75,   128,   142,   143,     0,     0,    21,    14,     0,
      20,    48,   136,     0,     0,     0,     0,   122,    85,    87,
      89,    94,    95,    97,    99,   101,   103,   105,   107,   109,
      65,    63,     0,   171,     0,   167,     0,   155,     0,     0,
     147,     0,     0,    73,    60,    69,    67,     0,    79,   141,
     141,   144,   154,    19,    47,   140,     0,   142,   143,     0,
       0,     0,     0,     0,   157,    72,     0,   141,    76,     0,
       0,     0,     0,   165,   168,     0,   169,   161,   156,     0,
       0,    74,     0,    78,   137,   138,     0,   150,     0,     0,
       0,     0,   160,   158,    71,     0,   166,   170,   163,   162,
     151,     0,   164
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -256,  -256,   344,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
     142,    19,  -256,  -256,   334,   292,  -133,  -256,   139,  -256,
     -52,  -256,     2,  -256,   -11,  -256,  -256,  -256,   167,  -256,
     158,  -256,  -256,   114,   216,  -256,   219,   -50,   189,   192,
    -256,   190,   128,   197,   188,   193,   196,   198,   187,   194,
    -192,   -96,  -189,  -256,  -256,   -45,   -40,  -186,   -46,   323,
    -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,  -256,
    -256,  -256,  -256,  -255
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     9,    10,    11,    12,    43,    13,    28,    29,   161,
     162,    68,    18,    38,    69,    70,    71,    15,    92,   221,
      16,    21,   130,    34,    23,    24,    72,   131,   132,   144,
     145,    73,    74,   257,    75,    53,    76,   167,   111,   112,
     184,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,    77,   126,   127,   168,   128,    81,
     129,    82,   216,    83,   272,    84,   290,   135,    85,   301,
     311,   298,   270,   246
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      80,    78,   201,    35,    93,    22,    79,   243,   110,    40,
     245,   174,   176,   177,  -169,  -170,   287,   -23,   251,    14,
     178,   178,    45,    46,   181,    80,    78,    30,    89,    90,
      14,    79,   151,    50,    25,    51,    37,    19,    87,    33,
      95,    96,   296,    54,    97,   308,    98,   297,   261,   182,
     183,    99,   139,    94,   171,   172,   173,   143,   -23,   142,
     102,   175,   175,   175,  -121,  -122,   152,    17,   170,    88,
     103,   104,   254,   280,   281,    14,   106,   178,    20,   243,
      20,    67,   286,   262,   200,    26,   202,    31,   140,    80,
      78,   292,    39,    67,   203,    79,   178,   178,    36,   266,
      20,   207,   211,   244,   178,   163,   212,   215,   243,    67,
      44,   286,    41,    20,    49,     1,     2,   227,   247,   224,
      42,     1,     2,   159,   178,   249,    55,   155,     5,     3,
     155,     4,   195,   196,     5,   195,   196,   284,   156,   288,
      48,   156,   178,     6,    56,   283,   178,   240,   217,   178,
      52,     7,   220,   160,     8,   253,   157,   303,   258,   157,
      86,   -84,    91,   302,   133,   306,   179,   307,   309,    93,
      80,    78,   225,   265,   278,   244,    79,   279,   312,   291,
       1,    57,   279,   226,     1,     2,    58,   134,    59,    60,
     185,   186,   269,     5,   136,   255,   250,     5,   137,   155,
     138,   157,   258,    61,   244,   146,    62,    63,    64,    65,
     156,   218,   219,   158,    66,    46,   282,   222,   223,   164,
     225,   148,    67,   289,    80,    78,    80,    78,   157,   293,
      79,   226,    79,     1,     2,   299,   275,   223,   163,   149,
      14,    27,   294,   223,    80,    78,     5,   295,   223,   157,
      79,   150,    80,    78,   153,    80,    78,   154,    79,   304,
     223,    79,   165,    95,    96,    80,    78,    97,   166,    98,
     169,    79,     1,     2,    99,    94,     1,     2,     1,     2,
       3,   100,   101,   102,   159,     5,     3,   180,     4,     5,
     187,     5,   188,   103,   104,   189,   105,   190,   192,   106,
     191,    95,    96,   193,    67,    97,   194,    98,     7,   107,
     197,     8,    99,   231,   232,   108,   109,   199,   198,   100,
     101,   102,   204,   206,   213,   214,   205,   178,   248,   259,
     260,   103,   104,   152,   267,   208,   268,   106,   271,    95,
      96,   273,    67,    97,   274,    98,   277,   107,  -121,   300,
      99,   305,   310,   108,   109,    32,  -122,   100,   101,   102,
     264,   263,    47,   147,   256,   241,   276,   228,   209,   103,
     104,   210,   229,   252,   230,   106,   234,    95,    96,   238,
      67,    97,   235,    98,   233,   107,   236,   239,    99,   237,
     141,   108,   109,     0,     0,   100,   101,   102,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   103,   104,     0,
       0,     0,     0,   106,     0,    95,    96,     0,    67,    97,
       0,    98,     0,   107,     0,     0,    99,     0,     0,   108,
     109,     0,     0,   100,   101,   102,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   103,   104,     0,     0,     0,
       0,   242,     0,    95,    96,     0,    67,    97,     0,    98,
       0,   107,     0,     0,    99,     0,     0,   108,   109,     0,
       0,   100,   101,   102,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   103,   104,     0,     0,     0,     0,   285,
       0,     0,     0,     0,    67,     0,     0,     0,     0,   107,
       0,     0,     0,     0,     0,   108,   109
};

static const yytype_int16 yycheck[] =
{
      46,    46,   135,    14,    56,     3,    46,   199,    58,    20,
     199,   107,   108,   109,     7,     7,   271,     4,   204,     0,
      20,    20,    37,    38,    18,    71,    71,     8,    41,    42,
      11,    71,    14,    42,     4,    44,    17,     4,    49,     4,
       4,     5,    42,    41,     8,   300,    10,    47,    47,    43,
      44,    15,     4,    40,   100,   101,   106,    68,    45,     4,
      24,   107,   108,   109,    57,    57,    48,    43,     4,    50,
      34,    35,     4,   259,   260,    56,    40,    20,    45,   271,
      45,    45,   271,   216,   134,     5,   136,     0,    40,   135,
     135,   277,    40,    45,   140,   135,    20,    20,    37,    42,
      45,   151,   152,   199,    20,    86,   152,   157,   300,    45,
      37,   300,    42,    45,    42,     3,     4,    41,    41,   169,
      46,     3,     4,    11,    20,    41,    10,    17,    16,    11,
      17,    13,    22,    23,    16,    22,    23,   270,    28,   272,
       4,    28,    20,    25,    38,    41,    20,   197,   159,    20,
       4,    33,   163,    41,    36,   205,    46,   290,   208,    46,
      40,    48,    47,    41,     4,   298,    37,    41,   301,   221,
     216,   216,    17,   223,    39,   271,   216,    42,   311,    39,
       3,     4,    42,    28,     3,     4,     9,    40,    11,    12,
      49,    50,   242,    16,    40,   206,    41,    16,    37,    17,
      37,    46,   252,    26,   300,    39,    29,    30,    31,    32,
      28,    41,    42,    27,    37,    38,   266,    41,    42,     4,
      17,    37,    45,   273,   270,   270,   272,   272,    46,   279,
     270,    28,   272,     3,     4,   285,    41,    42,   219,    37,
     221,    11,    41,    42,   290,   290,    16,    41,    42,    46,
     290,    37,   298,   298,    37,   301,   301,    37,   298,    41,
      42,   301,    39,     4,     5,   311,   311,     8,    37,    10,
      46,   311,     3,     4,    15,    40,     3,     4,     3,     4,
      11,    22,    23,    24,    11,    16,    11,    19,    13,    16,
      45,    16,    51,    34,    35,    52,    37,    53,    21,    40,
      54,     4,     5,    55,    45,     8,    57,    10,    33,    50,
      48,    36,    15,   185,   186,    56,    57,     6,    42,    22,
      23,    24,    40,    42,     4,     4,    48,    20,    30,    40,
      40,    34,    35,    48,     4,    38,     4,    40,     7,     4,
       5,    40,    45,     8,    29,    10,    40,    50,    57,     7,
      15,    10,    47,    56,    57,    11,    57,    22,    23,    24,
     221,   219,    28,    71,   206,   198,   252,   178,   152,    34,
      35,   152,   180,    38,   184,    40,   188,     4,     5,   192,
      45,     8,   189,    10,   187,    50,   190,   193,    15,   191,
      67,    56,    57,    -1,    -1,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    34,    35,    -1,
      -1,    -1,    -1,    40,    -1,     4,     5,    -1,    45,     8,
      -1,    10,    -1,    50,    -1,    -1,    15,    -1,    -1,    56,
      57,    -1,    -1,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    -1,    -1,    -1,
      -1,    40,    -1,     4,     5,    -1,    45,     8,    -1,    10,
      -1,    50,    -1,    -1,    15,    -1,    -1,    56,    57,    -1,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    40,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    -1,    50,
      -1,    -1,    -1,    -1,    -1,    56,    57
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    11,    13,    16,    25,    33,    36,    59,
      60,    61,    62,    64,    69,    75,    78,    43,    70,     4,
      45,    79,    80,    82,    83,     4,     5,    11,    65,    66,
      69,     0,    60,     4,    81,    82,    37,    69,    71,    40,
      82,    42,    46,    63,    37,    37,    38,    72,     4,    42,
      42,    44,     4,    93,    80,    10,    38,     4,     9,    11,
      12,    26,    29,    30,    31,    32,    37,    45,    69,    72,
      73,    74,    84,    89,    90,    92,    94,   112,   113,   114,
     116,   117,   119,   121,   123,   126,    40,    82,    69,    41,
      42,    47,    76,    78,    40,     4,     5,     8,    10,    15,
      22,    23,    24,    34,    35,    37,    40,    50,    56,    57,
      95,    96,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   113,   114,   116,   118,
      80,    85,    86,     4,    40,   125,    40,    37,    37,     4,
      40,   117,     4,    82,    87,    88,    39,    73,    37,    37,
      37,    14,    48,    37,    37,    17,    28,    46,    27,    11,
      41,    67,    68,    69,     4,    39,    37,    95,   115,    46,
       4,   116,   116,    95,   109,   116,   109,   109,    20,    37,
      19,    18,    43,    44,    98,    49,    50,    45,    51,    52,
      53,    54,    21,    55,    57,    22,    23,    48,    42,     6,
      95,    74,    95,   116,    40,    48,    42,    95,    38,    92,
      94,    95,   116,     4,     4,    95,   120,    82,    41,    42,
      82,    77,    41,    42,    95,    17,    28,    41,    96,    97,
      99,   100,   100,   101,   102,   103,   104,   105,   106,   107,
      95,    86,    40,   108,   109,   110,   131,    41,    30,    41,
      41,   115,    38,    95,     4,    82,    88,    91,    95,    40,
      40,    47,    74,    68,    76,    95,    42,     4,     4,    95,
     130,     7,   122,    40,    29,    41,    91,    40,    39,    42,
     115,   115,    95,    41,    74,    40,   110,   131,    74,    95,
     124,    39,   115,    95,    41,    41,    42,    47,   129,    95,
       7,   127,    41,    74,    41,    10,    74,    41,   131,    74,
      47,   128,    74
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    63,    62,    64,    65,    65,    66,    66,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    71,    72,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    77,    76,    76,    78,
      78,    79,    79,    80,    80,    81,    81,    82,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    87,    87,    87,
      87,    87,    87,    88,    88,    89,    89,    90,    91,    91,
      92,    92,    93,    93,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    98,    99,    99,    99,   100,   100,   101,
     101,   102,   102,   103,   103,   104,   104,   105,   105,   106,
     106,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   111,   111,   112,   112,   113,   114,   114,   115,
     115,   115,   116,   116,   116,   116,   116,   117,   117,   117,
     118,   118,   119,   120,   119,   122,   121,   124,   123,   125,
     123,   127,   126,   128,   126,   129,   126,   130,   126,   131,
     131,   131
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
       1,     1,     1,     1,     3,     2,     4,     6,     6,     1,
       3,     0,     3,     3,     4,     1,     1,     4,     2,     2,
       6,     8,     1,     0,     4,     0,     6,     0,     7,     0,
       7,     0,     8,     0,    10,     0,     8,     0,     6,     1,
       3,     1
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
#line 1470 "src/lexer/y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 39 "src/lexer/parser.y"
                                     {label("Struct def");}
#line 1476 "src/lexer/y.tab.c"
    break;

  case 14: /* funcDef: ret_type IDENTIFIER '(' parameters ')'  */
#line 45 "src/lexer/parser.y"
                                                          {label("Function def");}
#line 1482 "src/lexer/y.tab.c"
    break;

  case 15: /* funcDef: ret_type IDENTIFIER '(' ')'  */
#line 46 "src/lexer/parser.y"
                                               {label("Function def");}
#line 1488 "src/lexer/y.tab.c"
    break;

  case 32: /* statement: decl_assgn ';'  */
#line 77 "src/lexer/parser.y"
                                    {label("Declaration");}
#line 1494 "src/lexer/y.tab.c"
    break;

  case 33: /* statement: multi_assign ';'  */
#line 78 "src/lexer/parser.y"
                                    {label("Assignment");}
#line 1500 "src/lexer/y.tab.c"
    break;

  case 34: /* statement: augAssign ';'  */
#line 79 "src/lexer/parser.y"
                                    {label("Augmented Assignment");}
#line 1506 "src/lexer/y.tab.c"
    break;

  case 35: /* statement: ret  */
#line 80 "src/lexer/parser.y"
                                    {label("Return");}
#line 1512 "src/lexer/y.tab.c"
    break;

  case 39: /* statement: call ';'  */
#line 84 "src/lexer/parser.y"
                                    {label("Function Call");}
#line 1518 "src/lexer/y.tab.c"
    break;

  case 40: /* statement: obj_call ';'  */
#line 85 "src/lexer/parser.y"
                                    {label("Object Function Call");}
#line 1524 "src/lexer/y.tab.c"
    break;

  case 42: /* statement: BREAK ';'  */
#line 87 "src/lexer/parser.y"
                                    {label("Break");}
#line 1530 "src/lexer/y.tab.c"
    break;

  case 43: /* statement: CONTINUE ';'  */
#line 88 "src/lexer/parser.y"
                                    {label("Continue");}
#line 1536 "src/lexer/y.tab.c"
    break;

  case 46: /* $@2: %empty  */
#line 95 "src/lexer/parser.y"
                                 {label("Declaration");}
#line 1542 "src/lexer/y.tab.c"
    break;

  case 153: /* $@3: %empty  */
#line 280 "src/lexer/parser.y"
                                {label("Else stetement");}
#line 1548 "src/lexer/y.tab.c"
    break;

  case 155: /* $@4: %empty  */
#line 283 "src/lexer/parser.y"
                                  {label("If statement");}
#line 1554 "src/lexer/y.tab.c"
    break;

  case 157: /* $@5: %empty  */
#line 286 "src/lexer/parser.y"
                                            {label("Loop");}
#line 1560 "src/lexer/y.tab.c"
    break;

  case 159: /* $@6: %empty  */
#line 287 "src/lexer/parser.y"
                          {label("Loop");}
#line 1566 "src/lexer/y.tab.c"
    break;

  case 161: /* $@7: %empty  */
#line 290 "src/lexer/parser.y"
                                                            {label("For loop");}
#line 1572 "src/lexer/y.tab.c"
    break;

  case 163: /* $@8: %empty  */
#line 291 "src/lexer/parser.y"
                                                                          {label("For loop");}
#line 1578 "src/lexer/y.tab.c"
    break;

  case 165: /* $@9: %empty  */
#line 292 "src/lexer/parser.y"
                                                 {label("For loop");}
#line 1584 "src/lexer/y.tab.c"
    break;

  case 167: /* $@10: %empty  */
#line 293 "src/lexer/parser.y"
                                           {label("For loop");}
#line 1590 "src/lexer/y.tab.c"
    break;


#line 1594 "src/lexer/y.tab.c"

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
