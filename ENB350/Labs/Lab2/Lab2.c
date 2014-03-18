main()
{
typedef struct {
int whole;
unsigned int fraction;
} fp16;

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
a = 0x0002;
b = (unsigned int) 0xC000; // a and b now represent 2.75
c = 0xFFFE;
d = (unsigned int) 0xC000; // c and d now represent -1.25
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
exit(0);
}


int fp16make(int a, unsigned int b, fp16 *px){
    unsigned long c = a << 16;
    c = c | b;

    if(a < 0){
       c = (c ^ 16777215) + 1;
    }
	px->whole = (c >> 16);

   px->decimal = (c & 65535)

}

int fp16Todec() {

}