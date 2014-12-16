/*
  bluepp
  2014-12-16
  May the force be with me!
  
  http://www.mitbbs.com/article_t/JobHunting/32849681.html
  
*/

/* http://jlmedina123.wordpress.com/2014/03/11/memcpy-implementation/ */
#include <stdio.h>
#include <string.h>
 
 
void mymemcpy1(void *, const void *, size_t );
void mymemcpy2(void *, const void *, size_t );
void mymemcpy3(void *, const void *, size_t );
void mymemcpy4(void *, const void *, size_t );
 
int main(int argc, char **argv) {
 char source[] = "0123456789abdcdefghi";  // 21 bytes (20 letters + '\0')
    char dest[100];
 
    // void * memcpy ( void * destination, const void * source, size_t num );
    memcpy(dest, source, strlen(source) + 1);
    printf("Source: %s. Destination: %s\n", source, dest);
 
    strcpy(source, "ABCDEFGHI0123456789");
    mymemcpy1(dest, source, strlen(source) + 1);
    printf("Source: %s. Destination: %s\n", source, dest);
 
    strcpy(source, "0123456789101112131415");
    mymemcpy2(dest, source, strlen(source) + 1);
    printf("Source: %s. Destination: %s\n", source, dest);
 
    strcpy(source, "0123456789abdcdefghi");
    mymemcpy3(dest, source, strlen(source) + 1);
    printf("Source: %s. Destination: %s\n", source, dest);
 
    strcpy(source, "-0-1-2-3-4-5-6-7-8-9");
    mymemcpy4(dest, source, strlen(source) + 1);
    printf("Source: %s. Destination: %s\n", source, dest);
    return 0;
}
 
// simple implementation
void mymemcpy1(void *dest, const void *source, size_t num) {
    int i = 0;
    // casting pointers
    char *dest8 = (char *)dest;
    char *source8 = (char *)source;
    printf("Copying memory %d byte(s) at a time\n", sizeof(char));
    for (i = 0; i < num; i++) {
        dest8[i] = source8[i];
    }
}
// it checks that destination array does not overwrite
// source array
void mymemcpy2(void *dest, const void *source, size_t num) {
    int i = 0;
    // casting pointers
    char *dest8 = (char *)dest;
    char *source8 = (char *)source;
    printf("Copying memory %d byte(s) at a time\n", sizeof(char));
    for (i = 0; i < num; i++) {
        // make sure destination doesnt overwrite source
        if (&dest8[i] == source8) {
            printf("destination array address overwrites source address\n");
            return;
        }
        dest8[i] = source8[i];
    }
}
 
// copies 1 word at a time (8 bytes at a time)
void mymemcpy3(void *dest, const void *source, size_t num) {
    int i = 0;
    // casting pointers
    long *dest32 = (long *)dest;
    long *source32 = (long *)source;
    char *dest8 = (char *)dest;
    char *source8 = (char *)source;
 
    printf("Copying memory %d byte(s) at a time\n", sizeof(long));
    for (i = 0; i < num/8; i++) {
        if (&dest32[i] == source32) {
            printf("destination array address overwrites source address\n");
            return;
        }
        dest32[i] = source32[i];
    }
    // copy the last bytes
    dest8 =  (char *)&dest32[i];
    source8 = (char *)&source32[i];
    for (i = 0 ; i < num; i++) {
        dest8[i] = source8[i];
    }
}




/* --------------------------------------------------------------------------- */
/* http://www.opensource.apple.com/source/xnu/xnu-2050.18.24/libsyscall/wrappers/memcpy.c */
#include "string.h"

/*
 * sizeof(word) MUST BE A POWER OF TWO
 * SO THAT wmask BELOW IS ALL ONES
 */
typedef	int word;		/* "word" used for optimal copy speed */

#define	wsize	sizeof(word)
#define	wmask	(wsize - 1)

/*
 * Copy a block of memory, handling overlap.
 * This is the routine that actually implements
 * (the portable versions of) bcopy, memcpy, and memmove.
 */

__private_extern__
void * memcpy(void *dst0, const void *src0, size_t length)
{
	char *dst = dst0;
	const char *src = src0;
	size_t t;
	
	if (length == 0 || dst == src)		/* nothing to do */
		goto done;
	
	/*
	 * Macros: loop-t-times; and loop-t-times, t>0
	 */
#define	TLOOP(s) if (t) TLOOP1(s)
#define	TLOOP1(s) do { s; } while (--t)
	
	if ((unsigned long)dst < (unsigned long)src) {
		/*
		 * Copy forward.
		 */
		t = (uintptr_t)src;	/* only need low bits */
		if ((t | (uintptr_t)dst) & wmask) {
			/*
			 * Try to align operands.  This cannot be done
			 * unless the low bits match.
			 */
			if ((t ^ (uintptr_t)dst) & wmask || length < wsize)
				t = length;
			else
				t = wsize - (t & wmask);
			length -= t;
			TLOOP1(*dst++ = *src++);
		}
		/*
		 * Copy whole words, then mop up any trailing bytes.
		 */
		t = length / wsize;
		TLOOP(*(word *)dst = *(word *)src; src += wsize; dst += wsize);
		t = length & wmask;
		TLOOP(*dst++ = *src++);
	} else {
		/*
		 * Copy backwards.  Otherwise essentially the same.
		 * Alignment works as before, except that it takes
		 * (t&wmask) bytes to align, not wsize-(t&wmask).
		 */
		src += length;
		dst += length;
		t = (uintptr_t)src;
		if ((t | (uintptr_t)dst) & wmask) {
			if ((t ^ (uintptr_t)dst) & wmask || length <= wsize)
				t = length;
			else
				t &= wmask;
			length -= t;
			TLOOP1(*--dst = *--src);
		}
		t = length / wsize;
		TLOOP(src -= wsize; dst -= wsize; *(word *)dst = *(word *)src);
		t = length & wmask;
		TLOOP(*--dst = *--src);
	}
done:
	return (dst0);
}

__private_extern__ void *
memmove(void *s1, const void *s2, size_t n)
{
	return memcpy(s1, s2, n);
}

__private_extern__ void
bcopy(const void *s1, void *s2, size_t n)
{
	memcpy(s2, s1, n);
}
