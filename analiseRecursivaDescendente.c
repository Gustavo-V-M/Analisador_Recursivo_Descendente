#include <stdlib.h>
#include <stdio.h>

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

#define TRUE 1
#define FALSE 0

char lookahead;

int match(char check, char palavra[], int *pos)
{
  if (lookahead == check){
    lookahead = palavra[++(*pos)];
    return TRUE;
  }
  return FALSE;
}


/*
* N = {E, S, K, T, Z, F, D}
* T = {+, -, *, /, (, ), 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
*
*
* E -> S$
* S -> TK
* K -> +TK
* K -> -TK
* K -> e 
* T -> FZ
* Z -> *FZ
* Z -> /FZ 
* Z -> e 
* F -> (S)
* F -> 1D | 2D | 3D | 4D | 5D | 6D | 7D | 8D | 9D 
* D -> 0D | 1D | 2D | 3D | 4D | 5D |6D  | 7D | 8D | 9D 
* D -> e 
* */

int E(char palavra[], int *pos);
int S(char palavra[], int *pos);
int K(char palavra[], int *pos);
int T(char palavra[], int *pos);
int Z(char palavra[], int *pos);
int F(char palavra[], int *pos);
int D(char palavra[], int *pos);

int E(char palavra[], int *pos)
{
  if (S(palavra, pos) && match('$', palavra, pos))
  {
    return TRUE;
  }
  return FALSE;
}

int S(char palavra[], int *pos)
{
  if(T(palavra, pos) && K(palavra, pos))
  {
    return TRUE;
  }
  return FALSE;
}

int K(char palavra[], int *pos)
{
  if (lookahead == '+')
  {
    if (match('+', palavra, pos) && T(palavra, pos), K(palavra, pos))
    {
      return TRUE;
    }
    return FALSE;
  }
  else if (lookahead == '-')
  {
    if (match('+', palavra, pos) && T(palavra, pos), K(palavra, pos))
    {
      return TRUE;
    }
    return FALSE;
  }
  
    return TRUE; // K -> e
}

int T(char palavra[], int *pos)
{
  if (F(palavra, pos) && Z(palavra, pos))
  {
    return TRUE;
  }
  return FALSE;
}

int Z(char palavra[], int *pos)
{
  if (lookahead == '*')
  {
    if (match('*', palavra, pos) && F(palavra, pos) && Z(palavra, pos))
    {
      return TRUE;
    }
    return FALSE;
  }
  else if (lookahead == '/')
  {
    if (match('/', palavra, pos) && F(palavra, pos) && Z(palavra, pos))
    {
      return FALSE;
    }
  }
  return TRUE; // Z -> e
}

int F(char palavra[], int *pos)
{
  if (lookahead == '(')
  {
    if (S(palavra, pos) && match(')', palavra, pos))
    {
      return TRUE;
    }
    return FALSE;
  }
  else if (lookahead == '1')
  {
    if(match('1', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '2')
  {
    if(match('2', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '3')
  {
    if(match('3', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '4')
  {
    if(match('4', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '5')
  {
    if(match('5', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '6')
  {
    if(match('6', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '7')
  {
    if(match('7', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '8')
  {
    if(match('8', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '9')
  {
    if(match('9', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  return FALSE;
}

int D(char palavra[], int *pos)
{
  if (lookahead == '0')
  {
    if(match('0', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '1')
  {
    if(match('1', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '2')
  {
    if(match('2', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '3')
  {
    if(match('3', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '4')
  {
    if(match('4', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '5')
  {
    if(match('5', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '6')
  {
    if(match('6', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '7')
  {
    if(match('7', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '8')
  {
    if(match('8', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  else if (lookahead == '9')
  {
    if(match('9', palavra, pos) && D(palavra, pos)) return TRUE;
    return FALSE;
  }
  return TRUE; // D -> e
}

void trataErro(char palavra[], int pos)
{
  fprintf(stderr, "erro na posicao %i\n -> ", pos);
  for (int i = 0; i < pos; i++)
  {
    fprintf(stderr, "%c", palavra[i]);
  }
  fprintf(stderr, "!%c!\n", palavra[pos]);
}

int main(int argc, char const *argv[])
{
  char palavra[] = "1+1**$";
  int pos = 0;

  lookahead = palavra[pos];
  if (E(palavra, &pos)) printf("Sucesso!\n");
  else 
  {
    trataErro(palavra, pos);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}




