//#define __test_Andy__
//#define __test_Jeff__
#define __test_text__

#include "simpletools.h"
/*
#ifdef __test_text__
#include "simpletext.h"
#endif
*/

/*
char ecListRN[] = {'\r', '\n', 0, 0};    // List of recognized end characters
char ecListR[]  = {'\r',    0, 0, 0};    
char ecListN[]  = {'\n',    0, 0, 0};    

char ecsrn[]  = {'\r', '\n', 0, 0};      // \r\n end character list
char ecsn[]   = {'\n',    0, 0, 0};      // \n character list
char ecsr[]   = {'\r',    0, 0, 0};      // \r character list
*/

char ecListRN[] = {'\r', '\n', 0};    // List of recognized end characters
char ecListR[]  = {'\r',    0, 0};    
char ecListN[]  = {'\n',    0, 0};    

char ecsrn[]  = {'\r', '\n', 0};      // \r\n end character list
char ecsr[]   = {'\r',    0, 0};      // \r character list
char ecsn[]   = {'\n',    0, 0};      // \n character list

char str[] = "abcdef\0 ";


// c is the character string, ec is the list of end characters,
// and ecs is the end character sequence that should tx as soon
// as an ec is detected in c.

#ifdef __test_Andy__
void send_ecs(char *c, char *ec, char *ecs)
{ 
  while(1)
  {
    if( (*c == *ec) || (*c == *(ec+1))  || (*c == *(ec+2))  || (*c == *(ec+3)) )
    {
      while(1)
      {
        if(*ecs == 0 || *c == 0) return;
        putChar(*ecs++);
      }
    }
    putChar(*c++);  
  }
} 
#endif


#ifdef __test_Jeff__
void send_ecs(char *c, char *ec, char *ecs)
{ 
  while(*c)
  {
    if( !( (*c == *ec) || (*c == *(ec+1)) ) )
    {
      putChar(*c++);  
    }
    else
    {
      while(*ecs) {putChar(*ecs++);}
      c++;
    }
  }
}                  
#endif


#ifndef __test_text__
int main()
{
  pause(500);
  memcpy(str, "abcdef\0", 8);
  send_ecs(str, ecListRN, ecsrn);
  send_ecs(str, ecListRN, ecsrn);
  memcpy(str, "abcdef\r", 8);
  send_ecs(str, ecListRN, ecsr);
  send_ecs(str, ecListRN, ecsr);
  memcpy(str, "abcdef\n", 8);
  send_ecs(str, ecListRN, ecsn);
  send_ecs(str, ecListRN, ecsn);
  memcpy(str, "abcdef\r\n", 9);
  send_ecs(str, ecListRN, ecsr);
  send_ecs(str, ecListRN, ecsr);
  send_ecs(str, ecListRN, ecsr);
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  
  memcpy(str, "abcdef\0", 8);
  send_ecs(str, ecListR, ecsrn);
  send_ecs(str, ecListR, ecsrn);
  memcpy(str, "abcdef\r", 8);
  send_ecs(str, ecListR, ecsr);
  send_ecs(str, ecListR, ecsr);
  memcpy(str, "abcdef\n", 8);
  send_ecs(str, ecListR, ecsn);
  send_ecs(str, ecListR, ecsn);
  memcpy(str, "abcdef\r\n", 9);
  send_ecs(str, ecListR, ecsr);
  send_ecs(str, ecListR, ecsr);
  send_ecs(str, ecListR, ecsr);
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  
  memcpy(str, "abcdef\0", 8);
  send_ecs(str, ecListN, ecsrn);
  send_ecs(str, ecListN, ecsrn);
  memcpy(str, "abcdef\r", 8);
  send_ecs(str, ecListN, ecsr);
  send_ecs(str, ecListN, ecsr);
  memcpy(str, "abcdef\n", 8);
  send_ecs(str, ecListN, ecsn);
  send_ecs(str, ecListN, ecsn);
  memcpy(str, "abcdef\r\n", 9);
  send_ecs(str, ecListN, ecsr);
  send_ecs(str, ecListN, ecsr);
  send_ecs(str, ecListN, ecsr);
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  print("0_n_rn\r");
  memcpy(str, "\0", 8);
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  print("0_n_r\r");
  memcpy(str, "\0", 8);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  print("0_n_n\r");
  memcpy(str, "\0", 8);
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  print("0_n_r\r");
  memcpy(str, "\0", 9);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  print("r_n_rn\r");
  memcpy(str, "\r", 8);
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  print("r_n_r\r");
  memcpy(str, "\r", 8);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  print("r_n_n\r");
  memcpy(str, "\r", 8);
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  print("r_n_r\r");
  memcpy(str, "\r", 9);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  print("n_n_rn\r");
  memcpy(str, "\n", 8);
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  print("n_n_r\r");
  memcpy(str, "\n", 8);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  print("n_n_n\r");
  memcpy(str, "\n", 8);
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  print("n_n_r\r");
  memcpy(str, "\n", 9);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  print("rn_n_rn\r");
  memcpy(str, "\r\n", 8);
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  send_ecs(str, ecListN, ecsrn);
  putChar('.');
  print("rn_n_r\r");
  memcpy(str, "\r\n", 8);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  print("rn_n_n\r");
  memcpy(str, "\r\n", 8);
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  send_ecs(str, ecListN, ecsn);
  putChar('.');
  print("rn_n_r\r");
  memcpy(str, "\r\n", 9);
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  send_ecs(str, ecListN, ecsr);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
}
#endif


#ifdef __test_text__
int main()
{
  pause(500);

  memcpy(str, "abcdef\0", 8);
  //send_ecs(str, ecListRN, ecsrn);
  //send_ecs(str, ecListRN, ecsrn);
  set_endChars(simpleterm_pointer(), ecListRN);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\r", 8);
  //send_ecs(str, ecListRN, ecsr);
  //send_ecs(str, ecListRN, ecsr);
  set_endChars(simpleterm_pointer(), ecListRN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\n", 8);
  //send_ecs(str, ecListRN, ecsn);
  //send_ecs(str, ecListRN, ecsn);
  set_endChars(simpleterm_pointer(), ecListRN);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\r\n", 9);
  //send_ecs(str, ecListRN, ecsr);
  //send_ecs(str, ecListRN, ecsr);
  //send_ecs(str, ecListRN, ecsr);
  set_endChars(simpleterm_pointer(), ecListRN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  print("%s", str);
  print("%s", str);
  
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  
  memcpy(str, "abcdef\0", 8);
  //send_ecs(str, ecListR, ecsrn);
  //send_ecs(str, ecListR, ecsrn);
  set_endChars(simpleterm_pointer(), ecListR);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\r", 8);
  //send_ecs(str, ecListR, ecsr);
  //send_ecs(str, ecListR, ecsr);
  set_endChars(simpleterm_pointer(), ecListR);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\n", 8);
  //send_ecs(str, ecListR, ecsn);
  //send_ecs(str, ecListR, ecsn);
  set_endChars(simpleterm_pointer(), ecListR);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\r\n", 9);
  //send_ecs(str, ecListR, ecsr);
  //send_ecs(str, ecListR, ecsr);
  //send_ecs(str, ecListR, ecsr);
  set_endChars(simpleterm_pointer(), ecListR);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  print("%s", str);
  print("%s", str);

  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  
  memcpy(str, "abcdef\0", 8);
  //send_ecs(str, ecListN, ecsrn);
  //send_ecs(str, ecListN, ecsrn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\r", 8);
  //send_ecs(str, ecListN, ecsr);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\n", 8);
  //send_ecs(str, ecListN, ecsn);
  //send_ecs(str, ecListN, ecsn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  print("%s", str);

  memcpy(str, "abcdef\r\n", 9);
  //send_ecs(str, ecListN, ecsr);
  //send_ecs(str, ecListN, ecsr);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  print("%s", str);
  print("%s", str);

  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
  
  print("0_n_rn\r");
  memcpy(str, "\0", 8);
  //send_ecs(str, ecListN, ecsrn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsrn);
  print("%s", str);
  putChar('.');

  print("0_n_r\r");
  memcpy(str, "\0", 8);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');

  print("0_n_n\r");
  memcpy(str, "\0", 8);
  //send_ecs(str, ecListN, ecsn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsn);
  print("%s", str);
  putChar('.');

  print("0_n_r\r");
  memcpy(str, "\0", 9);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);

  print("r_n_rn\r");
  memcpy(str, "\r", 8);
  //send_ecs(str, ecListN, ecsrn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  putChar('.');
  putChar('.');
  //send_ecs(str, ecListN, ecsrn);
  print("%s", str);
  putChar('.');

  print("r_n_r\r");
  memcpy(str, "\r", 8);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');

  print("r_n_n\r");
  memcpy(str, "\r", 8);
  //send_ecs(str, ecListN, ecsn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsn);
  print("%s", str);
  putChar('.');

  print("r_n_r\r");
  memcpy(str, "\r", 9);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);

  print("n_n_rn\r");
  memcpy(str, "\n", 8);
  //send_ecs(str, ecListN, ecsrn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsrn);
  print("%s", str);
  putChar('.');

  print("n_n_r\r");
  memcpy(str, "\n", 8);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  
  print("n_n_n\r");
  memcpy(str, "\n", 8);
  //send_ecs(str, ecListN, ecsn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsn);
  print("%s", str);
  putChar('.');

  print("n_n_r\r");
  memcpy(str, "\n", 9);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);

  print("rn_n_rn\r");
  memcpy(str, "\r\n", 8);
  //send_ecs(str, ecListN, ecsrn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsrn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsrn);
  print("%s", str);
  putChar('.');

  print("rn_n_r\r");
  memcpy(str, "\r\n", 8);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');

  print("rn_n_n\r");
  memcpy(str, "\r\n", 8);
  //send_ecs(str, ecListN, ecsn);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsn);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsn);
  print("%s", str);
  putChar('.');

  print("rn_n_r\r");
  memcpy(str, "\r\n", 9);
  //send_ecs(str, ecListN, ecsr);
  set_endChars(simpleterm_pointer(), ecListN);
  set_endCharSequence(simpleterm_pointer(), ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  //send_ecs(str, ecListN, ecsr);
  print("%s", str);
  putChar('.');
  putChar('\r');
  putChar('-');
  putChar('-');
  putChar('\r');
  putChar('\r');
  pause(500);
}
#endif