#pragma once

#include<stdbool.h>

typedef struct
{
  patient info;
  patient *next;
}SinglePat;
//Pat is short for patient

typedef struct
{
  SinglePat *head;
  SinglePat *tail;
}PatQueue;

bool IsEmpty(PatQueue Q)
{
  if (Q.head == NULL)
  {
      return true;
  }
  else
    return false;
}

PatQueue InitQueue()
{
  PatQueue f;
  f.head = NULL;
  f.tail = NULL;
  return f;
}

Patient HeadQueue(patqueue f)
{
  Patient X;
  X = f.head->info;
  return X;
}

void Push(PatQueue *f,Patient x)
{
  SinglePat *temp;
  temp = malloc(sizeof(SinglePat));
  temp.info = x;
  temp->next = NULL;
  if (f.head == NULL)
  {
    *f.head = temp;
    *f.tail = temp;
  }
  else
  {
    *f.tail->next = temp;
    *f.tail = temp
  }
}

void Pop(patqueue *f,patient *x)
{
  SinglePat *temp;
  *x = f.head -> info;
  temp = f.head;
  if (f.head == f.tail)
  {
    *f.head = NULL;
    *f.tail = NULL;
  }
  else
  {
    f.head = f.head->next;
  }
  free(temp);
}
