
// other compliation units would be included here, more on this later
//#include <stdint.h>
#include <stdio.h>


// all portions of this activity are inside the main entry point function
// sections are selected by commenting / uncommenting define statements below

////////////////////////////////////////////////
// comment in the part(s) you want to operate
#define Part_Demo
//define Part_A
//#define Part_B
//#define Part_C
////////////////////////////////////////////////

// this function is the main application entry point
//  (it's essentially where your code starts running after reset)

int main(void) 
{    
  // preprocessor directives are evaluated prior to compliation
  // conditional preprocessor directives like ifdef and ifndef allow code to be enabled/disabled with simple flags
  

  #ifdef Part_Demo  
  // instructor demo to draw attention to some compiler features, and to get this activity going
  
  // one-time inits section (this is where you do things only once)
  
  int iCount = 0;
  unsigned short i = 0xDEAD;

  // set a breakpoint on the following line, run to the breakpoint
  while (++i)
  {
    ++iCount;
  }

  // use the debugger to figure out the value of iCount after the loop falls out  
  
  // what happens if we change the type of i from short to int? (demo break function, note debugger limitations)

  // programs must *never* leave the main function
  // loop section (do nothing for now)
  while (1);
    
  #endif
  

  #ifdef Part_A
  /////////////////////////////////////////////////////////////////
  // Part A
  /////////////////////////////////////////////////////////////////
  { // what is the significance of this bracket (new scope)
    
    // why declare a variable in a new scope?
    int iCount = 0;

    // why use unsigned?
    // why represent this number in hex, why not decimal, or binary for that matter?
    // what is going on with the entry expression of this loop, and how does this differ from C#?
    for (unsigned int i = 0x8000; i; i >>= 1)
    {
      // this this statement need to be here, or could it be a part of the 'for' statement?
      //  if you did move it, how should the loop body be expressed?
      iCount++;
    }
  
    // printf statements are similar to string interploation in C#, just a little more basic, with
    //  very little error checking. In the case below, the %d will be substituted with the value of iCount.
    //  the %d means 'decimal', and there are others. We will cover these off in time.
    printf ("the loop ran %d times!", iCount);

    // where does this output appear when you Build/Run?
    // where does this output appear when you Build/Debug?
  }

  // programs must *never* leave the main function
  // loop section (do nothing for now)
  while (1);

  #endif


  #ifdef Part_B
  /////////////////////////////////////////////////////////////////
  // Part B
  /////////////////////////////////////////////////////////////////

  // use the debugger to figure out the required answers
  typedef unsigned char byte;

  // B1: 
  {
    byte i = 0b10100101;

    for (byte mask = 1; i & 0x0F; mask <<= 1)
      i &= ~mask;
  }

  // what is the value of i after the above loop; provide a brief summary
  //  of what the operation above did
  //////////////////////////////////////



  //////////////////////////////////////


  // B2:
  // complete the code so that i does not have the first or last bit set
  //  any other bits in i will remain unaffected
  //  i can be given any initial value and the code will operate the same way
  // use the debugger to validate your code
  {
    byte i = 0xF7;

  // add your code here, then test with the debugger (use various initial values for i)
    
  }
  
  // B3:
  // complete the code so that i always has the most significant bit set
  //  any other bits in i will remain unaffected
  //  i can be given any initial value and the code will operate the same way
  // use the debugger to validate your code
  {
    byte i = 0x27;

    // add your code here, then test with the debugger (use various initial values for i)
    
  }

  // B4:
  // complete the code so that it counts the number of cleared bits in i
  // you may leave the result in a variable and check that it has the right
  //  value with the debugger
  //  i can be given any initial value and the code will operate the same way
  {
    byte i = 0x27;

    // add your code here, then test with the debugger (use various initial values for i)
    
  }

  // B5: skill testing!
  // complete the code so that i has only two bits set, clearing bits on the right
  //  until this is true. When your code is complete, i will have two bits set, regardless
  //  of the initial value (backfilling bits on the left as necessary)
  {
    byte i = 0x01; // outcome should be 0x81

    // add your code here, then test with the debugger (use various initial values for i)

  }

  // programs must *never* leave the main function
  // loop section (do nothing for now)
  while (1);

  #endif


  #ifdef Part_C

  // a struct definition for the following code
  typedef struct thing
  {
    int i;
    float f;
    char c;
  } SThing;

  // create an instance of the struct on the local stack
  // use the debugger to determine where the data is, and
  //  where the code is that is populating the structure
  SThing aThing;
  aThing.i = 42;
  aThing.f = 3.14f;
  aThing.c = ('A' + 'Z') / 2;

  // a super brief about pointers (for in-class discussion)
  // the *point* here is that a pointer is just an address
  SThing * pThing = &aThing;

  printf ("\r\nThe pointer is pointing at memory %p", pThing);

  pThing++;

  printf ("\r\nThe pointer is pointing at memory %p", pThing);

  #endif
}

/*************************** End of file ****************************/
