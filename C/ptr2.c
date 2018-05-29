#include <stdio.h>
#include <stdlib.h>

struct mheader {

#define MBLOCKSIZE 8
#define MBLOCKSHIFT 3
#define MMAGIC 2
	unsigned mh_prevblock:29;
	unsigned mh_pad:1;
	unsigned mh_magic1:2;

	unsigned mh_nextblock:29;
	unsigned mh_inuse:1;
	unsigned mh_magic2:2;
};


#define M_NEXTOFF(mh)	((size_t)(((size_t)((mh)->mh_nextblock))<<MBLOCKSHIFT))
#define M_PREVOFF(mh)	((size_t)(((size_t)((mh)->mh_prevblock))<<MBLOCKSHIFT))
#define M_NEXT(mh)	((struct mheader *)(((char*)(mh))+M_NEXTOFF(mh)))
#define M_PREV(mh)	((struct mheader *)(((char*)(mh))-M_PREVOFF(mh)))

#define M_DATA(mh)	((void *)((mh)+1))
#define M_SIZE(mh)	(M_NEXTOFF(mh)-MBLOCKSIZE)

#define M_OK(mh)	((mh)->mh_magic1==MMAGIC && (mh)->mh_magic2==MMAGIC)

#define M_MKFIELD(off)	((off)>>MBLOCKSHIFT)

int
main()
{

    struct mheader *mh;

    mh = malloc(sizeof(*mh));

    mh->mh_nextblock = 16;

    printf("mh: %p\n",mh);
    printf("mh + 3: %p\n",(char *)mh+3);
    printf("mh + 16: %p\n",(char *)mh+16);
    printf("mh + NEXTOFF: %p\n",(char *)mh+M_NEXTOFF(mh));

    printf("NEXTOFF 16: %lu\n", M_NEXTOFF(mh));
    printf("NEXT: %p\n", M_NEXT(mh));
    printf("MKFIELD: %lu\n", M_MKFIELD(M_NEXTOFF(mh)));

}
