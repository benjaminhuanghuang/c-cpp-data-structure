#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

typedef struct Stack
{
  size_t cap;
  size_t len;
  size_t stride;
  char *elements;
} Stack;

void stack_init(Stack *stack, size_t stride)
{
  const size_t INIT_CAP = 1;
  stack->cap = INIT_CAP;
  stack->len = 0;
  stack->stride = stride;
  stack->elements = malloc(INIT_CAP * stride);
}

void stack_free(Stack *stack)
{
  free(stack->elements);
}

void stack_push(Stack *stack, const void *value)
{
  if (stack->len >= stack->cap)
  {
    size_t new_cap = 2 * stack->cap * stack->stride;
    stack->elements = realloc(stack->elements, new_cap);
    stack->cap = new_cap;
  }

  char *offset = stack->elements + stack->len * stack->stride;
  memcpy(offset, value, stack->stride);
  stack->len++;
}

bool stack_pop(Stack *stack, void *dest)
{
  if (stack->len == 0)
    return false;

  char *offset = stack->elements + (stack->len - 1) * stack->stride;
  memcpy(dest, offset, stack->stride);
  stack->len--;
  return true;
}

const char closing[] = {
    ['('] = ')',
    ['['] = ']',
    ['{'] = '}'};

bool is_paired(const char *input)
{
  Stack stack;
  stack_init(&stack, sizeof(char));

  for (const char *ch = input; *ch != '\0'; ch++)
  {
    if (*ch == '(' || *ch == '[' || *ch == '{')
    {
      stack_push(&stack, ch);
    }
    else if (*ch == ')' || *ch == ']' || *ch == '}')
    {
      char last_open;
      bool err = !stack_pop(&stack, &last_open) ||
                 *ch != closing[(int)last_open];
      if (err)
      {
        stack_free(&stack);
        return false;
      }
    }
  }

  stack_free(&stack);
  return stack.len == 0;
}

