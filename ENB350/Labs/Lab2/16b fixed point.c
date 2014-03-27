#include <stdio.h>
typedef struct {
	int whole;
	unsigned int fraction;
} fp16;

int fp16make(int a, unsigned int b, fp16 *px) {
     px->whole = a;
     px->fraction = b;
     return 0;
}

int longtofp16(long A, fp16 *px){
   int whole = A >> 16;
	unsigned int fraction = (int)(A & 0x0000FFFF);
	fp16make(whole, fraction, px);
   return 0;
}

long fp16tolong(fp16 *px){
   long A =0;
   A = (long)px->whole << 16 | (long)px->fraction;
   return A;
}

int fp16Todecimal(fp16 *px) {
	unsigned int wholedig = 0;
	unsigned long holdfrac = 0x00000000;
	//printf("whole part is %d", px->whole);
	if ( px->whole >= 0 || px->fraction == 0){
		int i;
		printf("%d.", px->whole);
		holdfrac = px->fraction;
		for(i = 0; (i <2 || holdfrac != 0); i++) {
			//printf( "x is %lu", x);
			holdfrac = holdfrac *0xA;
			//printf("\nholdfrac is now %lx", holdfrac);
			wholedig = (int)(holdfrac >> 16); //takes the whole integer section into wholedig
			printf("%u", wholedig);//prints out integer
			holdfrac = holdfrac & 0x0000FFFF;// zeroes out integer section
			//printf("\tholdfrac is now %x", holdfrac);
		}
	}
	else{
		int i;
		//printf("is negative\t");
      if(px->whole +1 == 0)
      	printf("-");
		printf("%d.", (px->whole +1));
		holdfrac = 0x10000 - px->fraction;
		for(i = 0; i <2 || holdfrac != 0; i++) {
			//printf( "x is %lu", x);
			holdfrac = holdfrac *0xA;
			//printf("\nholdfrac is now %lx", holdfrac);
			wholedig = (int)(holdfrac >> 16);
			printf("%u", wholedig);
			holdfrac = holdfrac & 0x0000FFFF;
			//printf("\tholdfrac is now %x", holdfrac);
		}
   	}
   return 0;
}

int fp16sum(fp16 *px, fp16 *py, fp16 *padd) {
 long A, B, C;
 A = fp16tolong(px);
 B = fp16tolong(py);
 C = A + B;
 //printf(" %ld + %ld = %ld", A, B, C);
 longtofp16(C, padd);
 return 0;
}

int fp16diff(fp16 *px, fp16 *py, fp16 *pdiff) {
 long A, B, C;
 A = fp16tolong(px);
 B = fp16tolong(py);
 C = A - B;
 //printf(" %ld + %ld = %ld", A, B, C);
 longtofp16(C, pdiff);
 return 0;
}
main()
{
unsigned long prodUnsigned();
int fp16make(); // declaration for function to create fp16
int fp16sum(); // function to add
int fp16diff(); // function to subtract
int fp16prod(); // function to multiply
int fp16Todec(); // function to convert to decimal and display
// The above functions must also be defined and implemented with
// return types and arguments as explained in the task descriptions
// variables to be used for test operands, results
fp16 x,y,prod,*px, *py,*pprod, radd, *pradd, rdiff, *prdiff;
int a, c; // whole parts of test operands
unsigned int b, d; // fraction parts of test operands
// hard coded test operand fields. Change, edit and recompile.
a = 0xFFF0;
b = (unsigned int) 0x0000; // a and b now represent 2.75
c = 0xFFFF; //for -2
d = (unsigned int) 0x4000; // c and d now represent -1.25
//pointers
px = &x;
py = &y;
pprod = &prod;
pradd = &radd;
prdiff = &rdiff;
// perform test operations to check
fp16make(a,b,px);
fp16make(c,d,py);
fp16prod(px,py,pprod);
fp16sum(px,py,pradd);
fp16diff(px,py,prdiff);
// print out the operands and results as hex numbers
printf("x = %4x.%4x \n",px->whole,px->fraction);
printf("y = %4x.%4x \n",py->whole,py->fraction);
printf("product = %4x.%4x \n",prod.whole,prod.fraction);
// print out the operands and results as decimal numbers
printf("IN DECIMAL FORM \n");
printf("x = "); fp16Todecimal(px); printf("\n");
printf("y = "); fp16Todecimal(py); printf("\n");
printf("product = "); fp16Todecimal(pprod); printf("\n");
printf("sum = ");fp16Todecimal(pradd); printf("\n");
printf("diff = ");fp16Todecimal(prdiff); printf("\n");

printf("\n\n Test Case 2\n");

a = 0x0002;
b = (unsigned int) 0x8000; // ab should be 2.5
c = 0x0000;
d = (unsigned int) 0x8000; //ab should be 0.5
fp16make(a,b,px);
fp16make(c,d,py);
fp16prod(px,py,pprod);
fp16sum(px,py,pradd);
fp16diff(px,py,prdiff);
printf("x = "); fp16Todecimal(px); printf("\n");
printf("y = "); fp16Todecimal(py); printf("\n");
printf("product = "); fp16Todecimal(pprod); printf("\n");
printf("sum = ");fp16Todecimal(pradd); printf("\n");
printf("diff = ");fp16Todecimal(prdiff); printf("\n");

printf("\n\n Test Case 3\n");

a = 0xFFFFFFFD;
b = (unsigned int) 0x8000; // ab should be -2.5
c = 0x0000;
d = (unsigned int) 0x8000; //ab should be 0.5
fp16make(a,b,px);
fp16make(c,d,py);
fp16prod(px,py,pprod);
fp16sum(px,py,pradd);
fp16diff(px,py,prdiff);
printf("x = "); fp16Todecimal(px); printf("\n");
printf("y = "); fp16Todecimal(py); printf("\n");
printf("product = "); fp16Todecimal(pprod); printf("\n");
printf("sum = ");fp16Todecimal(pradd); printf("\n");
printf("diff = ");fp16Todecimal(prdiff); printf("\n");

printf("\n\n Test Case 4\n");

a = 0xFF53;
b = (unsigned int) 0xF000; // ab should be 2^15-1
c = 0xFFEE;
d = (unsigned int) 0xA000; //ab should be 2^15-1
fp16make(a,b,px);
fp16make(c,d,py);
fp16prod(px,py,pprod);
fp16sum(px,py,pradd);
fp16diff(px,py,prdiff);
printf("x = "); fp16Todecimal(px); printf("\n");
printf("y = "); fp16Todecimal(py); printf("\n");
printf("product = "); fp16Todecimal(pprod); printf("\n");
printf("sum = ");fp16Todecimal(pradd); printf("\n");
printf("diff = ");fp16Todecimal(prdiff); printf("\n");

printf("\n\n Test Case 5\n");

a = 0x8000A;
b = (unsigned int) 0xF000; // ab should be 2^15-1
c = 0x050A;
d = (unsigned int) 0x8000; //ab should be -2^15
fp16make(a,b,px);
fp16make(c,d,py);
fp16prod(px,py,pprod);
fp16sum(px,py,pradd);
fp16diff(px,py,prdiff);
printf("x = "); fp16Todecimal(px); printf("\n");
printf("y = "); fp16Todecimal(py); printf("\n");
printf("product = "); fp16Todecimal(pprod); printf("\n");
printf("sum = ");fp16Todecimal(pradd); printf("\n");
printf("diff = ");fp16Todecimal(prdiff); printf("\n");
fp16prod();
exit(0);
}

unsigned long prodUnsigned(unsigned int x, unsigned int y);
#asm
prodUnsigned::
	ld hl,(sp+4)
	ex de,hl
	ld hl,(sp+2)
	ex bc, hl
	MULU
	ex bc, hl
	ex de, hl
	ret
#endasm


int fp16prod(fp16 *px, fp16 *py, fp16 *pprod){
   unsigned long high, mid, low, result;
   long A = fp16tolong(px);
   long B = fp16tolong(py);
   high = prodUnsigned(px->whole, py->whole);
   mid = prodUnsigned(px->whole, py->fraction)+ prodUnsigned(px->fraction, py->whole);
   low = prodUnsigned(px->fraction, py->fraction);
   result = ((high << 16) & 0xFFFF0000) + mid + ((low >> 16) & 0x0000FFFF);

   if (px->whole < 0){
   	result = result - (B << 16);
   }
   if (py->whole < 0) {
   	result = result - (A <<16);
   }
   longtofp16(result, pprod);
   return 0;

}