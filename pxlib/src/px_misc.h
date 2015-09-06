#ifndef __PX_MISC_H__
#define __PX_MISC_H__
extern void px_put_long_le(char *cp, long lval);
extern long px_get_long_le(const char *cp);
extern unsigned short int px_get_short_le(const char *cp);
extern short int px_get_short_le_s(const char *cp);
extern void px_put_short_le(char *cp, short int sval);
extern void px_put_double_le(char *cp, double fval);
extern double px_get_double_le(const char *cp);

extern void px_put_long_be(char *cp, long lval);
extern long px_get_long_be(const char *cp);
extern short int px_get_short_be(const char *cp);
extern void px_put_short_be(char *cp, short int sval);
extern void px_put_double_be(char *cp, double fval);
extern double px_get_double_be(const char *cp);

extern void px_copy_fill(char *dp, char *sp, int len);
extern void px_copy_crimp(char *dp, char *sp, int len);
extern void px_set_date(char *cp, int year, int month, int day);
extern int px_date_year(char *cp);
extern int px_date_month(char *cp);
extern int px_date_day(char *cp);
extern char *px_cur_date(char *cp);
extern int px_get_date(char *cp);
extern void px_hex_dump(FILE *outfp, char *p, int len);
#endif
